/************************************************************************/
/*									*/
/*  Intermediary Routines for the page layout page.			*/
/*									*/
/************************************************************************/

#ifndef TED_PAGE_LAYOUT_TOOL_H
#define TED_PAGE_LAYOUT_TOOL_H

#include <appPageLayoutTool.h>
#include <docBuf.h>
#include <docSelectionDescription.h>

/************************************************************************/
/*									*/
/*  Routine Declarations.						*/
/*									*/
/************************************************************************/

void tedRefreshPageLayoutTool(PageLayoutTool *plt, int *pEnabled,
				     int *pPref, InspectorSubject *is,
				     const DocumentSelection *ds,
				     const SelectionDescription *sd,
				     const BufferDocument *bd,
				     const unsigned char *cmdEnabled);

void tedFormatCleanPageLayoutTool(PageLayoutTool *plt);

void tedFormatFinishPageLayoutPage(PageLayoutTool *plt,
					  const PageLayoutPageResources *plpr);

void tedFormatFillPageLayoutPage(PageLayoutTool *plt,
					const PageLayoutPageResources *plpr,
					InspectorSubject *is,
					APP_WIDGET pageWidget,
					const InspectorSubjectResources *isr);

#endif /*  TED_PAGE_LAYOUT_TOOL_H */
