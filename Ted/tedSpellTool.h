/************************************************************************/
/*									*/
/*  Spell Tool.								*/
/*									*/
/************************************************************************/

#ifndef TED_SPELL_TOOL_H
#define TED_SPELL_TOOL_H

#include <appSpellTool.h>
#include <appFrame.h>
#include <docBuf.h>
#include <docSelectionDescription.h>

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void tedRefreshSpellTool(SpellTool *ast, int *pEnabled, int *pPref,
			 InspectorSubject *is, const DocumentSelection *ds,
			 const SelectionDescription *sd,
			 const BufferDocument *bd, int documentId,
			 const unsigned char *cmdEnabled);

void tedFillSpellTool(SpellTool *ast, const SpellToolResources *astr,
		      AppInspector *ai, int subjectPage, InspectorSubject *is,
		      APP_WIDGET pageWidget,
		      const InspectorSubjectResources *isr);

void tedFormatShowSpellPage(EditApplication *ea);

#endif /*  TED_SPELL_TOOL_H */
