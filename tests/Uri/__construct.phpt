--TEST--
UriParser\Uri->__construct()
--SKIPIF--
<?php
if(!extension_loaded('uriparser')) die('skip - Uriparser extension not available');
?>
--FILE--
<?php
use UriParser\Uri;
$uri = new Uri;
var_dump($uri);
?>
--EXPECTF--
object(UriParser\Uri)#%d (8) {
  ["scheme"]=>
  NULL
  ["user"]=>
  NULL
  ["host"]=>
  NULL
  ["port"]=>
  NULL
  ["path"]=>
  NULL
  ["query"]=>
  NULL
  ["fragment"]=>
  NULL
  ["isAbsolute"]=>
  NULL
}