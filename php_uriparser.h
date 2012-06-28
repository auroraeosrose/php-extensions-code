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

#ifndef PHP_URIPARSER_H
#define PHP_URIPARSER_H

#define PHP_URIPARSER_VERSION "0.1.0-dev"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/* Standard PHP headers */
#include "php.h"

/* Our library header */
#include <uriparser/Uri.h>

#ifdef PHP_WIN32
#	define PHP_URIPARSER_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_URIPARSER_API __attribute__ ((visibility("default")))
#else
#	define PHP_URIPARSER_API
#endif

extern zend_module_entry uriparser_module_entry;
#define phpext_uriparser_ptr &uriparser_module_entry

PHP_MINIT_FUNCTION(uriparser_uri);

#define PHP_URIPARSER_NS "UriParser"

#endif /* PHP_URIPARSER_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */