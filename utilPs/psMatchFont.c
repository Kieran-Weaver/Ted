/************************************************************************/
/*									*/
/*  Mapping between Document fonts and PostScript fonts.		*/
/*									*/
/************************************************************************/

#include <config.h>
#include <string.h>
#include <limits.h>
#include <appDebugon.h>
#include "psFontFamily.h"
#include "psDocumentFontStyle.h"
#include "psPostScriptFontList.h"
#include "textAttribute.h"

/************************************************************************/
/*									*/
/*  An half hearted attempt to derive the font style from the family	*/
/*  name.								*/
/*									*/
/************************************************************************/

int psFontFamilyStyle(const char *fontFamilyName)
{
	int l = strlen(fontFamilyName);

	while (l > 0) {
		int past = -1;
		int i;

		if (l == 5 && !strncmp(fontFamilyName, "Arial", 5)) {
			return DFstyleFSWISS;
		}

		if (l == 9 && !strncmp(fontFamilyName, "Helvetica", 9)) {
			return DFstyleFSWISS;
		}

		if (l == 5 && !strncmp(fontFamilyName, "Times", 5)) {
			return DFstyleFROMAN;
		}

		if (l == 8 && !strncmp(fontFamilyName, "Palatino", 8)) {
			return DFstyleFROMAN;
		}

		if (l == 6 && !strncmp(fontFamilyName, "Symbol", 6)) {
			return DFstyleFTECH;
		}

		if (l == 7 && !strncmp(fontFamilyName, "Courier", 7)) {
			return DFstyleFMODERN;
		}

		if (l == 5 && !strncmp(fontFamilyName, "Ohlfs", 5)) {
			return DFstyleFMODERN;
		}

		if (l == 9 && !strncmp(fontFamilyName, "Wingdings", 9)) {
			return DFstyleFTECH;
		}
		if (l == 8 && !strncmp(fontFamilyName, "Webdings", 8)) {
			return DFstyleFTECH;
		}

		if (l == 7 && !strncmp(fontFamilyName, "Corsiva", 7)) {
			return DFstyleFSCRIPT;
		}

		for (i = 0; i < l - 1; i++) {
			if (fontFamilyName[i] != ' ' &&
			    fontFamilyName[i + 1] == ' ') {
				past = i + 1;
			}
		}
		if (past <= 0) {
			break;
		}
		l = past;

		for (i = 0; i < l; i++) {
			if (fontFamilyName[i] != ' ') {
				past = i + 1;
			}
		}
		l = past;
	}

	return DFstyleFNIL;
}

