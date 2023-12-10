/************************************************************************/
/*									*/
/*  Format tool:							*/
/*									*/
/************************************************************************/

#ifndef TED_TOOL_FRONT_H
#define TED_TOOL_FRONT_H

#include <appFrame.h>
#include <appInspector.h>
#include <docSelect.h>
#include <docDocumentTree.h>
#include <docSelectionGeometry.h>
#include <docSelectionDescription.h>

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void tedFormatToolAdaptToSelection(AppInspector *ai, EditDocument *ed,
					  int choosePage, DocumentTree *ei,
					  const DocumentSelection *ds,
					  const SelectionGeometry *sg,
					  const SelectionDescription *sd,
					  const unsigned char *cmdEnabled);

void tedFormatShowPagePage(EditApplication *ea);
void tedFormatShowFontPage(EditApplication *ea);
void tedFormatShowSymbolPage(EditApplication *ea);
void tedFormatShowLinkPage(EditApplication *ea);
void tedFormatShowBookmarkPage(EditApplication *ea);

void tedFormatShowParaLayoutPage(EditApplication *ea);
void tedFormatShowParaTabsPage(EditApplication *ea);
void tedFormatShowColumnPage(EditApplication *ea);
void tedFormatShowTablePage(EditApplication *ea);

void tedShowFormatTool(APP_WIDGET toolOption, EditApplication *ea);

void tedFormatFieldListChanged(EditApplication *ea);

#endif /*  TED_TOOL_FRONT_H */
