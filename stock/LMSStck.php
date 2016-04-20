<?php
/* lms-stck INIT FILE */

//Sorry, bo no-go for postgres :(
if (ConfigHelper::getConfig('database.database') == 'postgres') {
 	trigger_error("lms-stck doesn`t support PostgreSQL (yet)!", E_USER_WARNING);
	die('Fatal error: lms-stck doesn`t support PostgreSQL (yet)!');
}

define('STCK_DBVERSION', '2016042001');
define('STCK_DIR', $CONFIG['directories']['sys_dir'] . DIRECTORY_SEPARATOR . 'stock');

require('LMSStck.class.php');

$LMSST = new LMSStck($DB, $AUTH, $CONFIG, $LMS);
?>
