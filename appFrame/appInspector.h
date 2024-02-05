/************************************************************************/
/*									*/
/*  Application inspector with different subject pages.			*/
/*									*/
/************************************************************************/

#ifndef APP_INSPECTOR_H
#define APP_INSPECTOR_H

#include <stdio.h>
#include "appGuiBase.h"
#include "appFrame.h"
#include "appTool.h"
#include "guiOptionmenu.h"
/************************************************************************/
/*									*/
/*  Facilities to make property inspectors.				*/
/*									*/
/************************************************************************/

struct AppInspector;

typedef void (*InspectorSubjectGotColor)(void *through, int property,
					 const RGB8Color *rgb8);

typedef void (*InspectorNotifySubject)(struct AppInspector *ai, int from,
				       int to);

typedef struct InspectorSubject {
	APP_WIDGET isPage;
	APP_WIDGET isMenuitem;
	void *isPrivate;
	int isEnabled;

	APP_WIDGET isNextPrevRow;
	APP_WIDGET isPrevButton;
	APP_WIDGET isNextButton;

	APP_WIDGET isMoveUpButton;
	APP_WIDGET isMoveDownButton;

	APP_WIDGET isSelectButton;
	APP_WIDGET isDeleteButton;

	APP_WIDGET isInsertButton;
	APP_WIDGET isAppendButton;

	APP_WIDGET isApplyRow;
	APP_WIDGET isRevertButton;
	APP_WIDGET isApplyButton;

	InspectorSubjectGotColor isGotColor;
} InspectorSubject;

typedef struct AppInspector {
	struct EditApplication *aiApplication;

	APP_WIDGET aiTopWidget;
	APP_WIDGET aiPaned;

	AppOptionmenu aiSubjectOptionmenu;

	APP_WIDGET aiSeparator;
	APP_WIDGET aiPageParent;
	APP_WIDGET aiSeparator2;

	APP_WIDGET aiCloseButton;

	InspectorNotifySubject aiNotifySubject;

	void *aiRgbChooser; /*  RgbChooserPage */
	int aiRgbSubjectNumber;

	AppToolDestroy aiDestroy;
	void *aiTarget;

	int aiSubjectCount;
	int aiCurrentSubject;

	InspectorSubject *aiSubjects;
} AppInspector;

typedef struct AppInspectorResources {
	char *airCloseText;
} AppInspectorResources;

typedef struct InspectorSubjectResources {
	const char *isrSubjectName;
	const char *isrApplyToSubject;
	const char *isrRevert;

	const char *isrNextButtonText;
	const char *isrPrevButtonText;

	const char *isrMoveDownButtonText;
	const char *isrMoveUpButtonText;

	const char *isrSelectButtonText;
	const char *isrDeleteButtonText;

	const char *isrInsertButtonText;
	const char *isrAppendButtonText;
} InspectorSubjectResources;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void appInspectorSelectSubject(AppInspector *ai, int subject);

void appFinishInspector(AppInspector *ai);

void appEnableInspector(AppInspector *ai, int enabled);

void appEnableInspectorSubject(AppInspector *ai, int subject, int enabled);

void appInspectorGotColor(AppInspector *ai, int subjectPage, int property,
			  const RGB8Color *rgb8);

void appInspectorShowRgbPage(AppInspector *ai, int fromSubject,
			     int fromProperty, const RGB8Color *rgb8);

void appInspectorSetRgbPage(AppInspector *ai, void *vrcp, int subject);

int appInspectorAddSubject(AppInspector *ai,
			   const InspectorSubjectResources *isr);

void appInspectorDeleteSubject(AppInspector *ai, int subject);

void appInspectorPageChosen(int subject, void *vai);

void appInspectorChoosePage(AppInspector *ai, int andMenu, int pageNumber);

AppInspector *appMakeInspector(EditApplication *ea, APP_WIDGET option,
			       InspectorSubjectResources *isr, int subjectCount,
			       AppToolDestroy closeInspector, void *through);

void appInspectorMakePageParent(AppInspector *ai);

int appMakeVerticalInspectorPage(APP_WIDGET *pPage, APP_WIDGET *pMenuitem,
				 AppInspector *ai, const char *label);

void appInspectorEnablePage(AppInspector *ai, int pageNumber, int enabled);

#endif
