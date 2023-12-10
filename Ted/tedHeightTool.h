/************************************************************************/
/*									*/
/*  Height tool:							*/
/*									*/
/************************************************************************/

#ifndef TED_HEIGHT_TOOL_H
#define TED_HEIGHT_TOOL_H

#include <appFrame.h>
#include <guiOptionmenu.h>

/************************************************************************/
/*									*/
/*  A combination of a pulldown menu and a text widget to manage a	*/
/*  height property.							*/
/*									*/
/************************************************************************/

typedef enum HeightSetting {
	HC_FREE = 0,
	HC_AT_LEAST,
	HC_EXACTLY,

	HC__COUNT
} HeightSetting;

typedef struct HeightChooser {
	APP_WIDGET hcRow;
	AppOptionmenu hcOptionmenu;
	APP_WIDGET hcText;

	APP_WIDGET hcMenuItems[HC__COUNT];
	unsigned char hcHow;
	unsigned char hcEnabled;
} HeightChooser;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void tedInitHeightChooser(HeightChooser *hc);

void tedFormatMakeHeightRow(void *through, APP_WIDGET parent,
				   HeightChooser *hc,
				   APP_TXACTIVATE_CALLBACK_T textCallback,
				   OptionmenuCallback menuCallback);

void tedFormatRefreshHeightChooser(HeightChooser *hc, int height);

void tedFormatEnableHeightChooser(HeightChooser *hc, int enabled);

void tedFormatHeightChosen(int how, HeightChooser *hc, int defaultValue);

void tedFormatFillHeightChooser(HeightChooser *hc, const char *freeText,
				       const char *atLeastText,
				       const char *exactlyText);

int tedFormatToolGetHeight(int *pHeight, HeightChooser *hc);

int tedHeightToolValidateDimension(int *pValue, int *pChanged,
					  const HeightChooser *hc, int orig);

#endif /*  TED_HEIGHT_TOOL_H */
