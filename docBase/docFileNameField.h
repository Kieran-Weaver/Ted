/************************************************************************/
/*									*/
/*  Bookkeeping for FILENAME fields.					*/
/*									*/
/************************************************************************/

#ifndef DOC_FILENAME_FIELD_H
#define DOC_FILENAME_FIELD_H

struct DocumentField;

typedef struct FileNameField {
	unsigned char fnfIncludePath; /* \p	*/
} FileNameField;

/************************************************************************/
/*									*/
/*  Administrative routines.						*/
/*									*/
/************************************************************************/

void docInitFileNameField(FileNameField *fnf);
void docCleanFileNameField(FileNameField *fnf);

int docGetFileNameField(FileNameField *fnf, const struct DocumentField *df);

#endif /*  DOC_FILENAME_FIELD_H  */
