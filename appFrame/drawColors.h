#ifndef DRAW_COLORS_H
#define DRAW_COLORS_H

#include "appGuiBase.h"

#include <bmcolor.h>

#ifdef __cplusplus
"C" {
#endif

/************************************************************************/
/*									*/
/*  Administration on colors.						*/
/*									*/
/************************************************************************/

typedef struct AppColors {
	ColorAllocator acAllocator;


	GdkColormap *acColormap;
	int acVisualClass;
} AppColors;

/************************************************************************/
/*									*/
/*  Procedure declarations.						*/
/*									*/
/************************************************************************/

void appInitColors(AppColors *ac);

int appColorRgb(APP_COLOR_RGB *xc, AppColors *ac, unsigned int r,
		       unsigned int g, unsigned int b);

int appColorFindRgb(APP_COLOR_RGB *xc, AppColors *ac, unsigned int r,
			   unsigned int g, unsigned int b);

int appColorNamed(APP_COLOR_RGB *xc, AppColors *ac, const char *name);

#ifdef __cplusplus
}
#endif

#endif /*  DRAW_COLORS_H	*/
