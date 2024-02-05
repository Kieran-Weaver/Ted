/************************************************************************/
/*									*/
/*  Convert text from/to UTF-8 using iconv.				*/
/*									*/
/************************************************************************/

#include <config.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <iconv.h>
#include "uniUtf8.h"
#include <appDebugon.h>
#include "textConverter.h"
#include "textConverterImpl.h"
#include <utilIndexMapping.h>
#include "uniLegacyEncoding.h"
#include "uniLegacyMapping.h"
void textConverterSetNativeEncodingName(TextConverter *tc,
					const char *encodingName)
{
	if (!encodingName) {
		XDEB(encodingName);
		return;
	}

	/* Shortcut that also covers the both null case */
	if (tc->tcNativeEncodingName == encodingName) {
		return;
	}

	if ((tc->tcNativeEncodingName && !encodingName) ||
	    (!tc->tcNativeEncodingName && encodingName) ||
	    strcmp(tc->tcNativeEncodingName, encodingName)) {
		char *oldName = tc->tcNativeEncodingName;

		if ((iconv_t)tc->tcIconvToUtf8 != (iconv_t)-1) {
			iconv_close((iconv_t)tc->tcIconvToUtf8);
			tc->tcIconvToUtf8 =
				(struct TextConverterImpl *)(iconv_t)-1;
		}

		if ((iconv_t)tc->tcIconvFrUtf8 != (iconv_t)-1) {
			iconv_close((iconv_t)tc->tcIconvFrUtf8);
			tc->tcIconvFrUtf8 =
				(struct TextConverterImpl *)(iconv_t)-1;
		}

		if (encodingName) {
			tc->tcNativeEncodingName = strdup(encodingName);
		} else {
			tc->tcNativeEncodingName = (char *)0;
		}

		if (oldName) {
			free(oldName);
		}
	}

	return;
}

void textInitTextConverter(TextConverter *tc)
{
	tc->tcNativeEncodingName = (char *)0;
	tc->tcIconvToUtf8 = (struct TextConverterImpl *)(iconv_t)-1;
	tc->tcIconvFrUtf8 = (struct TextConverterImpl *)(iconv_t)-1;

	tc->tcProduce = (TextConverterProduce)0;
}

void textCleanTextConverter(TextConverter *tc)
{
	if (tc->tcNativeEncodingName) {
		free(tc->tcNativeEncodingName);
	}

	if ((iconv_t)tc->tcIconvToUtf8 != (iconv_t)-1) {
		iconv_close((iconv_t)tc->tcIconvToUtf8);
		tc->tcIconvToUtf8 = (struct TextConverterImpl *)(iconv_t)-1;
	}

	if ((iconv_t)tc->tcIconvFrUtf8 != (iconv_t)-1) {
		iconv_close((iconv_t)tc->tcIconvFrUtf8);
		tc->tcIconvFrUtf8 = (struct TextConverterImpl *)(iconv_t)-1;
	}
}

/************************************************************************/

static int textConverterProduce(const TextConverter *tc, void *through,
				int produced, const char *text, int len)
{
	int step;

	step = (*tc->tcProduce)(through, produced, text, len);
	if (step < 0) {
		LLLDEB(produced, len, step);
		return -1;
	}

	return step;
}

/************************************************************************/
/*									*/
/*  Hack because iconv does not support the symbol encoding.		*/
/*  Convert legacy bytes to UTF-8.					*/
/*									*/
/************************************************************************/

static int textConverterConvertBytesToUtf8(const TextConverter *tc,
					   const int unicodes[256],
					   void *through, int *pConsumed,
					   int produced, const char *text,
					   int len)
{
	char scratch[750];
	int buffered = 0;
	int step;
	const int scratchLen = sizeof(scratch) - 7;
	int consumed = 0;

	while (len > 0) {
		if (buffered >= scratchLen) {
			step = textConverterProduce(tc, through, produced,
						    scratch, buffered);
			if (step < 0) {
				LLLDEB(produced, buffered, step);
				return -1;
			}
			produced += step;
			buffered = 0;
		}

		if (unicodes[*text & 0xff] < 0) {
			step = uniPutUtf8(scratch + buffered, *text & 0xff);
		} else {
			step = uniPutUtf8(scratch + buffered,
					  unicodes[*text & 0xff]);
		}
		if (step < 1) {
			LDEB(step);
			return -1;
		}

		text++;
		len--;
		consumed++;
		buffered += step;
	}

	if (buffered > 0) {
		step = textConverterProduce(tc, through, produced, scratch,
					    buffered);
		if (step < 0) {
			LLLDEB(produced, buffered, step);
			return -1;
		}
		produced += step;
		buffered = 0;
	}

	*pConsumed += consumed;
	return produced;
}

/************************************************************************/
/*									*/
/*  Convert bytes using iconv. This is used in both directions.		*/
/*									*/
/*  Note that GNU iconv() expects a 'char **' as its second argument	*/
/*  rather than a 'const char **' as documented in the single UNIX spec.*/
/*  See: http://www.opengroup.org/pubs/online/7908799/xsh/iconv.html.	*/
/*									*/
/************************************************************************/

static int textConverterConvertIconv(TextConverter *tc,
				     struct TextConverterImpl *tci,
				     void *through, int *pConsumed,
				     int produced, const char *arg_ibuf,
				     size_t ileft)
{
	char scratch[750];
	char *obuf = scratch;
	size_t oleft = sizeof(scratch);
	int consumed = 0;

	iconv_t ico = (iconv_t)tci;

#if defined(__GNUC__) && !defined(iconv)
	char *ibuf = (char *)arg_ibuf;
#else
	const char *ibuf = arg_ibuf;
#endif

	while (ileft > 0) {
		const char *iibuf = ibuf;

		while (oleft > 0 && ileft > 0) {
			/*  return value is irrelevant: Just tells that the	*/
			/*  conversion was incomplete. So does ileft > 0.	*/

			(void)iconv(ico, &ibuf, &ileft, &obuf, &oleft);

			if (ibuf == iibuf) { /*XXDEB(ibuf,iibuf);*/
				break;
			}

			consumed += ibuf - iibuf;
			iibuf = ibuf;
		}

		if (obuf > scratch) {
			int step;

			step = textConverterProduce(tc, through, produced,
						    scratch, obuf - scratch);
			if (step < 0) {
				LLLDEB(produced, obuf - scratch, step);
				return -1;
			}

			produced += step;
			obuf = scratch;
			oleft = sizeof(scratch);
		}

		if (ileft > 0 &&
		    errno == EILSEQ) { /*LSCDEB(errno,strerror(errno),*ibuf);*/
			break;
		}
		if (ileft > 0 && errno != E2BIG) {
			LSDEB(errno, strerror(errno));
			return -1;
		}
	}

	*pConsumed += consumed;
	return produced;
}

/************************************************************************/
/*									*/
/*  Convert the input to UTF-8 bytes.					*/
/*									*/
/*  Note that GNU iconv() expects a 'char **' as its second argument	*/
/*  rather than a 'const char **' as documented in the single UNIX spec.*/
/*  See: http://www.opengroup.org/pubs/online/7908799/xsh/iconv.html.	*/
/*									*/
/*  Also note that iconv_open() returns an (iconv_t)-1 rather than	*/
/*  (iconv_t)0 on failure as is to be expected for a call that returns	*/
/*  a (void *) pointer.							*/
/*									*/
/************************************************************************/

int textConverterConvertToUtf8(TextConverter *tc, void *through, int *pConsumed,
			       int produced, const char *text, int len)
{
	if (tc && tc->tcNativeEncodingName && tc->tcNativeEncodingName[0]) {
		if ((iconv_t)tc->tcIconvToUtf8 == (iconv_t)-1) {
			tc->tcIconvToUtf8 =
				(struct TextConverterImpl *)iconv_open(
					"UTF-8", tc->tcNativeEncodingName);

			if ((iconv_t)tc->tcIconvToUtf8 == (iconv_t)-1 &&
			    !strcmp(tc->tcNativeEncodingName, "SYMBOL")) {
				return textConverterConvertBytesToUtf8(
					tc, uniSymbolGlyphUnicodes, through,
					pConsumed, produced, text, len);
			}

			if ((iconv_t)tc->tcIconvToUtf8 == (iconv_t)-1 &&
			    !strcmp(tc->tcNativeEncodingName, "DINGBATS")) {
				return textConverterConvertBytesToUtf8(
					tc, uniDingbatsGlyphUnicodes, through,
					pConsumed, produced, text, len);
			}

			if ((iconv_t)tc->tcIconvToUtf8 == (iconv_t)-1) {
				SXDEB(tc->tcNativeEncodingName,
				      tc->tcIconvToUtf8);
				return -1;
			}
		}

		produced = textConverterConvertIconv(tc, tc->tcIconvToUtf8,
						     through, pConsumed,
						     produced, (char *)text,
						     len);
		if (produced < 0) {
			LDEB(produced);
			return -1;
		}
	} else {
		int step;

		step = textConverterProduce(tc, through, produced, text, len);
		if (step < 0) {
			LLLDEB(produced, len, step);
			return -1;
		}

		produced += step;
		*pConsumed += len;
	}

	return produced;
}

void textConverterSetProduce(struct TextConverter *tc,
			     TextConverterProduce produce)
{
	tc->tcProduce = produce;
}
