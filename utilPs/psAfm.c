#include <config.h>

#include <string.h>

#include <sioGeneral.h>
#include "psFontInfo.h"
#include "psReadWriteFontInfo.h"

#include <appDebugon.h>

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
