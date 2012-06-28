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
object(UriParser\Uri)#%d (0) {
}