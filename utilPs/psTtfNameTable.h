#include <sioGeneral.h>
#include "psTtfTableEntry.h"

typedef struct TrueTypeNameRecord {
	unsigned int ttnrPlatformID; /*  1  */
	unsigned int ttnrEncodingID; /*  2  */
	unsigned int ttnrLanguageID;
	unsigned int ttnrNameID;
	unsigned int ttnrLength;
	unsigned int ttnrOffset;

	unsigned char *ttnrSavedBytes;
} TrueTypeNameRecord;

typedef struct TrueTypeNameTable {
	unsigned int ttntFormat;
	unsigned int ttntRecordCount;
	unsigned int ttntOffset;

	TrueTypeNameRecord *ttntRecords;
} TrueTypeNameTable;

void psTtfInitTrueTypeNameRecord(TrueTypeNameRecord *ttnr);
void psTtfCleanTrueTypeNameRecord(TrueTypeNameRecord *ttnr);
void psTtfInitTrueTypeNameTable(TrueTypeNameTable *ttnt);
void psTtfCleanTrueTypeNameTable(TrueTypeNameTable *ttnt);

int psTtfExtractNameRecords(SimpleInputStream *sisName,
				   const TrueTypeTableEntry *ttte,
				   TrueTypeNameTable *ttnt);

int psTtfGetName(char **pName, const TrueTypeNameTable *ttnt, int which);
