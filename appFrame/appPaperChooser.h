#ifndef APP_PAPER_CHOOSER_H
#define APP_PAPER_CHOOSER_H

#include "guiOptionmenu.h"
#include <utilPropMask.h>
#include <utilDocumentGeometry.h>

/************************************************************************/
/*									*/
/*  A paper chooser to be embedded in another window.			*/
/*									*/
/************************************************************************/

struct PaperChooser;

typedef void (*PaperChooserCallback)(struct PaperChooser *pc, void *through,
				     const DocumentGeometry *dg);

typedef struct PaperChooser {
	APP_WIDGET pcFrame;
	APP_WIDGET pcVerticalColumn;

	AppOptionmenu pcOptionmenu;
	APP_WIDGET pcSizeText;

	APP_WIDGET pcOrientationRow;
	APP_WIDGET pcPortraitRadio;
	APP_WIDGET pcLandscapeRadio;

	int pcCustomPaperSize;
	int pcSizeChosen;
	int pcLandscapeChosen;
	DocumentGeometry pcGeometryChosen;

	int pcSizeOptionCount;
	APP_WIDGET *pcSizeOptions;

	int pcUnitType;

	PaperChooserCallback pcCallback;
	void *pcCallbackThrough;

	int pcProgrammatic;
} PaperChooser;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void appPaperChooserShowSize(PaperChooser *pc, int sizeChosen);

int appPaperChooserGetSize(PropertyMask *pUpdMask, PaperChooser *pc,
			   DocumentGeometry *dg);

void appPaperChooserFillMenu(PaperChooser *pc, const char *customLabel);

void appPaperChooserAdaptToGeometry(PaperChooser *pc,
				    const DocumentGeometry *dg);

void appMakePaperChooserWidgets(APP_WIDGET parent, const char *title,
				int unitType, PaperChooser *pc,
				PaperChooserCallback callback, void *through);

void appPaperChooserAddOrientationToggles(PaperChooser *pc,
					  const char *portrait,
					  const char *landscape);

void appInitPaperChooser(PaperChooser *pc);
void appCleanPaperChooser(PaperChooser *pc);

void appEnablePaperChooser(PaperChooser *pc, int enabled);

#endif /*  APP_PAPER_CHOOSER_H  */
