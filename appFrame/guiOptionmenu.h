/************************************************************************/
/*									*/
/*  Option menus.							*/
/*									*/
/************************************************************************/

#include "appGuiBase.h"

#ifndef GUI_OPTMENU_H
#define GUI_OPTMENU_H

typedef void (*OptionmenuCallback)(int n, void *through);


typedef struct AppOptionmenu {
	APP_WIDGET aomInplace;
	APP_WIDGET aomPulldown;

	OptionmenuCallback aomCallback;
	void *aomTarget;
} AppOptionmenu;



/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void appMakeOptionmenuInColumn(AppOptionmenu *aom, APP_WIDGET parent,
				      OptionmenuCallback callBack,
				      void *through);

void appMakeOptionmenuInRow(AppOptionmenu *aom, APP_WIDGET row,
				   int column, int colspan,
				   OptionmenuCallback callBack, void *through);

void appEmptyOptionmenu(AppOptionmenu *aom);

void appGuiEnableOptionmenu(AppOptionmenu *aom, int sensitive);

APP_WIDGET appAddItemToOptionmenu(AppOptionmenu *aom, const char *label);

void appDeleteItemFromOptionmenu(AppOptionmenu *aom, APP_WIDGET item);

void appSetOptionmenu(AppOptionmenu *aom, int num);

void appInitOptionmenu(AppOptionmenu *aom);

void appOptionmenuItemSetVisibility(APP_WIDGET w, int visible);

#endif /* GUI_OPTMENU_H */
