/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Elizabeth Smith <auroraeosrose@php.net>                      |
  +----------------------------------------------------------------------+
*/

#include "php_uriparser.h"

zend_class_entry *uriparser_uri_ce;

ZEND_BEGIN_ARG_INFO(uriparser_uri_parse_args, ZEND_SEND_BY_VAL)
    ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

/* {{{ proto bool UriParser\Uri::parse(string path)
    simple parse example that does something*/
PHP_METHOD(UriParser_Uri, parse)
{
	char * path;
	int len;
	UriParserStateA state;
	UriUriA uri;
	
	    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &path, &len) == FAILURE) {
		    return;
	    }
	
	state.uri = &uri;
	if (uriParseUriA(&state, path) != URI_SUCCESS) {
	    RETVAL_FALSE;
	} else {
	    RETVAL_TRUE;
	}
	
	uriFreeUriMembersA(&uri);
}
/* }}} */

ZEND_BEGIN_ARG_INFO(uriparser_uri_setscheme_args, ZEND_SEND_BY_VAL)
    ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

/* {{{ proto void UriParser\Uri::setScheme(scheme)
 set the value of the scheme property */
PHP_METHOD(UriParser_Uri, setScheme)
{
	char * scheme;
	int len;
    
    
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &scheme, &len) == FAILURE) {
		return;
	}
    
    zend_update_property_stringl(uriparser_uri_ce, getThis(), "scheme", strlen("scheme"), scheme, len TSRMLS_CC);
}
/* }}} */

/* {{{ uriparser_uri_test_args[] */
zend_function_entry uriparser_uri_methods[] = {
	PHP_ME(UriParser_Uri, parse, uriparser_uri_parse_args, ZEND_ACC_PUBLIC)
	PHP_ME(UriParser_Uri, setScheme, uriparser_uri_setscheme_args, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(uriparser_uri)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, ZEND_NS_NAME(PHP_URIPARSER_NS, "Uri"), uriparser_uri_methods);
	uriparser_uri_ce = zend_register_internal_class(&ce TSRMLS_CC);
	zend_declare_property_null(uriparser_uri_ce, ZEND_STRS("scheme")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(uriparser_uri_ce, ZEND_STRS("user")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(uriparser_uri_ce, ZEND_STRS("host")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(uriparser_uri_ce, ZEND_STRS("port")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(uriparser_uri_ce, ZEND_STRS("path")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(uriparser_uri_ce, ZEND_STRS("query")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(uriparser_uri_ce, ZEND_STRS("fragment")-1, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(uriparser_uri_ce, ZEND_STRS("isAbsolute")-1, ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */