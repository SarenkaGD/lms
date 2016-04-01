<?php
$this->DB->BeginTrans();

$this->DB->Execute('CREATE TABLE stck_cashassignments(
		id int not null auto_increment,
		cashid int not null,
		stockid int not null,
		PRIMARY KEY(id),
		INDEX (cashid),
		FOREIGN KEY (cashid)
			REFERENCES cash (id)
			ON UPDATE CASCADE ON DELETE CASCADE
	) ENGINE=InnoDB');

$this->DB->Execute('INSERT INTO stck_cashassignments(cashid, stockid)
	SELECT id, stockid FROM cash where stockid is not null');

$this->DB->Execute('CREATE TABLE stck_invoicecontentsassignments(
	id int not null auto_increment,
	icdocid int not null,
	icitemid smallint(6) not null,
	stockid int not null,
	PRIMARY KEY(id),
	INDEX (icdocid,icitemid),
	FOREIGN KEY (icdocid,icitemid)
		REFERENCES invoicecontents(docid, itemid)
		ON UPDATE CASCADE ON DELETE CASCADE
	) ENGINE=InnoDB');

$this->DB->Execute('INSERT INTO stck_invoicecontentsassignments(icdocid, icitemid, stockid)
        SELECT docid, itemid, stockid FROM invoicecontents where stockid > 0');

$this->DB->Execute('DROP TABLE stck_stockassigments');

$this->DB->Execute('UPDATE stck_dbinfo SET keyvalue = ? WHERE keytype = ?', array('2016040101', 'dbversion'));

$this->DB->CommitTrans();
?>
