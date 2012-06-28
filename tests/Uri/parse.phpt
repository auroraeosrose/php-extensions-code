--TEST--
UriParser\Uri->parse(string path)
--SKIPIF--
<?php
if(!extension_loaded('uriparser')) die('skip - Uriparser extension not available');
?>
--FILE--
<?php
use UriParser\Uri;
$uri = new Uri;
var_dump($uri->parse('http://foobar.com'));
var_dump($uri->parse('hello dolly'));
?>
--EXPECTF--
bool(true)
bool(false)