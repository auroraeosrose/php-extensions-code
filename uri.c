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

ZEND_BEGIN_ARG_INFO(uriparser_uri_test_args, ZEND_SEND_BY_VAL)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

PHP_METHOD(UriParser_Uri, test)
{
	char * name;
	int len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &len) == FAILURE) {
		return;
	}

	php_printf("Hello stranger, this is a test for %s!\n", name);
}

/* {{{ uriparser_uri_test_args[] */
zend_function_entry uriparser_uri_methods[] = {
	PHP_ME(UriParser_Uri, test, uriparser_uri_test_args, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(uriparser_uri)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, ZEND_NS(PHP_URIPARSER_NS, "Uri"), uriparser_uri_methods);

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