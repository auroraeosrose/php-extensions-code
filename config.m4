dnl uriparser extension

PHP_ARG_WITH(uriparser, An RFC compliant URI parser,
[  --with-uriparser            Enable uriparser support], yes)

if test "$PHP_URIPARSER" != "no"; then

  SEARCH_PATH="$PHP_URIPARSER /usr/local /usr"
  SEARCH_FOR="/include/uriparser/Uri.h"
    if test -r $PHP_URIPARSER/$SEARCH_FOR; then # path given as parameter
      URIPARSER_DIR=$URIPARSER_DIR
    else 
      AC_MSG_CHECKING([for uriparser files in default path])
      for i in $SEARCH_PATH ; do
        if test -r $i/$SEARCH_FOR; then
          URIPARSER_DIR=$i
          AC_MSG_RESULT(found in $i)
        fi
      done
    fi
    if test -z "$URIPARSER_DIR"; then
      AC_MSG_RESULT([not found])
      AC_MSG_ERROR([Please reinstall the uriparser distribution])
    fi

    PHP_ADD_INCLUDE($URIPARSER_DIR/include)

    LIBNAME=uriparser
    LIBSYMBOL=uriParseUriA

    PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
    [
      PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $URIPARSER_DIR/$PHP_LIBDIR, URIPARSER_SHARED_LIBADD)
      AC_DEFINE(HAVE_URIPARSER,1,[ ])
    ],[
      AC_MSG_ERROR([wrong uriparser lib version or lib not found])
    ],[
      -L$URIPARSER_DIR/$PHP_LIBDIR -lm
    ])

    PHP_SUBST(URIPARSER_SHARED_LIBADD)
  
    PHP_NEW_EXTENSION(uriparser, php_uriparser.c uri.c, $ext_shared)
fi