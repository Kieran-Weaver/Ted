/************************************************************************/
/*									*/
/*  Exchange values with a text widget.					*/
/*									*/
/************************************************************************/

#ifndef GUI_TEXT_UTIL_H
#define GUI_TEXT_UTIL_H

#include <stdio.h>
#include "appGuiBase.h"
#include <utilMemoryBuffer.h>
#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int appGetLengthFromTextWidget(APP_WIDGET w, int *pValue, int *pChanged,
			       int defaultUnit, int minValue, int adaptToMin,
			       int maxValue, int adaptToMax);

int appGetIntegerFromTextWidget(APP_WIDGET w, int *pValue, int minValue,
				int adaptToMin, int maxValue, int adaptToMax);

int appGetDoubleFromTextWidget(APP_WIDGET w, double *pValue, double minValue,
			       int adaptToMin, double maxValue, int adaptToMax);

void appIntegerToTextWidget(APP_WIDGET w, int n);

void appIntervalToTextWidget(APP_WIDGET w, int n1, int n2);

void appRectangleToTextWidget(APP_WIDGET w, int row1, int row2, int col1,
			      int col2);

void appDoubleToTextWidget(APP_WIDGET w, double d);

void appLengthToTextWidget(APP_WIDGET w, int l, int unit);

int appBufferFromTextWidget(MemoryBuffer *mb, APP_WIDGET w);

void guiBufferToText(APP_WIDGET w, const MemoryBuffer *mb);

#ifdef __cplusplus
}
#endif

#endif
