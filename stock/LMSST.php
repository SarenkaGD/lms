<?php
/* lms-stck INIT FILE */

//Sorry, bo no-go for postgres :(
if (ConfigHelper::getConfig('database.database') == 'postgres') {
 	trigger_error("lms-stck doesn`t support PostgreSQL (yet)!", E_USER_WARNING);
	die('Fatal error: lms-stck doesn`t support PostgreSQL (yet)!');
}

define('STCK_DBVERSION', '2016040301');
define('STCK_DIR', $CONFIG['directories']['sys_dir'] . DIRECTORY_SEPARATOR . 'stock');

require('LMSST.class.php');

$LMSST = new LMSST($DB, $AUTH, $CONFIG, $LMS);
?>
