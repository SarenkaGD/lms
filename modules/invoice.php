<?php

/*
 * LMS version 1.11-git
 *
 *  (C) Copyright 2001-2014 LMS Developers
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

function invoice_body($document, $invoice) {
	$document->Draw($invoice);
	if (!isset($invoice['last']))
		$document->NewPage();
}

$attachment_name = ConfigHelper::getConfig('invoices.attachment_name');
$invoice_type = strtolower(ConfigHelper::getConfig('invoices.type'));

if ($invoice_type == 'pdf') {
	$pdf_type = ConfigHelper::getConfig('invoices.pdf_type', 'tcpdf');
	$pdf_type = ucwords($pdf_type);
	$classname = 'LMS' . $pdf_type . 'Invoice';
	$document = new $classname(trans('Invoices'));
} else
	$document = new LMSHtmlInvoice($SMARTY);

if (isset($_GET['print']) && $_GET['print'] == 'cached') {
	$SESSION->restore('ilm', $ilm);
	$SESSION->remove('ilm');

	if (isset($_POST['marks']))
		foreach ($_POST['marks'] as $idx => $mark)
			$ilm[$idx] = intval($mark);

	if (sizeof($ilm))
		foreach ($ilm as $mark)
			$ids[] = $mark;

	if (!isset($ids)) {
		$SESSION->close();
		die;
	}

	$layout['pagetitle'] = trans('Invoices');

	if (isset($_GET['cash'])) {
		$ids = $DB->GetCol('SELECT DISTINCT docid
			FROM cash, documents
			WHERE docid = documents.id AND (documents.type = ? OR documents.type = ?)
				AND cash.id IN ('.implode(',', $ids).')
			ORDER BY docid',
			array(DOC_INVOICE, DOC_CNOTE));
	}

	if (!empty($_GET['original'])) $which[] = trans('ORIGINAL');
	if (!empty($_GET['copy'])) $which[] = trans('COPY');
	if (!empty($_GET['duplicate'])) $which[] = trans('DUPLICATE');

	if (!sizeof($which)) $which[] = trans('ORIGINAL');

	$count = sizeof($ids) * sizeof($which);
	$i = 0;

	foreach ($ids as $idx => $invoiceid) {
		$invoice = $LMS->GetInvoiceContent($invoiceid);
		if (count($ids) == 1)
			$docnumber = docnumber($invoice['number'], $invoice['template'], $invoice['cdate']);

		foreach ($which as $type) {
			$i++;
			if ($i == $count) $invoice['last'] = TRUE;
			$invoice['type'] = $type;
			invoice_body($document, $invoice);
		}
	}
} elseif (isset($_GET['fetchallinvoices'])) {
	$layout['pagetitle'] = trans('Invoices');

	$offset = intval(date('Z'));
	$ids = $DB->GetCol('SELECT id FROM documents d
				WHERE cdate >= ? AND cdate <= ? AND (type = ? OR type = ?)'
				.(!empty($_GET['divisionid']) ? ' AND d.divisionid = ' . intval($_GET['divisionid']) : '')
				.(!empty($_GET['customerid']) ? ' AND d.customerid = '.intval($_GET['customerid']) : '')
				.(!empty($_GET['numberplanid']) ? ' AND d.numberplanid = '.intval($_GET['numberplanid']) : '')
				.(!empty($_GET['autoissued']) ? ' AND d.userid = 0' : '')
				.(!empty($_GET['groupid']) ?
				' AND '.(!empty($_GET['groupexclude']) ? 'NOT' : '').'
					EXISTS (SELECT 1 FROM customerassignments a
					WHERE a.customergroupid = '.intval($_GET['groupid']).'
						AND a.customerid = d.customerid)' : '')
				.' AND NOT EXISTS (
					SELECT 1 FROM customerassignments a
					JOIN excludedgroups e ON (a.customergroupid = e.customergroupid)
					WHERE e.userid = lms_current_user() AND a.customerid = d.customerid)'
				.' ORDER BY CEIL(cdate/86400), id',
				array(intval($_GET['from']) - $offset, intval($_GET['to']) - $offset, DOC_INVOICE, DOC_CNOTE));
	if (!$ids) {
		$SESSION->close();
		die;
	}

	if (!empty($_GET['original'])) $which[] = trans('ORIGINAL');
	if (!empty($_GET['copy'])) $which[] = trans('COPY');
	if (!empty($_GET['duplicate'])) $which[] = trans('DUPLICATE');

	if (!sizeof($which)) $which[] = trans('ORIGINAL');

	$count = sizeof($ids) * sizeof($which);
	$i = 0;

	if ($jpk) {
		$jpk_data .= "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
		$jpk_data .= "<JPK xmlns=\"http://jpk.mf.gov.pl/wzor/2016/03/09/03095/\" xmlns:etd=\"http://crd.gov.pl/xml/schematy/dziedzinowe/mf/2016/01/25/eD/DefinicjeTypy/\">\n";

		$divisionid = intval($_GET['divisionid']);
		$division = $DB->GetRow("SELECT d.name, shortname, address, city, zip, countryid, ten, regon,
				account, inv_header, inv_footer, inv_author, inv_cplace, location_city, location_street, tax_office_code,
				lb.name AS borough, ld.name AS district, ls.name AS state FROM divisions d
				LEFT JOIN location_cities lc ON lc.id = location_city
				LEFT JOIN location_boroughs lb ON lb.id = lc.boroughid
				LEFT JOIN location_districts ld ON ld.id = lb.districtid
				LEFT JOIN location_states ls ON ls.id = ld.stateid
				WHERE d.id = ?", array($divisionid));

		// JPK header
		$jpk_data .= "\t<Naglowek>\n";
		$jpk_data .= "\t\t<KodFormularza kodSystemowy=\"JPK_FA (1)\" wersjaSchemy=\"1-0\">JPK_FA</KodFormularza>\n";
		$jpk_data .= "\t\t<WariantFormularza>1</WariantFormularza>\n";
		$jpk_data .= "\t\t<CelZlozenia>1</CelZlozenia>\n";
		$jpk_data .= "\t\t<DataWytworzeniaJPK>" . strftime('%Y-%m-%dT%H:%M:%S') . "</DataWytworzeniaJPK>\n";
		$jpk_data .= "\t\t<DataOd>" . strftime('%Y-%m-%d', $datefrom) . "</DataOd>\n";
		$jpk_data .= "\t\t<DataDo>" . strftime('%Y-%m-%d', $dateto) . "</DataDo>\n";
		$jpk_data .= "\t\t<DomyslnyKodWaluty>PLN</DomyslnyKodWaluty>\n";
		$jpk_data .= "\t\t<KodUrzedu>" . (!empty($division['tax_office_code']) ? $division['tax_office_code']
			: ConfigHelper::getConfig('jpk.tax_office_code', '', true)) . "</KodUrzedu>\n";
		$jpk_data .= "\t</Naglowek>\n";

		$jpk_data .= "\t<Podmiot1>\n";
		$jpk_data .= "\t\t<IdentyfikatorPodmiotu>\n";
		$jpk_data .= "\t\t\t<etd:NIP>" . preg_replace('/[\s\-]/', '', $division['ten']) . "</etd:NIP>\n";
		$jpk_data .= "\t\t\t<etd:PelnaNazwa>" . $division['name'] . "</etd:PelnaNazwa>\n";
		$jpk_data .= "\t\t\t<etd:REGON>" . $division['regon'] . "</etd:REGON>\n";
		$jpk_data .= "\t\t</IdentyfikatorPodmiotu>\n";
		$jpk_data .= "\t\t<AdresPodmiotu>\n";
		$jpk_data .= "\t\t\t<etd:KodKraju>PL</etd:KodKraju>\n";
		$jpk_data .= "\t\t\t<etd:Wojewodztwo>" . (!empty($division['state']) ? $division['state']
			: ConfigHelper::getConfig('jpk.division_state', '', true)) . "</etd:Wojewodztwo>\n";
		$jpk_data .= "\t\t\t<etd:Powiat>" . (!empty($division['district']) ? $division['district']
			: ConfigHelper::getConfig('jpk.division_district', '', true)) . "</etd:Powiat>\n";
		$jpk_data .= "\t\t\t<etd:Gmina>" . (!empty($division['borough']) ? $division['borough']
			: ConfigHelper::getConfig('jpk.division_borough', '', true)) . "</etd:Gmina>\n";
		$address = parse_address($division['address']);
		$jpk_data .= "\t\t\t<etd:Ulica>" . $address['street'] . "</etd:Ulica>\n";
		$jpk_data .= "\t\t\t<etd:NrDomu>" . $address['house'] . "</etd:NrDomu>\n";
		if (isset($address['flat']))
			$jpk_data .= "\t\t\t<etd:NrLokalu>" . $address['flat'] . "</etd:NrLokalu>\n";
		$jpk_data .= "\t\t\t<etd:Miejscowosc>" . $division['city'] . "</etd:Miejscowosc>\n";
		$jpk_data .= "\t\t\t<etd:KodPocztowy>" . $division['zip'] . "</etd:KodPocztowy>\n";
		$jpk_data .= "\t\t\t<etd:Poczta>" . ConfigHelper::getConfig('jpk.division_postal_city', $division['city']) . "</etd:Poczta>\n";
		$jpk_data .= "\t\t</AdresPodmiotu>\n";
		$jpk_data .= "\t</Podmiot1>\n";
		$totalvalue = 0;
	}

	$invoices = array();
	foreach ($ids as $idx => $invoiceid) {
		$invoice = $LMS->GetInvoiceContent($invoiceid);
		if (count($ids) == 1)
			$docnumber = docnumber($invoice['number'], $invoice['template'], $invoice['cdate']);

		foreach ($which as $type) {
			$i++;
			if ($i == $count) $invoice['last'] = TRUE;
			$invoice['type'] = $type;
			invoice_body($document, $invoice);
		}
	}
} elseif ($invoice = $LMS->GetInvoiceContent($_GET['id'])) {
	$docnumber = docnumber($invoice['number'], $invoice['template'], $invoice['cdate']);
	if(!isset($invoice['invoice']))
		$layout['pagetitle'] = trans('Invoice No. $a', $docnumber);
	else
		$layout['pagetitle'] = trans('Credit Note No. $a', $docnumber);

	$which = array();

	if (!empty($_GET['original'])) $which[] = trans('ORIGINAL');
	if (!empty($_GET['copy'])) $which[] = trans('COPY');
	if (!empty($_GET['duplicate'])) $which[] = trans('DUPLICATE');

	if (!sizeof($which)) {
		$tmp = explode(',', ConfigHelper::getConfig('invoices.default_printpage'));
		foreach ($tmp as $t)
			if (trim($t) == 'original') $which[] = trans('ORIGINAL');
			elseif (trim($t) == 'copy') $which[] = trans('COPY');
			elseif (trim($t) == 'duplicate') $which[] = trans('DUPLICATE');

		if (!sizeof($which)) $which[] = trans('ORIGINAL');
	}

	$count = sizeof($which);
	$i = 0;

	foreach ($which as $type) {
		$i++;
		if ($i == $count) $invoice['last'] = TRUE;
		$invoice['type'] = $type;
		invoice_body($document, $invoice);
	}
} else
	$SESSION->redirect('?m=invoicelist');

if (!is_null($attachment_name) && isset($docnumber)) {
	$attachment_name = str_replace('%number', $docnumber, $attachment_name);
	$attachment_name = preg_replace('/[^[:alnum:]_\.]/i', '_', $attachment_name);
} else
	$attachment_name = 'invoices.' . ($invoice_type == 'pdf' ? 'pdf' : 'html');

$document->WriteToBrowser($attachment_name);

?>
