--TEST--
UriParser\Normalize
--SKIPIF--
<?php
if(!extension_loaded('uriparser')) die('skip - Uriparser extension not available');
?>
--FILE--
<?php
$class = new ReflectionClass ('UriParser\Normalize');
$array = $class->getConstants ();
var_dump ($array);
?>
--EXPECTF--
array(%d) {
  ["FRAGMENT"]=>
  int(32)
  ["HOST"]=>
  int(4)
  ["PATH"]=>
  int(8)
  ["QUERY"]=>
  int(16)
  ["SCHEME"]=>
  int(1)
  ["USER_INFO"]=>
  int(2)
}