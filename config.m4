dnl uriparser extension

PHP_ARG_WITH(uriparser, An RFC compliant URI parser,
[  --with-uriparser            Enable uriparser support], yes)

if test "$PHP_URIPARSER" != "no"; then
  PHP_NEW_EXTENSION(uriparser, php_uriparser.c, $ext_shared)
fi