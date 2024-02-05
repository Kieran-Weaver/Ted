/************************************************************************/
/*									*/
/*  Administration of the lists in a document.				*/
/*									*/
/*  Refer to page 21 of the RTF 1.7 document.				*/
/*									*/
/************************************************************************/

#ifndef DOC_LIST_ADMIN_H
#define DOC_LIST_ADMIN_H

#include "docListTable.h"
#include "docListOverrideTable.h"

struct ListLevel;

typedef struct ListAdmin {
	DocumentListTable laListTable;
	ListOverrideTable laListOverrideTable;
} ListAdmin;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void docInitListAdmin(ListAdmin *la);
void docCleanListAdmin(ListAdmin *la);

int docCopyListAdmin(ListAdmin *to, const ListAdmin *from);

int docMakeOverrideForEveryList(ListAdmin *la);

int docMergeListAdmins(ListAdmin *laTo, const ListAdmin *laFrom,
		       const int *lsUsed, int *lsMap, const int *listUsed,
		       const int *fontMap, const int *colorMap,
		       const int *rulerMap);

int docGetListForStyle(struct ListOverride **pLo, struct DocumentList **pDl,
		       int ls, const ListAdmin *la);

int docGetListOfOverride(struct ListOverride *lo, const DocumentListTable *dlt);

int docListGetFormatPath(int *startPath, int *formatPath,
			 const struct ListLevel **pLl, int ilvl,
			 const struct DocumentList *dl,
			 const struct ListOverride *lo);

#endif
