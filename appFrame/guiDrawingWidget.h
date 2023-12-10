/************************************************************************/
/*									*/
/*  A widget in the screen GUI. (Implementation)			*/
/*									*/
/************************************************************************/

#include "appGuiBase.h"
#include <psPostScriptFontList.h>
#include <utilColor.h>

/************************************************************************/
/*									*/
/*  Routine Declarations.						*/
/*									*/
/************************************************************************/

void guiExposeDrawingWidget(APP_WIDGET nativeWidget);
void guiExposeDrawingWidgetRectangle(APP_WIDGET nativeWidget,
					    const DocumentRectangle *dr);

void guiCollectExposures(DocumentRectangle *drClip,
				APP_WIDGET nativeWidget,
				APP_EVENT *exposeEvent);

void guiGetForegroundColor(RGB8Color *rgb8, APP_WIDGET nativeWidget);

void guiGetBackgroundColor(RGB8Color *rgb8, APP_WIDGET nativeWidget);

void guiGetTopShadowColor(RGB8Color *rgb8, APP_WIDGET nativeWidget);

void guiGetBottomShadowColor(RGB8Color *rgb8, APP_WIDGET nativeWidget);

int guiDrawGetSizeOfWidget(int *pWide, int *pHigh, APP_WIDGET w);

int guiDrawGetSizeFromConfigureEvent(int *pWide, int *pHigh,
					    APP_WIDGET w, APP_EVENT *event);

int guiGetCoordinatesFromMouseButtonEvent(int *pX, int *pY, int *pButton,
						 int *pUpDown, int *pSeq,
						 unsigned int *pKeyState,
						 const APP_WIDGET w,
						 const APP_EVENT *event);

int guiGetCoordinatesRelativeToWidget(int *pX, int *pY,
					     const APP_WIDGET w);

int guiGetCoordinatesFromMouseMoveEvent(int *pX, int *pY, APP_WIDGET w,
					       APP_EVENT *event);

void guiDrawSetRedrawHandler(APP_WIDGET w, APP_EVENT_HANDLER_T handler,
				    void *through);

void guiDrawSetConfigureHandler(APP_WIDGET w,
				       APP_EVENT_HANDLER_T handler,
				       void *through);

void guiDrawSetButtonPressHandler(APP_WIDGET w,
					 APP_EVENT_HANDLER_T handler,
					 void *through);

void guiDrawSetScrollHandler(APP_WIDGET w, APP_EVENT_HANDLER_T handler,
				    void *through);

int guiDrawGetInoutFromFocusEvent(int *pInOut, APP_WIDGET w,
					 APP_EVENT *event);
