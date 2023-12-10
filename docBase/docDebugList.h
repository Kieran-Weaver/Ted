/************************************************************************/
/*									*/
/*  Lists: Diagnostic routines.						*/
/*									*/
/************************************************************************/

#ifndef DOC_DEBUG_LIST_H
#define DOC_DEBUG_LIST_H

#include "docDocumentList.h"
#include "docListOverride.h"
#include "docListOverrideTable.h"
#include "docListTable.h"

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void docListDocumentList(int n, const DocumentList *dl);

void docListListOverrideLevel(int n, const ListOverrideLevel *lol);

void docListListOverrideTable(int n, const ListOverrideTable *lot);

void docListListOverride(int n, const ListOverride *lo);

void docListDocumentListTable(const DocumentListTable *dlt);

#endif /*	DOC_DEBUG_LIST_H	*/
