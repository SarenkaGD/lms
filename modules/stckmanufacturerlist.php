<?php
function check($str){
	$c=strlen($str)==1 ? ord($str) : 0;    // get the ascii code if it is a single character
      	echo "C: ".$c;
	return ($c>=ord('A') && $c<=ord('Z'));  // it is a single character between a and z
}

if (!check($_GET['start']))
	$listdata['start'] = NULL;
else
	$listdata['start'] = $_GET['start'];

$layout['pagetitle'] = trans('Manufacturers');

if(!isset($_GET['o']))
	$SESSION->restore('smlo', $o);
else
	$o = $_GET['o'];

$SESSION->save('smlo', $o);

$manufacturerlist = $LMSST->ManufacturerGetList($o, $listdata['start']);
$listdata['total'] = $manufacturerlist['total'];
$listdata['direction'] = $manufacturerlist['direction'];
$listdata['order'] = $manufacturerlist['order'];
unset($manufacturerlist['total']);
unset($manufacturerlist['direction']);
unset($manufacturerlist['order']);

if(!isset($_GET['page']))
        $SESSION->restore('smlp', $_GET['page']);

$page = (! $_GET['page'] ? 1 : $_GET['page']);
$pagelimit = (!ConfigHelper::getConfig('phpui.manufacturerlist_pagelimit') ? 100 : ConfigHelper::getConfig('phpui.manufacturerlist_pagelimit'));
$start = ($page - 1) * $pagelimit;

$SESSION->save('smlp', $page);

$SESSION->save('backto', $_SERVER['QUERY_STRING']);

$SMARTY->assign('page',$page);
$SMARTY->assign('pagelimit',$pagelimit);
$SMARTY->assign('start',$start);
$SMARTY->assign('manufacturerlist', $manufacturerlist);
$SMARTY->assign('listdata', $listdata);
$SMARTY->display('stck/stckmanufacturerlist.html');
?>
