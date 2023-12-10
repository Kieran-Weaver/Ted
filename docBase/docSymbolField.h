/************************************************************************/
/*									*/
/*  Bookkeeping for SYMBOL fields.					*/
/*									*/
/************************************************************************/

#ifndef DOC_SYMBOL_FIELD_H
#define DOC_SYMBOL_FIELD_H

struct DocumentField;

#include <utilMemoryBuffer.h>

typedef enum SymbolFieldEncoding {
	SYMBOLencANSI = 0,
	SYMBOLencUNICODE,
	SYMBOLencSHIFT_JIS,

	SYMBOLenc_COUNT
} SymbolFieldEncoding;

typedef struct SymbolField {
	MemoryBuffer sfFontName;
	int sfSymbol;
	int sfSizePoints;
	int sfEncoding;
	int sfIsHigh;
} SymbolField;

/************************************************************************/
/*									*/
/*  Administrative routines.						*/
/*									*/
/************************************************************************/

void docInitSymbolField(SymbolField *sf);
void docCleanSymbolField(SymbolField *sf);

int docFieldGetSymbol(SymbolField *sf, const struct DocumentField *df);

#endif /*  DOC_SYMBOL_FIELD_H  */
