<?php
/* lms-stck INIT FILE */

//Sorry, bo no-go for postgres :(
if (ConfigHelper::getConfig('database.database') == 'postgresql') {
 	trigger_error("lms-stck doesn`t support PostgreSQL (yet)!", E_USER_WARNING);
	die('Fatal error: lms-stck doesn`t support PostgreSQL (yet)!');
}

define('STCK_DBVERSION', '2016032500');
define('STCK_DIR', $CONFIG['directories']['sys_dir'] . DIRECTORY_SEPARATOR . 'stock');

require('LMSST.class.php');

$LMSST = new LMSST($DB, $AUTH, $CONFIG, $LMS);
?>
