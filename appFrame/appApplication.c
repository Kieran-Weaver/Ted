/************************************************************************/
/*									*/
/*  Application window application independent functionality.		*/
/*									*/
/************************************************************************/

#include <config.h>

#include <stddef.h>
#include <stdio.h>

#include <utilFontmap.h>
#include "appFrame.h"
#include "appMatchFont.h"

#include <appDebugon.h>

/************************************************************************/
/*									*/
/*  Collect a list of fonts through fontconfig.                 	*/
/*									*/
/************************************************************************/

int appPostScriptFontCatalog(EditApplication *ea)
{
	int rval = 0;

	if (ea->eaPostScriptFontList.psflFamilyCount > 0) {
		goto ready;
	}

#ifdef USE_FONTCONFIG
	ea->eaPostScriptFontList.psflAvoidFontconfig =
		ea->eaAvoidFontconfigInt > 0;

	if (!ea->eaPostScriptFontList.psflAvoidFontconfig) {
		appFcListFonts(&(ea->eaPostScriptFontList));

		if (ea->eaPostScriptFontList.psflFamilyCount > 0) {
			goto ready;
		}
	}
#else
	ea->eaPostScriptFontList.psflAvoidFontconfig = 1;
#endif

	if (ea->eaGhostscriptFontmap && !ea->eaGhostscriptMappingsRead) {
		if (utilFontmapReadMap(ea->eaGhostscriptFontmap)) {
			SDEB(ea->eaGhostscriptFontmap);
			rval = -1;
			goto ready;
		}

		ea->eaGhostscriptMappingsRead = 1;
	}

ready:

	return rval;
}

/************************************************************************/
/*									*/
/*  Collect a list of printers.						*/
/*									*/
/************************************************************************/

int appGetPrintDestinations(EditApplication *ea)
{
	if (ea->eaPrintDestinationsCollected) {
		return 0;
	}

	ea->eaPrintDestinationsCollected = 1;

	if (utilPrinterGetPrinters(
		    &(ea->eaPrintDestinationCount),
		    &(ea->eaDefaultPrintDestination),
		    &(ea->eaPrintDestinations), ea->eaCustomPrintCommand,
		    ea->eaCustomPrinterName, ea->eaCustomPrintCommand2,
		    ea->eaCustomPrinterName2)) {
		LDEB(1);
		return -1;
	}

	return 0;
}
