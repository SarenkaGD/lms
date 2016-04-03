<?php
$this->DB->BeginTrans();

$this->DB->Execute('ALTER TABLE `stck_stock` CHANGE `deleted` `deleted` BOOLEAN NOT NULL DEFAULT FALSE;');

$this->DB->CommitTrans();
?>
