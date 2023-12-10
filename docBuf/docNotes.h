/************************************************************************/
/*									*/
/*  Text Editor Buffer structure.					*/
/*									*/
/************************************************************************/

#ifndef DOC_NOTES_H
#define DOC_NOTES_H

/************************************************************************/
/*									*/
/*  Forward declarations of structs.					*/
/*									*/
/************************************************************************/

struct DocumentNote;
struct BufferDocument;
struct BufferItem;
struct DocumentField;
struct TextLine;
struct TextParticule;
struct DocumentSelection;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int docInsertNote(struct DocumentNote **pDn, struct BufferDocument *bd,
			 struct DocumentField *dfNote, int autoNumber);

struct DocumentField *
docGetSelectedNote(struct DocumentNote **pDn, int *pSelInNote,
		   struct BufferDocument *bd,
		   const struct DocumentSelection *ds);

void docCleanNote(struct BufferDocument *bd, struct DocumentNote *dn);

struct DocumentField *
docGetFirstNoteFromColumn(struct DocumentNote **pDn,
			  const struct BufferDocument *bd, int page, int column,
			  int treeType);

struct DocumentField *
docGetFirstNoteInColumn(struct DocumentNote **pDn,
			const struct BufferDocument *bd, int page, int column,
			int treeType);

struct DocumentField *
docGetLastNoteInColumn(struct DocumentNote **pDn,
		       const struct BufferDocument *bd, int page, int column,
		       int treeType);

struct DocumentField *
docGetFirstNoteOnPage(struct DocumentNote **pDn,
		      const struct BufferDocument *bd, int page, int treeType);

struct DocumentField *
docGetFirstNoteOfSection(struct DocumentNote **pDn,
			 const struct BufferDocument *bd, int sect,
			 int treeType);

struct DocumentField *
docGetFirstNoteOfDocument(struct DocumentNote **pDn,
			  const struct BufferDocument *bd, int treeType);

struct DocumentField *
docGetLastNoteOfDocument(struct DocumentNote **pDn,
			 const struct BufferDocument *bd, int treeType);

struct DocumentField *
docGetNextNoteInSection(struct DocumentNote **pDn,
			const struct BufferDocument *bd, int sect,
			struct DocumentField *df, int treeType);

struct DocumentField *
docGetNextNoteInDocument(struct DocumentNote **pDn,
			 const struct BufferDocument *bd,
			 struct DocumentField *df, int treeType);

struct DocumentField *
docGetPrevNoteInDocument(struct DocumentNote **pDn,
			 const struct BufferDocument *bd,
			 struct DocumentField *df, int treeType);

struct DocumentNote *
docGetNoteOfField(const struct DocumentField *dfNote,
		  const struct BufferDocument *bd);

#endif
