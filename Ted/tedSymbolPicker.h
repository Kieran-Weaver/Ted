/************************************************************************/
/*									*/
/*  Symbol Picker:							*/
/*									*/
/************************************************************************/

#ifndef TED_SYMBOL_PICKER_H
#define TED_SYMBOL_PICKER_H

#include <appSymbolPicker.h>
#include <docSelect.h>
#include <docSelectionDescription.h>
#include <docBuf.h>

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void tedRefreshSymbolPicker(SymbolPicker *sp, int *pEnabled, int *pPref,
				   InspectorSubject *is,
				   const DocumentSelection *ds,
				   const SelectionDescription *sd,
				   const BufferDocument *bd, int documentId,
				   const unsigned char *cmdEnabled);

void tedSymbolPickerInsert(void *voidea, const char *bytes, int size,
				  const TextAttribute *taSet,
				  const PropertyMask *taSetMask);

#endif /*  TED_SYMBOL_PICKER_H */
