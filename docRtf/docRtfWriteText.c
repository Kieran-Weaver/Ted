/************************************************************************/
/*									*/
/*  Manage the actual string content while reading an RTF document.	*/
/*									*/
/************************************************************************/

#include <config.h>
#include <ctype.h>
#include <stdint.h>
#include <appDebugon.h>
#include <utilMatchFont.h>
#include <uniUtf8.h>
#include <textConverter.h>
#include <textConverterImpl.h>
#include "docRtfWriterImpl.h"
#include "docRtfFlags.h"
#include "docRtfTextConverter.h"
/************************************************************************/
/*									*/
/*  Emit a string to the RTF output stream.				*/
/*									*/
/************************************************************************/

static int docRtfEscapeChar(RtfWriter *rw, int c)
{
	SimpleOutputStream *sos = rw->rwSosOut;
	switch (c) {
	case '{':
	case '\\':
	case '}':
		if (sioOutPutByte('\\', sos) < 0) {
			LDEB(1);
			return -1;
		}
		if (sioOutPutByte(c, sos) < 0) {
			LDEB(1);
			return -1;
		}
		rw->rwCol += 2;
		break;
	default:
		if (c < 32 || c > 127) {
			static const char xdigs[] = "0123456789abcdef";

			if (sioOutPutByte('\\', sos) < 0) {
				LDEB(1);
				return -1;
			}
			if (sioOutPutByte('\'', sos) < 0) {
				LDEB(1);
				return -1;
			}
			if (sioOutPutByte(xdigs[(c >> 4) & 0x0f], sos) < 0) {
				LDEB(1);
				return -1;
			}
			if (sioOutPutByte(xdigs[(c >> 0) & 0x0f], sos) < 0) {
				LDEB(1);
				return -1;
			}
			rw->rwCol += 4;
		} else {
			if (sioOutPutByte(c, sos) < 0) {
				LDEB(1);
				return -1;
			}
			rw->rwCol += 1;
		}
		break;
	}

	return 0;
}

static int docRtfEscapeString(void *vrw, int produced, /* ignored */
			      const char *ss, int n)
{
	RtfWriter *rw = (RtfWriter *)vrw;
	const unsigned char *us = (const unsigned char *)ss;
	int i;
	int err;
	int addSpace = 0;

	if (n == 0) {
		return n;
	}

	switch (rw->rwcAfter) {
	case RTFafterTAG:
		if (ss[0] == ' ' || ss[0] == '-' || ss[0] == '_' ||
		    isalnum(ss[0])) {
			addSpace = 1;
		}
		break;

	case RTFafterARG:
		if (ss[0] == ' ' || isdigit(ss[0])) {
			addSpace = 1;
		}
		break;

	case RTFafterTEXT:
		break;

	default:
		CDEB(rw->rwcAfter);
		return -1;
	}

	if (addSpace) {
		if (sioOutPutByte(' ', rw->rwSosOut) < 0) {
			LDEB(1);
			return -1;
		}

		rw->rwCol += 1;
	}
	rw->rwcAfter = RTFafterTEXT;

	i = 0;
	while (i < n) {
		err = docRtfEscapeChar(rw, *us);
		if (err < 0)
			return err;
		i++;
		us++;
	}

	return n;
}

/************************************************************************/
/*									*/
/*  Emit a unicode (UTF-16) character as a tag.				*/
/*									*/
/************************************************************************/

static int docRtfEmitU16(RtfWriter *rw, int symbol)
{
	if (symbol > 32767 && symbol < 65536) {
		symbol -= 65536;
	}

	docRtfWriteArgTag(rw, "u", symbol);
	docRtfEscapeString((void *)rw, 0, "?", 1);

	return 0;
}

static int docRtfEmitU32(RtfWriter *rw, uint32_t symbol)
{
	int surrogate;
	char chr;
	if (symbol < 0x80) {
		chr = symbol & 0x7F;
		docRtfEscapeString(rw, 0, &chr, 1);
		return 0;
	} else if (symbol > 0x10000) {
		symbol -= 0x10000;
		surrogate = 0xD800 + (symbol >> 10);
		symbol = 0xDC00 + (symbol & 0x3FF);

		docRtfEmitU16(rw, surrogate);
	}

	docRtfEmitU16(rw, symbol);

	return 0;
}

/************************************************************************/
/*									*/
/*  Emit an utf-8 string in some legacy encoding.			*/
/*  The string might very well contain unicodes that cannot be		*/
/*  represented in the legacy encoding. The encoder stops on those	*/
/*  bytes and we emit them in \u1234 format.				*/
/*									*/
/************************************************************************/

static int docRtfWriteEncodedString(RtfWriter *rw, 
				    int fontEncoded, const char *ss, int n)
{
	int consumed = 0;

	while (n > 0) {
		unsigned short symbol;

		consumed = uniGetUtf8(&symbol, ss);
		if (consumed < 1) {
			LDEB(consumed);
			return -1;
		}

		docRtfEmitU32(rw, symbol);

		ss += consumed;
		n -= consumed;
	}

	return 0;
}

void docRtfWriteDocEncodedString(RtfWriter *rw, const char *ss, int n)
{
	docRtfWriteEncodedString(rw, 0, ss, n);
}

void docRtfWriteRawBytes(RtfWriter *rw, const char *ss, int n)
{
	docRtfEscapeString((void *)rw, 0, ss, n);
}

/************************************************************************/

void docRtfWriteSetupTextConverters(RtfWriter *rw)
{
	textConverterSetProduce(rw->rwTextTextConverter, docRtfEscapeString);
}
