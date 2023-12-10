/************************************************************************/
/*									*/
/*  List table of a document.						*/
/*									*/
/************************************************************************/

#ifndef DOC_LIST_OVERRIDE_TABLE_H
#define DOC_LIST_OVERRIDE_TABLE_H

struct ListOverride;

typedef struct ListOverrideTable {
	struct ListOverride *lotOverrides;
	int lotOverrideCount;
} ListOverrideTable;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void docInitListOverrideTable(ListOverrideTable *lot);
void docCleanListOverrideTable(ListOverrideTable *lot);

int docCopyListOverrideTable(ListOverrideTable *to,
				    const ListOverrideTable *from);

int docListOverrideTableAddOverride(struct ListOverride **pLo,
					   ListOverrideTable *lot, int ls,
					   int listId, int listIndex);

int docListOverrideTableSetOverride(ListOverrideTable *lot,
					   const struct ListOverride *lo,
					   const int *fontMap,
					   const int *colorMap,
					   const int *rulerMap);

int docMergeListOverrideIntoTable(ListOverrideTable *lot,
					 const struct ListOverride *lo,
					 const int *fontMap,
					 const int *colorMap,
					 const int *rulerMap);

int docListOverrideTableDeleteOverride(ListOverrideTable *lot, int ls);

#endif
