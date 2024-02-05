/************************************************************************/
/*									*/
/*  Text color, border and shading tool:				*/
/*									*/
/************************************************************************/

#ifndef TED_TEXT_ORNAMENTS_TOOL_H
#define TED_TEXT_ORNAMENTS_TOOL_H

#include "tedBorderTool.h"
#include "tedShadingTool.h"
#include <docExpandedTextAttribute.h>
#include <appFontTool.h>
#include <docSelectionDescription.h>
#include <docSelectionGeometry.h>

/************************************************************************/
/*									*/
/*  Resources for the text colors and borders tool.			*/
/*									*/
/************************************************************************/

typedef struct TextOrnamentsPageResources {
	char *totrTextColor;
	char *totrTextBorder;
	char *totrTextShading;

	ColorChooserResources totrTextColorChooserResources;
	ShadingToolResources totrShadingResources;
	BorderToolResources totrBorderToolResources;
} TextOrnamentsPageResources;

/************************************************************************/
/*									*/
/*  A text color tool, i.e. the 'Text Colors' page of the format tool.	*/
/*									*/
/************************************************************************/

typedef struct TextOrnamentsTool {
	EditApplication *totApplication;
	AppInspector *totInspector;
	int totSubjectPage;
	unsigned int totCurrentDocumentId;
	const TextOrnamentsPageResources *totPageResources;
	FontChooserSetFont totSetFont;

	unsigned char totCanChange;
	unsigned char totIsListBullet;

	PropertyMask totSetMask;
	ExpandedTextAttribute totAttributeSet;
	PropertyMask totChosenMask;
	ExpandedTextAttribute totAttributeChosen;

	APP_WIDGET totColorRow;
	APP_WIDGET totTextColorToggle;
	ColorChooser totTextColorChooser;

	BorderTool totBorderTool;
	ShadingTool totShadingTool;

	APP_WIDGET totSetButton;
} TextOrnamentsTool;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void tedFormatToolGetTextOrnamentsResourceTable(EditApplication *ea,
						TextOrnamentsPageResources *plpr,
						InspectorSubjectResources *isr);

void tedFormatFillTextOrnamentsChoosers(TextOrnamentsTool *tot,
					const TextOrnamentsPageResources *totr);

void tedFormatFillTextOrnamentsPage(TextOrnamentsTool *tot,
				    const TextOrnamentsPageResources *totr,
				    AppInspector *ai, int subjectPage,
				    InspectorSubject *is, APP_WIDGET pgW,
				    const InspectorSubjectResources *isr);

void tedRefreshTextOrnamentsTool(TextOrnamentsTool *tot, int *pEnabled,
				 int *pPref, InspectorSubject *is,
				 EditDocument *ed, const DocumentSelection *ds,
				 const SelectionGeometry *sg,
				 const SelectionDescription *sd,
				 const unsigned char *cmdEnabled);

void tedInitTextOrnamentsTool(TextOrnamentsTool *tot);
void tedCleanTextOrnamentsTool(TextOrnamentsTool *tot);

void tedFinishTextOrnamentsPage(TextOrnamentsTool *pot,
				const TextOrnamentsPageResources *popr);

#endif /*  TED_PARA_ORNAMENTS_TOOL_H */
