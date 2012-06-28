--TEST--
UriParser->setScheme(string scheme)
--SKIPIF--
<?php
if(!extension_loaded('uriparser')) die('skip - Uriparser extension not available');
?>
--FILE--
<?php
use UriParser\Uri;
$uri = new Uri;
$uri->setScheme('foobar');
var_dump($uri);
?>
--EXPECTF--
object(UriParser\Uri)#%d (8) {
  ["scheme":protected]=>
  string(6) "foobar"
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