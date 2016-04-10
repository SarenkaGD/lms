<?php
$access_table['lms-stck-full'] = array(
	'label' => trans('full access to lms-stck module'),
	'allow_regexp' => '^(stck)[a-z]+$'
	);

$access_table['lms-stck-reports'] = array(
	'label' => trans('full access lms-stck reports'),
	'allow_regexp' => '^printstock$'
	);

/*$access['table'][100]['name']      = 'magazyn';
$access['table'][100]['allow_reg'] = '^(stck)[a-z]+$';

$access['table'][101]['name']           = 'raporty magazynowe';
$access['table'][101]['allow_reg']      = '^printstock$';
*/?>
