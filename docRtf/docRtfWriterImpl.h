/************************************************************************/
/*									*/
/*  Writing RTF.							*/
/*									*/
/************************************************************************/

#ifndef RTF_WRITER_IMPL_H
#define RTF_WRITER_IMPL_H

#include <docBuf.h>
#include <sioGeneral.h>
#include "docRtfWriter.h"

struct TabStopList;

/************************************************************************/
/*									*/
/*  The writer.								*/
/*									*/
/************************************************************************/

typedef struct PushedAttribute {
	struct PushedAttribute *paNext;
	TextAttribute paTextAttribute;
	int paTextCharset;
} PushedAttribute;

struct RtfWriter {
	struct BufferDocument *rwDocument;
	/**
				 *  The current text attribute. The state of 
				 *  the writer is also determined by the charset
				 *  of the current text, as the RTF file format 
				 *  includes the charset of the text in the 
				 *  identity of the font.
				 */
	TextAttribute rwTextAttribute;
	/**
				 *  The rtf charset of the current text attribute.
				 *  This is needed as the RTF file format 
				 *  represents text with 8-bit characters belonging
				 *  to different fonts if there are too many 
				 *  different characters in the font.
				 */
	int rwTextCharset;
	ParagraphProperties rwcParagraphProperties;
	RowProperties rwRowProperties;

	ParagraphProperties rwcOutsideTableParagraphProperties;

	PagedList rwcEncodedFontList;

	PushedAttribute *rwcPushedAttribute;
	int rwcInFldrslt;
	/**
				  *  The current depth of table nesting:
				  *  0: outside tables, 1: In table,
				  *  2+: in a nested table.
				  */
	int rwTableNesting;
	/**
				  *  The deepest depth of table nesting:
				  *  If the value >1, Ted will emit 
				  *  itap tags along with intbl tags.
				  *  This is because itap tags confuse wordpad.
				  */
	int rwDeepestTableNesting;

	/**
				  *  While writing a selection, it is not 
				  *  obvious that the section properties 
				  *  are saved: If the selection is contained 
				  *  in a single child of the section, we 
				  *  start in that child. So we never actually 
				  *  enter the section node.
				  */
	int rwSectionPropertiesSaved;

	int rwcAfter;
#define RTFafterTAG 'T'
#define RTFafterARG '0'
#define RTFafterTEXT '*'
	int rwcLastNodeLevel;

	int rwSaveFlags;

	int rwCol;
	SimpleOutputStream *rwSosOut;

	/**
				 * Used for RTF conversions. I.E where 
				 * no font applies
				 */
	struct TextConverter *rwRtfTextConverter;
	/**
				 * Used for Text conversions. I.E where 
				 * a font applies
				 */
	struct TextConverter *rwTextTextConverter;

	const PropertyMask *rwPpExtraMask;
	const PropertyMask *rwCpExtraMask;
	const PropertyMask *rwRpExtraMask;
	const PropertyMask *rwSpExtraMask;
};

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int docRtfWriteArgTag(RtfWriter *rwc, const char *tag, int arg);

void docRtfWriteFlagTag(RtfWriter *rwc, const char *tag, int arg);

void docRtfWriteAltTag(RtfWriter *rwc, const char *yesTag, const char *noTag,
		       int arg);

void docRtfWriteEnumTag(RtfWriter *rwc, const char *const *tags, int arg,
			int tagCount, int enumCount);

int docRtfWriteTag(RtfWriter *rwc, const char *tag);

void docRtfWriteDocEncodedString(RtfWriter *rwc, const char *s, int n);

void docRtfWriteRawBytes(RtfWriter *rwc, const char *s, int n);

void docRtfWriteDocEncodedStringDestination(RtfWriter *rwc, const char *tag,
					    const char *s, int n,
					    int addSemicolon);

void docRtfWriteRawBytesDestination(RtfWriter *rwc, const char *tag,
				    const char *s, int n);

void docRtfWriteNextLine(RtfWriter *rwc);

void docRtfSaveBorderByNumber(RtfWriter *rwc, const char *tag, int num,
			      int anywy);

void docRtfSaveTextAttribute(RtfWriter *rwc, const PropertyMask *updMask,
			     const TextAttribute *ta);

void docRtfSaveParagraphProperties(RtfWriter *rwc, const PropertyMask *updMask,
				   const ParagraphProperties *pp);

int docRtfWriteDestinationBegin(RtfWriter *rwc, const char *tag);

int docRtfWriteDestinationEnd(RtfWriter *rwc);

int docRtfSavePictureTags(RtfWriter *rwc, const PropertyMask *pipSetMask,
			  const PictureProperties *pipSet);

int docRtfPicturePropertyMask(PropertyMask *pipSetMask,
			      const PictureProperties *pipSet);

int docRtfWriteMemoryBuffer(RtfWriter *rwc, const MemoryBuffer *mb);

void docRtfSaveSectionProperties(RtfWriter *rwc, const PropertyMask *updMask,
				 const SectionProperties *sp);

int docRtfSaveSectionPropertiesOfNode(RtfWriter *rwc,
				      const DocumentSelection *ds,
				      const struct BufferItem *sectNode);

int docRtfWriteGetDefaultFont(RtfWriter *rw, int deff);

void docRtfWriteFontTable(RtfWriter *rwc);

int docRtfWriteColorTable(RtfWriter *rwc, const DocumentProperties *dp);

void docRtfWriteStyleSheet(RtfWriter *rwc, const DocumentStyleSheet *dss);

int docRtfWriteArgDestinationBegin(RtfWriter *rwc, const char *tag, int arg);

int docRtfSaveDocumentProperties(RtfWriter *rwc, int fet,
				 const PropertyMask *dpMask,
				 const DocumentProperties *dp);

int docRtfSaveNotesProperties(
	RtfWriter *rw, const PropertyMask *mask, const NotesProperties *np,
	const int propMap[NOTESprop_COUNT], const char *startNrTag,
	const char *const *justificationTags, int justificationTagCount,
	const char *const *placementTags, int placementTagCount,
	const char *const *restartTags, int restartTagCount,
	const char *const *styleTags, int styleTagCount);

void docRtfSaveParaFrameProperties(RtfWriter *rwc, const FrameProperties *fp);
void docRtfSaveRowFrameProperties(RtfWriter *rwc, const FrameProperties *fp);

int docRtfSaveSectHeadersFooters(RtfWriter *rwc, const struct BufferItem *bi);

int docRtfSaveHeaderFooter(RtfWriter *rwc, const DocumentTree *dt);

int docRtfSaveDocumentTree(RtfWriter *rwc, const char *tag,
			   const DocumentTree *dt, int evenIfAbsent,
			   int forcePar);

int docRtfSaveDocNotesSeparators(RtfWriter *rwc, const BufferDocument *bd);

void docRtfSaveCellProperties(RtfWriter *rwc, const PropertyMask *cpSetMask,
			      const CellProperties *cpSet, int shiftLeft);

void docRtfSaveRowProperties(RtfWriter *rwc, const PropertyMask *rpSetMask,
			     const RowProperties *rpSet, int col0, int col1);

void docRtfSaveAutoSpace(RtfWriter *rwc, const char *unitTag, int unit,
			 const char *numberTag, int number);

int docRtfWriteListProps(RtfWriter *rw, const struct DocumentList *dl);

void docRtfWriteListTable(RtfWriter *rwc, const DocumentListTable *dlt);

void docRtfWriteListOverrideTable(RtfWriter *rwc, const ListOverrideTable *lot);

void docRtfWriteListLevel(RtfWriter *rwc, const struct ListLevel *ll);

void docRtfSaveTabStopList(RtfWriter *rwc, const struct TabStopList *tsl);

void docRtfSaveShadingByNumber(RtfWriter *rwc, int num,
			       const char *const *patTags, int patTagCount,
			       const char *foreTag, const char *backTag,
			       const char *levelTag);

void docRtfReserveColumns(RtfWriter *rwc, int cols);

int docRtfSaveParaNode(RtfWriter *rwc, const struct BufferItem *bi,
		       const DocumentSelection *ds, const int flattenCell,
		       const int firstInRow);

void docRtfWriteSemicolon(RtfWriter *rwc);

void docRtfSaveParaTableNesting(RtfWriter *rwc, int nest);

int docRtfPushAttribute(RtfWriter *rwc);
int docRtfPopAttribute(RtfWriter *rwc);

void docRtfWriteSwitchTextAttributes(RtfWriter *rwc, int textAttrNr,
				     const char *first);

void docRtfWriteSwitchToPlain(RtfWriter *rwc);

int docRtfWriteBuildFontAdmin(RtfWriter *rwc);

int docRtfWriteGetCharset(RtfWriter *rwc, int *pCharset, const DocumentFont *df,
			  int symbol);

int docRtfSaveFieldHead(RtfWriter *rwc, const struct BufferItem *paraNode,
			int part);

int docRtfSaveFieldTail(RtfWriter *rwc, const struct BufferItem *paraNode,
			int part);

int docRtfDocPropMask(PropertyMask *dpSaveMask,
		      const DocumentProperties *dpDoc);

int docRtfWriteSelection(RtfWriter *rw, const DocumentSelection *ds);

int docRtfSaveDate(RtfWriter *rw, const char *tag, const struct tm *tm);

void docRtfWriteSetupTextConverters(RtfWriter *rw);

#endif /*	RTF_WRITER_IMPL_H	*/
