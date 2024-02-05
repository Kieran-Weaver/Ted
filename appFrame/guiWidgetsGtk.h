/************************************************************************/
/*									*/
/*  Basic structures for a Gui document manipulator application.	*/
/*									*/
/************************************************************************/

#ifndef GUI_WIDGETS_GTK_H
#define GUI_WIDGETS_GTK_H

#include "appGuiBase.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int appGuiGtkGetChildLabel(char **pLabel, APP_WIDGET w);

int appGuiGtkSetChildLabel(APP_WIDGET w, const char *s);

void appGuiGtkListTree(int indent, APP_WIDGET w);

#ifdef __cplusplus
}
#endif

#endif
