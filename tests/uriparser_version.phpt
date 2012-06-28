--TEST--
uriparser_version() function
--SKIPIF--
<?php
if(!extension_loaded('uriparser')) die('skip - Uriparser extension not available');
?>
--FILE--
<?php
$version = uriparser_version();
var_dump($version);

uriparser_version('foo');
?>
--EXPECTF--
string(%d) %s

Warning: uriparser_version() expects exactly 0 parameters, 1 given in %s on line %d