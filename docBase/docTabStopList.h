/************************************************************************/
/*									*/
/*  Tabs in a ruler.							*/
/*									*/
/************************************************************************/

#ifndef DOC_TAB_STOP_LIST_H
#define DOC_TAB_STOP_LIST_H

#include "docTabStop.h"
typedef struct TabStopList {
	TabStop *tslTabStops;
	short int tslTabStopCount;
} TabStopList;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void docInitTabStopList(TabStopList *tsl);
void docCleanTabStopList(TabStopList *tsl);

int docAddTabToListTwips(TabStopList *tsl, const TabStop *tsNew);

int docAddTabToListPixels(TabStopList *tsl, const TabStop *tsNew);

void docDeleteTabFromList(TabStopList *tsl, int n);

int docCopyTabStopList(TabStopList *to, const TabStopList *from);

int docNextTabStop(TabStop *pTs, int *pX, int *pTab, const TabStopList *tsl,
		   int x0Geometry, int x0TextLines, int tabInterval,
		   int xPosition);

int docRulerMergeTabs(TabStopList *tslTo, int x0GeometryPixels, double xfac,
		      const TabStopList *tslFrom);

#endif /*  DOC_TAB_STOP_LIST_H	*/
