<?php

/*
 * LMS version 1.11-git
 *
 *  (C) Copyright 2001-2016 LMS Developers
 *
 *  Please, see the doc/AUTHORS for more information about authors!
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License Version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
 *  USA.
 *
 *  $Id$
 */

$id = intval($_GET['id']);

if($id && $_GET['is_sure'] == '1') {
<<<<<<< HEAD
    if(isset($_GET['recover'])) {
	if (ConfigHelper::getConfig('phpui.stock')) {
		$stck_ica = $DB->GetAll('SELECT icitemid, stockid FROM stck_invoicecontentsassignments WHERE icdocid = ?', array($id));
		$sold = 0;
		if ($stck_ica) {
			foreach ($stck_ica as $pos) {
				$sold = $sold || $LMSST->StockSoldById($pos['stockid']);
			}
		}
	
		if ($sold) {
			$body = '<P>'.trans('Unable to recover invoice - stock already sold!').'</P>';
			$SMARTY->assign('body',$body);
			$SMARTY->display('dialog.html');
			exit;
		}
	}
	$DB->Execute('UPDATE documents SET cancelled = 0 WHERE id = ?', array($id));
	$document = $DB->GetRow('SELECT customerid, cdate FROM documents WHERE id = ?', array($id));
	if (ConfigHelper::getConfig('phpui.stock'))//Added if for lms-stck
		$invoices = $DB->GetAll('SELECT ic.*, sica.stockid
			FROM invoicecontents ic
			LEFT JOIN stck_invoicecontentsassignments sica ON (ic.docid = sica.icdocid AND ic.itemid = sica.icitemid)
			WHERE ic.docid = ?', array($id));
	else
		$invoices = $DB->GetAll('SELECT * FROM invoicecontents WHERE docid = ?', array($id));
	$itemid = 1;
	foreach ($invoices as $invoice) {
	    $LMS->AddBalance(array(
		'time' => $document['cdate'],
		'value' => $invoice['value'] * $invoice['count'] * -1,
		'taxid' => $invoice['taxid'],
		'customerid' => $document['customerid'],
		'comment' => $invoice['description'],
		'docid' => $id,
		'itemid' => $invoice['itemid']//$itemid -> $invoice['itemid'] - just tobe on the safe side
	    ));
	    if (ConfigHelper::getConfig('phpui.stock')) {
	    	$icid = $DB->GetLastInsertID('cash');
		$DB->Execute('INSERT INTO stck_cashassignments (cashid, stockid) VALUES(?, ?)', array($icid, $invoice['stockid']));
	    	$LMSST->StockSell($id, $invoice['stockid'], ($invoice['value'] * $invoice['count']), time());
	    }
	    $itemid += 1;
	}
	if ($SYSLOG) {
		$args = array(
		    $SYSLOG_RESOURCE_KEYS[SYSLOG_RES_DOC] => $document['id'],
		    $SYSLOG_RESOURCE_KEYS[SYSLOG_RES_CUST] => $document['customerid'],
		    $SYSLOG_RESOURCE_KEYS[SYSLOG_RES_USER] => $AUTH->id
		);
		$SYSLOG->AddMessage(SYSLOG_RES_DOC, SYSLOG_OPER_UPDATE, $args, 
			array($SYSLOG_RESOURCE_KEYS[SYSLOG_RES_CUST] , $SYSLOG_RESOURCE_KEYS[SYSLOG_RES_DOC], $SYSLOG_RESOURCE_KEYS[SYSLOG_RES_USER])
		);
	}
    } 
    else {
	$DB->Execute('UPDATE documents SET cancelled = 1 WHERE id = ?', array($id));
	//lms-stck Sarenka
	if (ConfigHelper::getConfig('phpui.stock')) {
		$stck_ica = $DB->GetAll('SELECT icitemid, stockid FROM stck_invoicecontentsassignments WHERE icdocid = ?', array($id));
		if ($stck_ica) {
			$doc = $DB->GetRow('SELECT number, cdate, template, extnumber, paytime, paytype
			        FROM documents
				LEFT JOIN numberplans ON (numberplanid = numberplans.id)
				WHERE documents.id = ?', array($id));
			foreach ($stck_ica as $pos) {
				$LMSST->StockUnSell($pos['stockid'], trans('Canceled invoice (nr: $a)', docnumber($doc['number'], $doc['template'], $doc['cdate'], $doc['extnumber'])));
			}
		}
	}
	$DB->Execute('DELETE FROM cash WHERE docid = ?', array($id));
	$document = $DB->GetRow('SELECT * FROM documents WHERE id = ?', array($id));
	if ($SYSLOG) {
		$args = array(
		    $SYSLOG_RESOURCE_KEYS[SYSLOG_RES_DOC] => $document['id'],
		    $SYSLOG_RESOURCE_KEYS[SYSLOG_RES_CUST] => $document['customerid'],
		    $SYSLOG_RESOURCE_KEYS[SYSLOG_RES_USER] => $AUTH->id
		);
		$SYSLOG->AddMessage(SYSLOG_RES_DOC, SYSLOG_OPER_UPDATE, $args, 
			array($SYSLOG_RESOURCE_KEYS[SYSLOG_RES_CUST] , $SYSLOG_RESOURCE_KEYS[SYSLOG_RES_DOC], $SYSLOG_RESOURCE_KEYS[SYSLOG_RES_USER])
		);
=======
	if (isset($_GET['recover'])) {
		$DB->Execute('UPDATE documents SET cancelled = 0 WHERE id = ?', array($id));
		$document = $DB->GetRow('SELECT customerid, cdate FROM documents WHERE id = ?', array($id));
		$invoices = $DB->GetAll('SELECT * FROM invoicecontents WHERE docid = ?', array($id));
		$itemid = 1;
		foreach ($invoices as $invoice) {
			$LMS->AddBalance(array(
				'time' => $document['cdate'],
				'value' => $invoice['value'] * $invoice['count'] * -1,
				'taxid' => $invoice['taxid'],
				'customerid' => $document['customerid'],
				'comment' => $invoice['description'],
				'docid' => $id,
				'itemid' => $itemid
			));
			$itemid += 1;
		}
		if ($SYSLOG) {
			$args = array(
				SYSLOG::RES_DOC => $document['id'],
				SYSLOG::RES_CUST => $document['customerid'],
				SYSLOG::RES_USER => $AUTH->id
			);
			$SYSLOG->AddMessage(SYSLOG::RES_DOC, SYSLOG::OPER_UPDATE, $args);
		}
	} else {
		$DB->Execute('UPDATE documents SET cancelled = 1 WHERE id = ?', array($id));
		$DB->Execute('DELETE FROM cash WHERE docid = ?', array($id));
		$document = $DB->GetRow('SELECT * FROM documents WHERE id = ?', array($id));
		if ($SYSLOG) {
			$args = array(
				SYSLOG::RES_DOC => $document['id'],
				SYSLOG::RES_CUST => $document['customerid'],
				SYSLOG::RES_USER => $AUTH->id
			);
			$SYSLOG->AddMessage(SYSLOG::RES_DOC, SYSLOG::OPER_UPDATE, $args);
		}
>>>>>>> 8be93af356821963ef3b0ffbe8e5a4742391d77b
	}
}

$SESSION->redirect('?m=invoicelist');

?>
