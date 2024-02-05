/************************************************************************/
/*									*/
/*  Printf like functionality of SimpleOutputStream's			*/
/*									*/
/************************************************************************/

#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include "sioGeneral.h"
#include "sioVPrintf.h"
#include <appDebugon.h>

/************************************************************************/
/*									*/
/*  Printf formatting on output streams.				*/
/*									*/
/************************************************************************/

int sioOutVPrintf(SimpleOutputStream *sos, const char *format, va_list ap)
{
	char *buf = NULL;
	va_list tmp;
	va_copy(tmp, ap);
	int sz = vsnprintf(NULL, 0, format, tmp);
	buf = (char *)malloc(sz + 1);
	vsnprintf(buf, sz + 1, format, ap);

	int err = sioOutPutString(buf, sos);
	free(buf);
	if (err < 0)
		return err;
	else
		return sz;
}

int sioOutPrintf(SimpleOutputStream *sos, const char *format, ...)
{
	int emitted = 0;
	va_list valist;

	va_start(valist, format);

	emitted = sioOutVPrintf(sos, format, valist);

	va_end(valist);

	return emitted;
}
