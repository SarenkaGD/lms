<?php
$this->DB->BeginTrans();

$this->DB->Execute('UPDATE stck_stock s
	JOIN stck_products p
	ON s.productid = p.id
	SET s.groupid = p.groupid
	WHERE s.groupid <> p.groupid');

$this->DB->CommitTrans();
?>
