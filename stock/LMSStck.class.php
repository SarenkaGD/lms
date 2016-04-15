<?php

class LMSStck {

	var $DB;
	var $AUTH;
	var $CONFIG;
	var $LMS;
	var $_version = 1.1;
	var $dbschversion;

	function LMSStck(&$DB, &$AUTH, &$CONFIG, &$LMS) {
		$this->DB = &$DB;
		$this->AUTH = &$AUTH;
		$this->CONFIG = &$CONFIG;
		$this->LMS = &$LMS;
		$this->dbschversion = $this->UpgradeDB();
	}
	
	/* MODULE SYSTEM FUNCTIONS */
	function SetDefault($table, $id) {
		$this->DB->Execute("ALTER TABLE ".$table." SET def = 0 WHERE def = 1");
		$this->DB->Execute("ALTER TABLE ".$table." SET def = 1 WHERE id = ?", array($id));
	}

	function STStats() {
		$stats['rn'] = $this->DB->GetRow("SELECT COUNT(id) as count, SUM(netvalue) as netvalue, SUM(grossvalue) as grossvalue
						FROM `stck_receivenotes`
						WHERE paid IS NULL");
		return $stats;
	}

	private function UpgradeDB($dbver = STCK_DBVERSION, $stckdir = NULL) {
		$lastupgrade = NULL;
		if ($dbversion = $this->DB->GetOne('SELECT keyvalue
			FROM stck_dbinfo
			WHERE keytype = ?', array('dbversion'))) {
			if ($dbver > $dbversion) {
				set_time_limit(0);

				$lastupgrade = $dbversion;

				if (is_null($stckdir))
					$stckdir = STCK_DIR;

				$filename_prefix = ConfigHelper::getConfig('database.database') == LMSDB::POSTGRESQL ? 'postgres' : 'mysql';

				$pendingupgrades = array();
				$upgradelist = getdir($stckdir . DIRECTORY_SEPARATOR . 'upgradedb', '^' . $filename_prefix . '\.[0-9]{10}\.php$');
			
				if (!empty($upgradelist))
					foreach ($upgradelist as $upgrade) {
						$upgradeversion = preg_replace('/^' . $filename_prefix . '\.([0-9]{10})\.php$/', '\1', $upgrade);
						
						if ($upgradeversion > $dbversion && $upgradeversion <= $dbver)
							$pendingupgrades[] = $upgradeversion;
					}

				if (!empty($pendingupgrades)) {
					sort($pendingupgrades);
					foreach ($pendingupgrades as $upgrade) {
						include($stckdir . DIRECTORY_SEPARATOR . 'upgradedb' . DIRECTORY_SEPARATOR . $filename_prefix . '.' . $upgrade . '.php');
						if (empty($this->DB->errors))
							$lastupgrade = $upgrade;
						else
							break;
					}
				}

			}
		} else { //no stck_dbinfo - check if previouse lms-stck tables exists or stck_dbinfo not filled

			$dbinfo = $this->DB->GetOne('SELECT COUNT(*) FROM information_schema.tables WHERE table_schema = ? AND table_name = ?', array(ConfigHelper::getConfig('database.database'), 'stck_dbinfo'));
			// check if any previous tables exists in this database
			$old_stck = $this->DB->GetOne('SELECT COUNT(*) FROM information_schema.tables WHERE table_schema = ? AND table_name = ?', array(ConfigHelper::getConfig('database.database'), 'stck_stock'));
			if (!$dbinfo && $old_stck) {
				include(STCK_DIR . DIRECTORY_SEPARATOR . 'upgradedb' . DIRECTORY_SEPARATOR . 'mysql-init.php');
				$this->UpgradeDB();
			} elseif (!$dbinfo && !$old_stck) {
				$schema = 'LMSST.mysql';
				if (!$sql = file_get_contents(STCK_DIR . DIRECTORY_SEPARATOR . 'upgradedb' . DIRECTORY_SEPARATOR . $schema))
					die ('Could not open database schema file ' . STCK_DIR . DIRECTORY_SEPARATOR . 'db' . DIRECTORY_SEPARATOR . $schema);
			
				if (!$this->DB->MultiExecute($sql))    // execute
					die ('Could not load database schema!');

			}

		}
		return STCK_DBVERSION;
	}
	
	/* WAREHOUSE */
	function WarehouseGetDefaultId() {
		return $this->DB->GetOne('SELECT id FROM stck_warehouses WHERE def = 1');
	}


	function WarehouseAdd($warehouse) {
		if ($this->DB->Execute("INSERT INTO stck_warehouses(name, comment, creationdate, creatorid) VALUES(?, ?, ?NOW?, ?)", array(
			$warehouse['name'],
			$warehouse['comment'],
			$this->AUTH->id,
			))) {
			$id = $this->DB->GetLastInsertID('stck_warehouses');
			if ($warehouse['default']) $this->SetDefault('stck_warehouses', $id);
			return $id;
		}
	}

	function WarehouseGetList($order='name,asc') {

		list($order,$direction) = sscanf($order, '%[^,],%s');

		($direction=='desc') ? $direction = 'desc' : $direction = 'asc';

		switch($order) {
			case 'id':
				$sqlord = ' ORDER BY id';
				break;
			case 'name':
				$sqlord = ' ORDER BY name';
				break;
			default:
				$sqlord = ' ORDER BY name';
				break;
		}

		/*if ($wgl = $this->DB->GetAll('SELECT w.id, w.name, w.comment, w.def,
			COALESCE(SUM(s.pricebuynet), 0) as valuenet,  COALESCE(SUM(s.pricebuygross), 0) as valuegross, COUNT(s.id) as count
			FROM stck_warehouses w
			LEFT JOIN stck_stock s ON s.warehouseid = w.id AND s.pricesell IS NULL AND s.leavedate = 0
			WHERE w.deleted = 0 
			GROUP BY (w.id)'*/
		if ($wgl = $this->DB->GetAll('SELECT w.id, w.name, w.comment, w.def,
			COALESCE(SUM(s.pricebuynet), 0) as valuenet,  COALESCE(SUM(s.pricebuygross), 0) as valuegross, COUNT(s.id) as count
			FROM stck_warehouses w
			LEFT JOIN stck_stock s ON s.warehouseid = w.id AND s.sold = 0
			WHERE w.deleted = 0
			GROUP BY (w.id)'
			.($sqlord != '' ? $sqlord.' '.$direction : ''))) {
			$wgl['total'] = sizeof($wgl);
			$wgl['order'] = $order;
			$wgl['direction'] = $direction;
			return $wgl;
		}
	}

	function WarehouseExists($id) {
		switch($this->DB->GetOne('SELECT deleted FROM stck_warehouses WHERE id=?', array($id))) {
			case '0':
				return TRUE;
				break;
			case '1':
				return -1;
				break;
			case '':
			default:
				return FALSE;
				break;
		}
	}

	function WarehouseStockCount($id) {
		return $this->DB->GetOne("SELECT COUNT(id) FROM stck_stock s WHERE s.warehouseid = ? AND s.deleted = 0", array($id));
	}

/*	function WarehouseStockValue($id) {
		return $this->DB->GetOne("SELECT SUM(s.pricebuy) FROM stck_stock s WHERE s.warehouseid = ? AND s.active = 1", array($id));
	}
*/
	function WarehouseDel($id) {
		$this->DB->Execute("UPDATE stck_warehouses SET deleted = 1, moddate = ?NOW?, modid = ? WHERE id = ?", array($this->AUTH->id, $id));
	}

	function WarehouseGetInfoById($id) {
		/*if ($wi = $this->DB->GetRow("SELECT w.*, u.name as createdby,
			COALESCE(SUM(s.pricebuynet), 0) as valuenet,  COALESCE(SUM(s.pricebuygross), 0) as valuegross, COUNT(s.id) as count
			FROM stck_warehouses w
			LEFT JOIN users u ON w.creatorid = u.id
			LEFT JOIN stck_stock s ON s.warehouseid = w.id
			WHERE w.id = ? AND u.id = w.creatorid AND s.pricesell IS NULL", array($id))) {
			//$wi['count'] = $this->WarehouseStockCount($id);
			//$wi['value'] = $this->WarehouseStockValue($id);*/
		if ($wi = $this->DB->GetRow("SELECT w.*, u.name as createdby,
			COALESCE(SUM(s.pricebuynet), 0) as valuenet,  COALESCE(SUM(s.pricebuygross), 0) as valuegross, COUNT(s.id) as count
			FROM stck_warehouses w
			LEFT JOIN users u ON w.creatorid = u.id
			LEFT JOIN stck_stock s ON s.warehouseid = w.id
			WHERE w.id = ? AND u.id = w.creatorid AND s.sold = 0", array($id))) {
			$wi['modifiedby'] = $this->LMS->GetUserName($wi['modid']);
			return $wi;
		}
	}

	function WarehouseEdit($we) {
		$this->DB->Execute("UPDATE stck_warehouses SET name = ?, comment = ?, def = ?, moddate = ?NOW?, modid = ?, commerce = ?, deleted = 0 WHERE id = ?", array (
			$we['name'],
			$we['comment'],
			$we['default'],
			$this->AUTH->id,
			$we['commerce'],
			$we['id']));
		if ($we['default'])
			$this->DB->Execute("UPDATE stck_warehouses SET def = 0 WHERE id != ?", array($we['id']));
		return $we['id'];
	}

	function WarehouseGetNameById($id) {
		return $this->DB->GetOne("SELECT name FROM stck_warehouses WHERE id = ?", array($id));
	}

	/* MANUFACTURER */

	function ManufacturerAdd($manufacturer) {
		if ($this->DB->Execute("INSERT INTO stck_manufacturers(name, comment, creationdate, creatorid) VALUES(UPPER(?), ?, ?NOW?, ?)", array(
			$manufacturer['name'],
			$manufacturer['comment'],
			$this->AUTH->id,
			))) {
			return $this->DB->GetLastInsertID('stck_manufacturers');
		}
	}

	function ManufacturerGetList($order='name,asc', $start = NULL) {
		
		list($order,$direction) = sscanf($order, '%[^,],%s');

		($direction=='desc') ? $direction = 'desc' : $direction = 'asc';

		switch($order) {
			case 'id':
				$sqlord = ' ORDER BY id';
				break;
			case 'name':
				$sqlord = ' ORDER BY name';
				break;
			default:
				$sqlord = ' ORDER BY name';
				break;
			}

		if ($mgl = $this->DB->GetAll('SELECT m.id, m.name, m.comment
			FROM stck_manufacturers m WHERE m.deleted = 0'
			.($start ? ' AND UPPER(m.name) LIKE \''.$start.'%\' ' : '')
			.($sqlord != '' ? $sqlord.' '.$direction : ''))) {
			
			$mgl['total'] = sizeof($mgl);
			$mgl['order'] = $order;
			$mgl['direction'] = $direction;
			return $mgl;
		}
	}

	function ManufacturerGetInfoById($id) {
		if ($mi = $this->DB->GetRow("SELECT m.*, u.name as createdby,
			COALESCE(SUM(s.pricebuynet), 0) as valuenet,  COALESCE(SUM(s.pricebuygross), 0) as valuegross, COUNT(s.id) as count
			FROM stck_manufacturers m
			LEFT JOIN users u ON u.id = m.creatorid
			LEFT JOIN stck_products p ON p.manufacturerid = m.id
			LEFT JOIN stck_stock s ON s.productid = p.id
			WHERE m.id = ? AND u.id = m.creatorid AND s.sold = 0", array($id))) {
			
/*			$mi['count'] = $this->ManufacturerStockCount($id);
			$mi['value'] = $this->ManufacturerStockValue($id);
*/			$mi['modifiedby'] = $this->LMS->GetUserName($mi['modid']);
			return $mi;
		}
	}

	function ManufacturerStockCount($id) {
		return $this->DB->GetOne("SELECT COUNT(s.id)
			FROM stck_stock s, stck_products p
			WHERE p.manufacturerid = ? AND s.deleted = 0 AND p.id = s.productid", array($id));
	}
	
	function ManufacturerStockValue($id) {
		return $this->DB->GetOne("SELECT SUM(s.pricebuynet)
			FROM stck_stock s, stck_products p
			WHERE p.manufacturerid = ? AND s.deleted = 0 AND p.id = s.productid", array($id));
	}

	function ManufacturerExists($id) {
		switch($this->DB->GetOne('SELECT deleted FROM stck_manufacturers WHERE id=?', array($id))) {
			case '0':
				return TRUE;
				break;
			case '1':
				return -1;
				break;
			case '':
			default:
				return FALSE;
				break;
		}
	}

	function ManufacturerDel($id) {
		$this->DB->Execute("UPDATE stck_manufacturers SET deleted = 1, moddate = ?NOW?, modid = ? WHERE id = ?", array($this->AUTH->id, $id));
	}

	function ManufacturerEdit($me) {
		$this->DB->Execute("UPDATE stck_manufacturers SET name = UPPER(?), comment = ?, moddate = ?NOW?, modid = ? WHERE id = ?", array (
			$me['name'],
			$me['comment'],
			$this->AUTH->id,
			$me['id']));
		return $me['id'];
	}

	/* GROUPS */

	function GroupAdd($group) {
		if ($this->DB->Execute("INSERT INTO stck_groups(quantityid, quantitycheck, name, comment, creationdate, creatorid) VALUES(?, IFNULL(?, 0), ?, ?, ?NOW?, ?)", array(
			$group['quantityid'],
			$group['quantitycheck'],
			$group['name'],
			$group['comment'],
			$this->AUTH->id,
			))) {
			return $this->DB->GetLastInsertID('stck_groups');
		}
	}

	function GroupGetInfoById($id) {
		if ($gi = $this->DB->GetRow("SELECT g.*, u.name as createdby, q.name as quantityname,
			COALESCE(SUM(s.pricebuynet), 0) as valuenet,  COALESCE(SUM(s.pricebuygross), 0) as valuegross, COUNT(s.id) as count
			FROM stck_groups g
			LEFT JOIN users u ON u.id = g.creatorid
			LEFT JOIN stck_quantities q ON q.id = g.quantityid
			LEFT JOIN stck_stock s ON s.groupid = g.id
			WHERE g.id = ? AND s.sold = 0", array($id))) {
//			$gi['count'] = $this->GroupStockCount($id);
//			$gi['value'] = $this->GroupStockValue($id);
			$gi['modifiedby'] = $this->LMS->GetUserName($gi['modid']);
			return $gi;
		}
	}

	function GroupDel($id) {
		$this->DB->Execute("UPDATE stck_groups SET deleted = 1, moddate = ?NOW?, modid = ? WHERE id = ?", array($this->AUTH->id, $id));
	}


	function GroupStockCount($id) {
		return $this->DB->GetOne("SELECT COUNT(s.id)
			FROM stck_stock s, stck_products p
			WHERE p.groupid = ? AND s.deleted = 0 AND p.id = s.productid", array($id));
	}

/*	function GroupStockValue($id) {
		return $this->DB->GetOne("SELECT SUM(s.pricebuy)
			FROM stck_stock s, stck_products p
			WHERE p.groupid = ? AND s.active = 1 AND p.id = s.productid", array($id));
	}
*/
	function GroupExists($id) {
		switch($this->DB->GetOne('SELECT deleted FROM stck_manufacturers WHERE id=?', array($id))) {
			case '0':
				return TRUE;
				break;
			case '1':
				return -1;
				break;
			case '':
			default:
				return FALSE;
				break;
		}
	}

	function GroupGetList($order='name,asc', $start = NULL) {
		list($order,$direction) = sscanf($order, '%[^,],%s');

		($direction=='desc') ? $direction = 'desc' : $direction = 'asc';
		
		switch($order) {
			case 'id':
				$sqlord = ' ORDER BY g.id';
				break;
			case 'name':
				$sqlord = ' ORDER BY g.name';
				break;
			default:
				$sqlord = ' ORDER BY g.name';
				break;
		}
		
		if ($ggl = $this->DB->GetAll('SELECT g.id as gid, g.name as gname, g.comment as gcomment, g.*,
			COALESCE(SUM(s.pricebuynet), 0) as valuenet,  COALESCE(SUM(s.pricebuygross), 0) as valuegross, COUNT(s.id) as count
			FROM stck_groups g
			LEFT JOIN stck_stock s ON s.groupid = g.id
			WHERE s.sold = 0'
			.($start ? ' AND UPPER(g.name) LIKE \''.$start.'%\' ' : '')
			.' GROUP BY (g.id)'
			.($sqlord != '' ? $sqlord.' '.$direction : ''))) {
				$ggl['total'] = sizeof($ggl);
				$ggl['order'] = $order;
				$ggl['direction'] = $direction;
				return $ggl;
		}
	}

	function GroupEdit($ge) {
		$this->DB->Execute("UPDATE stck_groups SET name = ?, quantityid = ?, quantitycheck = ?, comment = ?,
			moddate = ?NOW?, modid = ?, deleted = 0 WHERE id = ?", array (
			$ge['name'],
			$ge['quantityid'],
			$ge['quantitycheck'],
			$ge['comment'],
			$this->AUTH->id,
			$ge['id']));
		return $ge['id'];
	}

	/* QUANTITY */

	function QuantityGetList($order='name,asc') {
		list($order,$direction) = sscanf($order, '%[^,],%s');

                ($direction=='desc') ? $direction = 'desc' : $direction = 'asc';

                switch($order) {
			case 'id':
				$sqlord = ' ORDER BY id';
				break;
			case 'name':
				$sqlord = ' ORDER BY name';
				break;
			default:
				$sqlord = ' ORDER BY name';
				break;
		}

		if ($qgl = $this->DB->GetAll('SELECT q.id, q.name, q.comment, q.def
			FROM stck_quantities q
			WHERE q.deleted = 0'
			.($sqlord != '' ? $sqlord.' '.$direction : ''))) {
			$qgl['total'] = sizeof($qgl);
			$qgl['order'] = $order;
			$qgl['direction'] = $direction;
			return $qgl;
		}
	}

	function QuantityGetNameById($id) {
		return $this->DB->GetOne("SELECT name FROM stck_quantities WHERE id = ?", array($id));
	}

	/* TYPES */

	function TypeGetList($order='name,asc') {
		list($order,$direction) = sscanf($order, '%[^,],%s');
		
		($direction=='desc') ? $direction = 'desc' : $direction = 'asc';

		switch($order) {
			case 'id':
				$sqlord = ' ORDER BY id';
				break;
			case 'name':
				$sqlord = ' ORDER BY name';
				break;
			default:
				$sqlord = ' ORDER BY name';
				break;
		}
	
		if ($tgl = $this->DB->GetAll('SELECT t.id, t.name
			FROM stck_types t
			WHERE t.deleted = 0'
			.($sqlord != '' ? $sqlord.' '.$direction : ''))) {
			$tgl['total'] = sizeof($tgl);
			$tgl['order'] = $order;
			$tgl['direction'] = $direction;
			return $tgl;
		}
	}


	/* PRODUCTS */

	function ProductAdd($pa) {
		if ($this->DB->Execute("INSERT INTO stck_products(manufacturerid, groupid, taxid, typeid, quantityid, quantitycheck, ean, quantity, name, creationdate, creatorid) VALUES(?, ?, ?, ?, ?, IFNULL(?, 0), ?, ?, ?, ?NOW?,?)", array(
			$pa['manufacturerid'],
			$pa['groupid'],
			$pa['taxid'],
			$pa['typeid'],
			$pa['quantityid'],
			$pa['quantitycheck'],
			$pa['ean'],
			$pa['quantity'],
			$pa['name'],
			$this->AUTH->id))) {
			return $this->DB->GetLastInsertID('stck_products');
		}
	}

	function StockList($order='name,asc', $manufacturer = NULL, $group = NULL, $warehouse = 1, $docid = NULL) {
		list($order,$direction) = sscanf($order, '%[^,],%s');
		$totalpcs = 0;
		$totalvn = 0;
		$totalvg = 0;

               ($direction=='desc') ? $direction = 'desc' : $direction = 'asc';

                switch($order) {
			case 'id':
				$sqlord = ' ORDER BY p.id';
				break;
			case 'name':
				$sqlord = ' ORDER BY pname';
				break;
			case 'manufacturer':
				$sqlord = ' ORDER BY m.name';
				break;
			case 'group':
				$sqlord = ' ORDER BY g.name';
				break;
			case 'quant':
				$sqlord = ' ORDER BY p.quantity';
				break;
			default:
				$sqlord = ' ORDER BY pname';
				break;
		}

		if ($pgl = $this->DB->GetAll('SELECT m.name as mname, m.id as mid, CONCAT(m.name, \' \', p.name) as pname, p.id, p.quantity, g.name as gname, g.id as gid, COALESCE(SUM(s.pricebuynet), 0) as valuenet,  COALESCE(SUM(s.pricebuygross), 0) as valuegross, COUNT(s.id) as count, t.name as type
			FROM stck_products p
			LEFT JOIN stck_manufacturers m ON p.manufacturerid = m.id
			LEFT JOIN stck_groups g ON p.groupid = g.id
			LEFT JOIN stck_stock s ON s.productid = p.id
			LEFT JOIN stck_types t ON p.typeid = t.id
			WHERE p.deleted = 0 AND s.sold = 0'
			.($warehouse ? ' AND s.warehouseid = '.$warehouse : '')
			.($manufacturer ? ' AND m.id = '.$manufacturer : '')
			.($group ? ' AND g.id = '.$group : '')
			.($docid ? ' AND s.enterdocumentid = '.$docid : '').'
			GROUP BY(p.id)'
			.($sqlord != '' ? $sqlord.' '.$direction : ''))) {
			foreach($pgl as $p) {
				$totalpcs += $p['count'];
				$totalvn += $p['valuenet'];
				$totalvg += $p['valuegross'];
			}
			$pgl['total'] = sizeof($pgl);
			$pgl['totalpcs'] = $totalpcs;
			$pgl['totalvn'] = $totalvn;
			$pgl['totalvg'] = $totalvg;
			$pgl['order'] = $order;
			$pgl['direction'] = $direction;
			return $pgl;
		}
	}

	function ProductExists($id) {
		switch($this->DB->GetOne('SELECT deleted FROM stck_products WHERE id=?', array($id))) {
			case '0':
				return TRUE;
				break;
			case '1':
				return -1;
				break;
			case '':
			default:
				return FALSE;
				break;
		}
	}


	function ProductGetInfoById($id) {
		if ($pi = $this->DB->GetRow("SELECT p.*,
			m.name as mname,
			g.name as gname,
			u.name as createdby,
			q.name as qname,
			t.name as tname,
			tx.value as tax, tx.label as txname,
			COALESCE(SUM(s.pricebuynet), 0) as valuenet,  COALESCE(SUM(s.pricebuygross), 0) as valuegross, COUNT(s.id) as count
			FROM stck_products p
			LEFT JOIN stck_manufacturers m ON m.id = p.manufacturerid
			LEFT JOIN stck_groups g ON g.id = p.groupid
			LEFT JOIN stck_types t ON t.id = p.typeid
			LEFT JOIN taxes tx ON tx.id = p.taxid
			LEFT JOIN users u ON u.id = p.creatorid
			LEFT JOIN stck_quantities q ON q.id = p.quantityid
			LEFT JOIN stck_stock s ON s.productid = p.id
			WHERE p.id = ? AND s.sold = 0", array($id))) {
			$pi['modifiedby'] = $this->LMS->GetUserName($pi['modid']);
			return $pi;
		}
	}

	function ProductEdit($pe) {
		$og = $this->DB->GetOne('SELECT groupid FROM stck_products WHERE id = ?', array($pe['id']));
		if ($og != $pe['groupid'])
			$this->DB->BeginTrans();
		$this->DB->Execute("UPDATE stck_products SET name = ?, quantity = ?, ean = ?, typeid = ?,
		groupid = ?, manufacturerid = ?, taxid = ?, quantityid = ?, quantitycheck = ?, comment = ?,
		moddate = ?NOW?, modid = ?, deleted = 0 WHERE id = ?", array (
		$pe['name'],
		$pe['quantity'],
		$pe['ean'],
		$pe['typeid'],
		$pe['groupid'],
		$pe['manufacturerid'],
		$pe['taxid'],
		$pe['quantityid'],
		$pe['quantitycheck'],
		$pe['comment'],
		$this->AUTH->id,
		$pe['id']));
		if ($og != $pe['groupid']) {
			$this->DB->Execute('UPDATE stck_stock SET s.groupid = ? WHERE s.productid = ?', array($pe['groupid']));
			$this->DB->CommitTrans();
		}
		return $pe['id'];
	}

	function ProductGetList($order='name,asc', $manufacturerid = NULL, $groupid = NULL, $warehouseid = NULL) {
	  	
		list($order,$direction) = sscanf($order, '%[^,],%s');
		$totalpcs = 0;

		($direction=='desc') ? $direction = 'desc' : $direction = 'asc';
		
		switch($order) {
		case 'name':
			$sqlord = ' ORDER BY pname';
			break;
		case 'manufacturer':
			$sqlord = ' ORDER BY m.name';
			break;
		case 'group':
			$sqlord = ' ORDER BY g.name';
			break;
		case 'quant':
			$sqlord = ' ORDER BY scount';
			break;
		case 'id':
			$sqlord = ' ORDER BY p.id';
			break;
		default:
			$sqlord = ' ORDER BY pname';
		break;
		}

		$pgl = $this->DB->GetAll("SELECT p.*,
			m.id as mid, m.name as mname, CONCAT(m.name, ' ', p.name) as pname,
			g.id as gid, g.name as gname,"
			.($warehouseid ? ' vsc.scount' : 'SUM(vsc.scount) as scount')
			." FROM stck_products p
			LEFT JOIN stck_manufacturers m ON m.id = p.manufacturerid
			LEFT JOIN stck_groups g ON g.id = p.groupid
			LEFT JOIN stck_vstockcount vsc ON vsc.productid = p.id
			WHERE 1"
			.($manufacturerid ? ' AND m.id = '.$manufacturerid : '')
			.($groupid ? ' AND p.groupid = '.$groupid : '')
			.($warehouseid ? ' AND vsc.warehouseid = '.$warehouseid : ' GROUP BY p.id')
			.($sqlord != '' ? $sqlord.' '.$direction : ''), array());
		$pgl['total'] = sizeof($pgl);
		$pgl['order'] = $order;
		$pgl['direction'] = $direction;
		return $pgl;

	}

	/* STOCK */

	function StockSell($number, $id, $price, $date) {
		if ($this->DB->Execute("UPDATE stck_stock SET quitdocumentid = ?, pricesell = ?, leavedate = ?, sold = 1, moddate = ?NOW?, modid = ? WHERE id = ?", array($number, (string)$price, $date, $this->AUTH->id, $id)))
			return true;
		else
			return false;
	}

	function StockUnSell($id) {
		$this->DB->Execute("UPDATE stck_stock SET pricesell = NULL, leavedate = 0, sold = 0, moddate = ?NOW?, modid = ? WHERE id = ?", array($this->AUTH->id, $id));
	}

	function StockAdd($product, $doc = NULL, $bdate) {
		if ($this->DB->Execute("INSERT INTO stck_stock(warehouseid, productid, supplierid, enterdocumentid, creationdate, bdate, creatorid, serialnumber, pricebuynet, taxid, pricebuygross, groupid, warranty) VALUES(?, ?, ?, ?, ?NOW?, ?, ?, ?, ?, ?, ?, ?, ?)", array(
			$product['warehouse'],
			$product['pid'],
			isset($doc['supplierid']) ? $doc['supplierid'] : $product['supplierid'],
			isset($doc['dbnumber']) ? $doc['dbnumber'] : $product['docnumber'],
			$bdate,
			$this->AUTH->id,
			$product['serial'],
			(string) str_replace(',','.', $product['price']['net']),
			$product['price']['taxid'],
			(string) str_replace(',','.', $product['price']['gross']),
			$product['group'],
			$product['warranty']
			)))
			return $this->DB->GetLastInsertID();
		else
			return FALSE;
	}

	function StockPositionGetById($id) {
		if ($sgpbi = $this->DB->GetRow('SELECT s.*,
			CONCAT(m.name, \' \', p.name) as pname,
			t.label as txname
			FROM stck_stock s
			LEFT JOIN stck_products p ON p.id = s.productid
			LEFT JOIN stck_manufacturers m ON m.id = p.manufacturerid
			LEFT JOIN taxes t ON (s.taxid = t.id)
			WHERE s.id = ?', array($id))) {
			return $sgpbi;
		}
		return false;
	}

	function StockPositionEdit($position) {
		$position['pricebuynet'] = str_replace(',','.', $position['pricebuynet']);
		$position['pricebuygross'] = str_replace(',','.', $position['pricebuygross']);

		if ($this->DB->Execute('UPDATE stck_stock SET warehouseid = ?, serialnumber = ?, pricebuynet = ?,
		taxid = ?, pricebuygross = ?, modid = ?, sold = ?, moddate = ?NOW?, comment = ? WHERE id = ?', array(
			$position['warehouseid'],
			strtoupper($position['serialnumber']),
			(string) $position['pricebuynet'],
			$position['taxid'],
			(string) $position['pricebuygross'],
			$this->AUTH->id,
			$position['sold'],
			$position['comment'],
			$position['id']
			))) {
			$cid = $this->DB->GetOne('SELECT cashid FROM stck_cashassignments WHERE stockid = ? AND rnitem = ?', array($position['id'], 1));
			echo "CID: ".$cid;
			$this->DB->Execute('UPDATE cash set value = ?, taxid = ? WHERE id = ?', array((string) $position['pricebuygross'], $position['taxid'], $cid));
			print_r($this->DB);
			$docid = $this->DB->GetOne('SELECT enterdocumentid FROM stck_stock WHERE id = ?', array($position['id']));
			$this->ReceiveNoteUpdateValue($docid);
			if ($position['sold']) {
				$position['pricesell'] = str_replace(',','.', $position['pricesell']);
				$this->StockSell(NULL, $position['id'], $position['pricesell'], $position['leavedate']);
			}
			return true;
		}
		return false;
	}

	function StockPositionChangeSupplier($id, $supplierid) {
		if ($this->DB->Execute('UPDATE stck_stock SET supplierid = ?,  modid = ?, moddate = ?NOW? WHERE id = ?', array($supplierid, $this->AUTH->id, $id))) {
			$cid = $this->DB->GetOne('SELECT cashid FROM stck_cashassignments WHERE stockid = ? AND rnitem = ?', array($id, 1));
			$this->DB->Execute('UPDATE cash SET customerid = ? WHERE id = ?', array($supplierid, $cid));
			return true;
		}
		return false;
	}

	function StockExists($id) {
		switch($this->DB->GetOne('SELECT deleted FROM stck_stock WHERE id=?', array($id))) {
			case '0':
				return TRUE;
				break;
			case '1':
				return -1;
				break;
			case '':
			default:
				return FALSE;
			break;
		}
	}

	function StockProductList($order, $prodid = NULL, $ssp, $docid = NULL, $warehouseid = NULL, $manufacturerid = NULL, $groupid = NULL, $sn = NULL) {
		list($order,$direction) = sscanf($order, '%[^,],%s');
		$totalpcs = 0;
		$totalvn = 0;
		$totalvg = 0;

		($direction=='desc') ? $direction = 'desc' : $direction = 'asc';

		switch($order) {
			case 'id':
				$sqlord = ' ORDER BY p.id';
				break;
			case 'name':
				$sqlord = ' ORDER BY pname';
				break;
			case 'warehouse':
				$sqlord = ' ORDER BY wname';
				break;
			case 'supplier':
				$sqlord = ' ORDER BY sname';
				break;
			case 'creationdate':
				$sqlord = ' ORDER BY s.creationdate';
				break;
			default:
				$sqlord = ' ORDER BY pname';
			break;
		}

		if ($sn)
			$sn = $this->DB->Escape("%$sn%");

		if ($spl = $this->DB->GetAll('SELECT s.*,
			s.pricebuynet as valuenet, s.pricebuygross as valuegross,
			w.name as wname, w.id as wid,
			g.name as gname,
			CONCAT(m.name, \' \', p.name) as pname,
			CONCAT(c.lastname, \' \', c.name) as sname, c.id as cid,
			rn.number as rnnumber
			FROM stck_stock s
			LEFT JOIN stck_warehouses w ON w.id = s.warehouseid
			LEFT JOIN stck_groups g ON g.id = s.groupid
			LEFT JOIN customers c ON s.supplierid = c.id
			LEFT JOIN stck_products p ON p.id = s.productid
			LEFT JOIN stck_manufacturers m ON m.id = p.manufacturerid
			LEFT JOIN taxes tx ON tx.id = p.taxid
			LEFT JOIN stck_receivenotes rn ON s.enterdocumentid = rn.id
			WHERE 1'
			.($prodid ? ' AND s.productid = '.$prodid : '')
			.($docid ? ' AND s.enterdocumentid = '.$docid : '')
			.($ssp ? '' : ' AND s.sold = 0')
			.($warehouseid ? ' AND s.warehouseid = '.$warehouseid : '')
			.($manufacturerid ? ' AND m.id = '.$manufacturerid : '')
			.($groupid ? ' AND p.groupid = '.$groupid : '')
			.($sn ? ' AND LOWER(serialnumber) ?LIKE? LOWER('.$sn.')' : '')
			.($sqlord != '' ? $sqlord.' '.$direction : ''))) {
			foreach($spl as $p) {
				$totalpcs += $p['count'];
				$totalvn += $p['valuenet'];
				$totalvg += $p['valuegross'];
			}
			$spl['total'] = sizeof($spl);
			$spl['order'] = $order;
			$spl['direction'] = $direction;
			$spl['totalpcs'] = $totalpcs;
			$spl['totalvn'] = $totalvn;
			$spl['totalvg'] = $totalvg;
			return $spl;
		}
	}

	/* RECEIVE NOTES */

	function ReceiveNoteDocumentAdd($doc) {
		if ($this->DB->Execute("INSERT INTO stck_receivenotes(supplierid, number, creatorid, creationdate, netvalue, grossvalue, paytype, datesettlement, datesale, deadline, comment) VALUES(?, ?, ?, ?NOW?, ?, ?, ?, ?, ?, ?, ?)", array(
			$doc['supplierid'],
			$doc['number'],
			$this->AUTH->id,
			(string) str_replace(',','.', $doc['net']),
			(string) str_replace(',','.',$doc['gross']),
			$doc['paytype'],
			$doc['date']['settlement'],
			$doc['date']['sale'],
			$doc['date']['deadline'],
			$doc['comment']
			)))
			return $this->DB->GetLastInsertID();
		else
			return false;
	}

	function ReceiveNoteAdd($receivenote) {
		$error = NULL;
		if ($receivenote['doc']['dbnumber'] = $this->ReceiveNoteDocumentAdd($receivenote['doc'])) {
			foreach($receivenote['product'] as $product) {
				$product['group'] = $this->DB->GetOne('SELECT groupid FROM stck_products WHERE id = ?', array($product['pid']));
				$sid = $this->StockAdd($product, $receivenote['doc'], $receivenote['doc']['date']['sale']);
				$this->LMS->AddBalance(array(
					'value' => $product['price']['gross'],
					'taxid' => $product['price']['taxid'],
					'customerid' => $receivenote['doc']['supplierid'],
					'comment' => $product['product'].' (S/N: '.$product['serial'].')',
					));
				$bid = $this->DB->GetLastInsertID();
				$this->BalanceAddStockID($sid, $bid, 1);
			}
			if ($receivenote['doc']['paytype'] == 1) {
				$this->ReceiveNoteAccount($receivenote['doc']['dbnumber']);
			}
			return true;	
		}
	}

	function ReceiveNotePositionAdd($rnel, $transaction = NULL) {
		$error = NULL;

		if (!$transaction)
			$this->DB->BeginTrans();

		foreach($rnel['product'] as $product) {
			echo("Dodaje produkt");
			$product['group'] = $this->DB->GetOne('SELECT groupid FROM stck_products WHERE id = ?', array($product['pid']));
			if ($rnel['doc']['number'] && !$product['docnumber'])
				$product['docnumber'] = $rnel['doc']['number'];
			if (!$rnel['doc']['bdate'])
				$rnel['doc']['bdate'] = $this->DB->GetOne('SELECT datesale FROM stck_receivenotes WHERE id = ?', array($product['docnumber']));
			$sid = $this->StockAdd($product, $rnel['doc'], $rnel['doc']['bdate']);
			$this->ReceiveNoteUpdateValue($rnel['doc']['number']);
			$this->LMS->AddBalance(array(
				'value' => $product['price']['gross'],
				'customerid' => $rnel['doc']['supplierid'],
				'comment' => $product['product'],
			));
			$bid = $this->DB->GetLastInsertID();
			$this->BalanceAddStockID($sid, $bid, 1);
		}
		
		if (!$transaction)
			$this->DB->CommitTrans();
		return true;
	}

	function ReceiveNoteList($order='name,asc', $pagelimit = 100, $page, $sprn = 0, $supplierid = NULL, $docnumber = NULL) {
		list($order,$direction) = sscanf($order, '%[^,],%s');

		($direction=='desc') ? $direction = 'desc' : $direction = 'asc';

		switch($order) {
			case 'id':
				$sqlord = ' ORDER BY rn.id';
				break;
			case 'sname':
				$sqlord = ' ORDER BY sname';
				break;
			case 'cd':
				$sqlord = ' ORDER BY rn.creationdate';
				break;
			case 'nv':
				$sqlord = ' ORDER BY rn.netvalue';
				break;
			case 'gv':
				$sqlord = ' ORDER BY rn.grossvalue';
				break;
			case 'dl':
				$sqlord = ' ORDER BY rn.deadline';
				break;
			case 'sldate':
				$sqlord = ' ORDER BY rn.datesale';
				break;
			case 'stdate':
			default:
				$sqlord = ' ORDER BY rn.datesettlement';
				break;
		}

		if ($docnumber)
			$docnumber = $this->DB->Escape("%$docnumber%");
		
		if ($rnl = $this->DB->GetAll('SELECT rn.*,
			CONCAT(c.lastname, \' \', c.name) as sname, c.id as sid
			FROM stck_receivenotes rn
			LEFT JOIN customers c ON c.id = rn.supplierid
			WHERE 1'
			.($supplierid ? ' AND rn.supplierid = '.$supplierid : '')
			.($docnumber ? ' AND rn.number LIKE '.$docnumber : '')
			.($sprn ? '' : ' AND rn.paid IS NULL')
			.($sqlord != '' ? $sqlord.' '.$direction : ''))) {
			
			$rnl['total'] = sizeof($rnl);
			$rnl['order'] = $order;
			$rnl['direction'] = $direction;
			$rnl['totalvu'] = $this->DB->GetOne('SELECT SUM(grossvalue) as gross
				FROM stck_receivenotes
				WHERE paid IS NULL');
			return $rnl;
		}
		return false;
	}

	function ReceiveNoteExists($id) {
		switch($this->DB->GetOne('SELECT deleted FROM stck_receivenotes WHERE id=?', array($id))) {
			case '0':
				return TRUE;
				break;
			case '1':
				return -1;
				break;
			case '':
			default:
				return FALSE;
				break;
		}
	}

	function ReceiveNoteGetInfoById($id) {
		if ($rngibi = $this->DB->GetRow('SELECT rn.*,
		CONCAT(c.lastname, \' \', c.name) as sname,
		u1.name as createdby,
		u2.name as modifiedby
		FROM stck_receivenotes rn
		LEFT JOIN customers c ON c.id = rn.supplierid
		LEFT JOIN users u1 ON u1.id = rn.creatorid
		LEFT JOIN users u2 ON u2.id = rn.modid
		WHERE rn.id = ?', array($id))) {
			return $rngibi;
		}
		return false;
	}

	function ReceiveNoteUpdateValue($id) {
		$rns = $this->DB->GetRow('SELECT SUM(pricebuygross) as sumgross, SUM(pricebuynet) as sumnet 
			FROM stck_stock 
			WHERE enterdocumentid = ?', array($id));
		if ($this->DB->Execute('UPDATE stck_receivenotes SET netvalue = ?, grossvalue = ? WHERE id = ?', array($rns['sumnet'], $rns['sumgross'], $id)))
			return true;
		return false;
	}

	function ReceiveNoteEdit($rn, $productlist, $rnepl = NULL) {
		if ($this->DB->Execute('UPDATE stck_receivenotes SET number = ?, datesettlement = ?, datesale = ?, deadline = ?, paytype = ?, comment = ?, moddate = ?NOW?, modid = ? WHERE id = ?', array(
			$rn['number'],
			$rn['datesettlement'],
			$rn['datesale'],
			$rn['deadline'],
			$rn['paytype'],
			$rn['comment'],
			$this->AUTH->id,
			$rn['id']))) {
			if ($rn['osid'] != $rn['supplierid']) {
				$this->DB->BeginTrans();
				foreach ($productlist as $product) {
					if (!$this->StockPositionChangeSupplier($product['id'], $rn['supplierid'])) {
						return false;
					}
				}
				
				if ($rnepl) {
					$rnepl['doc']['supplierid'] = $rn['supplierid'];
					$rnepl['doc']['number'] = $rn['id'];

					if (!$this->ReceiveNotePositionAdd($rnepl, 1))
						return false;

				}
				print_r($this->DB);
				if ($this->DB->GetOne('SELECT paid FROM stck_receivenotes WHERE id = ?', array($rn['id']))) {
					$cid = $this->DB->GetOne('SELECT cashid FROM stck_receivennotesassignment WHERE rnid = ?', array($rn['id']));
					$this->DB->Execute('UPDATE cash SET customerid = ? WHERE id = ?', array($rn['supplierid'], $cid));
				}
				$this->DB->Execute('UPDATE stck_receivenotes SET supplierid = ? WHERE id = ?', array($rn['supplierid'], $rn['id']));
				print_r($this->DB);
				$this->DB->CommitTrans();
				return $rn['id'];
			}
			return $rn['id'];
		}
		return false;
	}

	function ReceiveNoteAccount($id) {
		$this->DB->BeginTrans();
		$rn = $this->DB->GetRow('SELECT id, grossvalue, supplierid, number, paytype, paid FROM stck_receivenotes WHERE id = ?', array($id));
		if (!$rn['paid']) {
			$this->LMS->AddBalance(array(
				'value' => $rn['grossvalue']*-1,
				'customerid' => $rn['supplierid'],
				'type' => 1,
				'comment' => $rn['number']." - ".$PAYTYPES[$rn['paytype']]
			));
			$cid = $this->DB->GetLastInsertID('cash');
			$this->DB->Execute('INSERT INTO stck_receivennotesassignment (rnid, cashid) VALUE(?, ?)', array($id, $cid));
			$this->DB->Execute('UPDATE stck_receivenotes SET paid = 1 WHERE id = ?', array($id));
			$this->DB->CommitTrans();
		}
	}

	/* BALANCE */

	function BalanceAddStockID($stock, $balance, $rnitem = NULL) {
		if ($this->DB->Execute('INSERT INTO stck_cashassignments(cashid, stockid, rnitem) VALUES(?, ?, ?)', array($balance, $stock, $rnitem))) {
			return true;
		}
		return false;
	}
}

function DateChange($date) {
	 $t_date = preg_split('/\s+/', $date);
	 
	 if(isset($date[1]))
	 	$time = explode(':',$t_date[1]);
	else
		$time[0] = $time[1] = 0;
	
	$t_date = explode('/',$t_date[0]);

	if(checkdate($t_date[1],$t_date[2],(int)$t_date[0])) { //if date is wrong, set today's date{
		$date = mktime((int)$time[0],(int)$time[1],0,$t_date[1],$t_date[2],$t_date[0]);
	} else 
		$date = time();

	return $date;
}

include('locale/'.$_ui_language.'/strings.php');
?>
