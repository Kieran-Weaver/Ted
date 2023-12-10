/************************************************************************/
/*									*/
/*  Simple color chooser on an inspector page.				*/
/*									*/
/************************************************************************/

#ifndef APP_COLOR_CHOOSER_H
#define APP_COLOR_CHOOSER_H

#include <psPostScriptFontList.h>
#include <utilPropMask.h>
#include "appGuiBase.h"
#include "appDrawnPulldown.h"

struct ColorChooser;

typedef void (*ColorChooserCallback)(struct ColorChooser *cc, int which,
				     void *through, int choice,
				     const RGB8Color *rgb8);

typedef struct ColorChooserResources {
	char *ccrAutomaticColor;
	char *ccrMoreColors;
} ColorChooserResources;

typedef struct ColorChooserPaletteColor {
	RGB8Color ccpcRGB8Color;
	int ccpcStatus;
} ColorChooserPaletteColor;

#define CCstatusFREE 0
#define CCstatusSYSTEM 1
#define CCstatusPALETTE 2

typedef struct ColorChooser {
	unsigned char ccFilled;
	unsigned char ccEnabled;
	unsigned char ccVisible;
	unsigned char ccHasAutomatic;
	unsigned char ccColorExplicit;
	unsigned char ccColorSet;

	const ColorChooserResources *ccResources;
	const PostScriptFontList *ccPostScriptFontList;

	AppDrawnPulldown ccPulldown;
	RGB8Color ccPulldownBackgroundColor;
	APP_WIDGET ccLabelWidget;

	int ccInplaceScreenFont;
	int ccPulldownScreenFont;

	RGB8Color ccColorChosen;

	ColorChooserCallback ccCallback;
	void *ccTarget;
	int ccWhich;

	int ccStripHigh;
	int ccColumnWide;
	int ccStrips;
	int ccColumns;
	int ccXShift;

	ColorChooserPaletteColor *ccColors;
	int ccColorCount;
} ColorChooser;

typedef enum ColorChooserChoice {
	CHOICEccDEFAULT = 0,
	CHOICEccCOLOR,
	CHOICEccMORE,

	CHOICEcc_COUNT
} ColorChooserChoice;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void appColorChooserSetColor(ColorChooser *cc, int colorExplicit,
				    const RGB8Color *rgb8);

void appColorChooserUnset(ColorChooser *cc);

void appColorChooserSuggestPalette(ColorChooser *cc, int avoidZero,
					  const ColorPalette *cp);

void appInitColorChooser(ColorChooser *cc);
void appCleanColorChooser(ColorChooser *cc);

void appMakeColorChooserInRow(ColorChooser *cc, int hasAutomatic,
				     APP_WIDGET row, int col, int colspan,
				     const ColorChooserResources *ccr,
				     ColorChooserCallback colorCallback,
				     int which, void *through);

void appMakeToggleAndColorChooserRow(
	APP_WIDGET *pRow, APP_WIDGET *pToggle, ColorChooser *cc,
	int hasAutomatic, APP_WIDGET column, const char *toggleText,
	const ColorChooserResources *ccr, APP_TOGGLE_CALLBACK_T toggleCallback,
	ColorChooserCallback colorCallback, int which, void *through);

void appMakeLabelAndColorChooserRow(APP_WIDGET *pRow, APP_WIDGET *pLabel,
					   ColorChooser *cc, int hasAutomatic,
					   APP_WIDGET column,
					   const char *labelText,
					   const ColorChooserResources *ccr,
					   ColorChooserCallback callback,
					   int which, void *through);

void appFinishColorChooser(ColorChooser *cc,
				  const PostScriptFontList *psfl,
				  APP_WIDGET fontWidget);

void appColorChooserColorChosen(PropertyMask *isSetMask, int *pChanged,
				       RGB8Color *rgb8To, int *pExplicit,
				       const RGB8Color *rgb8Set,
				       int colorExplicit, int which);

void appEnableColorChooser(ColorChooser *cc, int enabled);

void appShowColorChooser(ColorChooser *cc, int visible);

#endif /*  APP_COLOR_CHOOSER_H */
