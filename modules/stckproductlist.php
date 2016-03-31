<?php
$CONFIG['phpui']['short_pagescroller'] = 1;
$layout['pagetitle'] = trans('Product list');

if(!isset($_GET['o']))
	$SESSION->restore('sglo', $o);
else
	$o = $_GET['o'];
$order = $o;
$SESSION->save('sglo', $o);

if (isset($_POST['s_pl'])) {
	$s_pl = $_POST['s_pl'];
	foreach($s_pl as $k => $v) {
		if (!ctype_digit($v) && $v != "") {
			unset($s_pl);
			break;
		}
		if ($v == "") {
			$s_pl[$k] = NULL;
		}
	}
	$SESSION->save('s_pl', $s_pl);
} else {
	$SESSION->restore('s_pl', $s_pl);
}

$productlist = $LMSST->ProductGetList($o, $s_pl['manufacturer'], $s_pl['group']);

$listdata['total'] = $productlist['total'];
$listdata['direction'] = $productlist['direction'];
$listdata['order'] = $productlist['order'];
unset($productlist['total']);
unset($productlist['direction']);
unset($productlist['order']);

$manufacturerlist = $LMSST->ManufacturerGetList($o);
unset($manufacturerlist['total']);
unset($manufacturerlist['direction']);
unset($manufacturerlist['order']);

$grouplist = $LMSST->GroupGetList($o);
unset($grouplist['total']);
unset($grouplist['direction']);
unset($grouplist['order']);

if(!isset($_GET['page']))
        $SESSION->restore('sglp', $_GET['page']);

$page = (! $_GET['page'] ? 1 : $_GET['page']);
$pagelimit = (! $CONFIG['phpui']['productlist_pagelimit'] ? $listdata['total'] : $CONFIG['phpui']['productlist_pagelimit']);
$start = ($page - 1) * $pagelimit;

$SESSION->save('swlp', $page);

$SESSION->save('backto', $_SERVER['QUERY_STRING']);

$SMARTY->assign('page',$page);
$SMARTY->assign('pagelimit',$pagelimit);
$SMARTY->assign('start',$start);
$SMARTY->assign('productlist', $productlist);
$SMARTY->assign('listdata', $listdata);
$SMARTY->assign('manufacturers', $manufacturerlist);
$SMARTY->assign('groups', $grouplist);
$SMARTY->assign('s_pl', $s_pl);
$SMARTY->display('stck/stckproductlist.html');
?>
