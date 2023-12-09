#include <config.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <sioGeneral.h>
#include "psFontInfo.h"
#include "psReadWriteFontInfo.h"

#include <appDebugon.h>

static void psAfmEmitStringProperty(SimpleOutputStream *sos,
				    const char *keyword, const char *val)
{
	if (!val) {
		return;
	}

	while (isspace(*val)) {
		val++;
	}
	if (!*val) {
		return;
	}

	/*  lines */
	while (*val) {
		int line = 254 - strlen(keyword);
		int left = line;

		sioOutPrintf(sos, "%s ", keyword);

		/*  words */
		while (*val) {
			const char *word = val;
			const char *past;
			int step;

			while (*word && !isspace(*word)) {
				word++;
			}
			past = word;
			while (*past && isspace(*past)) {
				past++;
			}

			step = past - val;
			/* fits with spaces */
			if (step < left) {
				sioOutPrintf(sos, "%.*s", step, val);
				left -= step;
				val = past;
				continue;
			}

			step = word - val;
			/* fits without spaces */
			if (step < left) {
				sioOutPrintf(sos, "%.*s", step, val);
				val = past;
			} else {
				/* does not fit. Can it fit? If not, emit what fits now */
				if (step > line) {
					sioOutPrintf(sos, "%.*s", left, val);
					val += left;
				}
			}

			sioOutPrintf(sos, "\n");
			keyword = "Comment";
			break;
		}
	}

	sioOutPrintf(sos, "\n");
	return;
}

static void psWriteCharMetric(SimpleOutputStream *sos, int c,
			      const AfmCharMetric *acm)
{
	sioOutPrintf(sos, "C %d ; WX %d ; N %s ; B %d %d %d %d ;\n", c,
		     acm->acmWX, acm->acmN, acm->acmBBox.drX0,
		     acm->acmBBox.drY0, acm->acmBBox.drX1, acm->acmBBox.drY1);

#if 0
    {
    int			i;
    const AfmCodeList *	acl= &(acm->acmUnicodeCodeList);

    for ( i= 0; i < acl->aclCodeCount; i++ )
	{ sioOutPrintf( sos, "Comment Unicode 0x%04X\n", acl->aclCodes[i] ); }
    }
#endif

	return;
}

static int psCountAfmMetrics(const AfmFontInfo *afi)
{
	int count = 0;
	int glyph;

	for (glyph = 0; glyph < afi->afiMetricCount; glyph++) {
		const AfmCharMetric *acm = afi->afiMetrics[glyph];
		const AfmCodeList *acl;

		if (!acm) {
			continue;
		}

		acl = &(acm->acmDefaultCodeList);

		if (acl->aclCodeCount == 0) {
			count++;
		} /*  -1		*/
		else {
			count += acl->aclCodeCount;
		} /*  Codes	*/
	}

	return count;
}

void psWriteFontInfoDict(SimpleOutputStream *sos, const AfmFontInfo *afi)
{
	sioOutPrintf(sos, "/FontInfo 10 dict dup begin\n");

	if (afi->afiFamilyName) {
		sioOutPrintf(sos, "/FamilyName (%s) readonly def\n",
			     afi->afiFamilyName);
	}

	if (afi->afiFullName) {
		sioOutPrintf(sos, "/FullName (%s) readonly def\n",
			     afi->afiFullName);
	}

	if (afi->afiNotice) {
		sioOutPrintf(sos, "/Notice (%s) readonly def\n",
			     afi->afiNotice);
	}

	if (afi->afiWeightStr) {
		sioOutPrintf(sos, "/Weight (%s) readonly def\n",
			     afi->afiWeightStr);
	}

	if (afi->afiVersion) {
		sioOutPrintf(sos, "/Version (%s) readonly def\n",
			     afi->afiVersion);
	}

	sioOutPrintf(sos, "/ItalicAngle %g def\n", afi->afiItalicAngle);

	sioOutPrintf(sos, "/isFixedPitch %s def\n",
		     afi->afiIsFixedPitch ? "true" : "false");

	sioOutPrintf(sos, "/UnderlinePosition %d def\n",
		     afi->afiUnderlinePosition);
	sioOutPrintf(sos, "/UnderlineThickness %d def\n",
		     afi->afiUnderlineThickness);

	sioOutPrintf(sos, "end readonly def\n");

	return;
}
