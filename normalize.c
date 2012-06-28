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

zend_class_entry *uriparser_normalize_ce;

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(uriparser_normalize)
{
	zend_class_entry ce;
    
	INIT_CLASS_ENTRY(ce, ZEND_NS_NAME(PHP_URIPARSER_NS, "Normalize"), NULL);
	uriparser_normalize_ce = zend_register_internal_class(&ce TSRMLS_CC);
	uriparser_normalize_ce->ce_flags |= ZEND_ACC_FINAL | ZEND_ACC_ABSTRACT;
	
	zend_declare_class_constant_long(uriparser_normalize_ce, "FRAGMENT", sizeof("FRAGMENT")-1, (long)URI_NORMALIZE_FRAGMENT TSRMLS_CC);
	zend_declare_class_constant_long(uriparser_normalize_ce, "HOST", sizeof("HOST")-1, (long)URI_NORMALIZE_HOST TSRMLS_CC); 
	zend_declare_class_constant_long(uriparser_normalize_ce, "PATH", sizeof("PATH")-1, (long)URI_NORMALIZE_PATH TSRMLS_CC); 
	zend_declare_class_constant_long(uriparser_normalize_ce, "QUERY", sizeof("QUERY")-1, (long)URI_NORMALIZE_QUERY TSRMLS_CC); 
	zend_declare_class_constant_long(uriparser_normalize_ce, "SCHEME", sizeof("SCHEME")-1, (long)URI_NORMALIZE_SCHEME TSRMLS_CC); 
	zend_declare_class_constant_long(uriparser_normalize_ce, "USER_INFO", sizeof("USER_INFO")-1, (long)URI_NORMALIZE_USER_INFO TSRMLS_CC); 

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