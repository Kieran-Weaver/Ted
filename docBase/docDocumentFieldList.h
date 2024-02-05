/************************************************************************/
/*									*/
/*  A list of fields.							*/
/*									*/
/************************************************************************/

#ifndef DOC_DOCUMENT_FIELD_LIST_H
#define DOC_DOCUMENT_FIELD_LIST_H

#include <utilPagedList.h>
typedef struct DocumentFieldList {
	PagedList dflPagedList;
} DocumentFieldList;

struct DocumentField;
struct SelectionScope;
struct EditPosition;
struct MemoryBuffer;

struct DocumentField *docGetFieldByNumber(const DocumentFieldList *dfl, int n);

void docDeleteFieldFromList(DocumentFieldList *dfl, struct DocumentField *df);

int docGetFieldKindByNumber(const DocumentFieldList *dfl, int n);

void docCleanFieldList(DocumentFieldList *dfl);
void docInitFieldList(DocumentFieldList *dfl);

int docSetPageOfField(DocumentFieldList *dfl, int n, int page);

struct DocumentField *docClaimField(DocumentFieldList *dfl);

struct DocumentField *docClaimFieldCopy(DocumentFieldList *dfl,
					const struct DocumentField *dfFrom,
					const struct SelectionScope *ss,
					const struct EditPosition *epStart);

int docFindBookmarkField(struct DocumentField **pDf,
			 const DocumentFieldList *dfl,
			 const struct MemoryBuffer *markName);

int docMakeBookmarkList(char ***pBookmarks, int *pBookmarkCount,
			int includeTocMarks, const DocumentFieldList *dfl);

#endif /*  DOC_DOCUMENT_FIELD_LIST_H  */
