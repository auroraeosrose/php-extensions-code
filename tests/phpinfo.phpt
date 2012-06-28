--TEST--
uriparser phpinfo information
--SKIPIF--
<?php
if(!extension_loaded('uriparser')) die('skip - Uriparser extension not available');
?>
--FILE--
<?php
ob_start();
phpinfo(INFO_MODULES);
$data = ob_get_clean();
$data = explode("\n\n", $data);
foreach($data as $key => $info) {
	if ($info === 'uriparser') {
		break;
	}
}
$data = $data[$key + 1];
var_dump($data);
?>
--EXPECTF--
string(%d) "Uriparser Library Bindings => enabled
Uriparser Library Version => %s
Extension Version => %s"