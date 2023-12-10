/************************************************************************/
/*									*/
/*  Reading RTF.							*/
/*									*/
/************************************************************************/

#ifndef RTF_READER_IMPL_H
#define RTF_READER_IMPL_H

#include <docBuf.h>
#include <docNoteProperties.h>
#include <sioGeneral.h>
#include <docTabStop.h>
#include <docTabStopList.h>
#include <docListOverride.h>
#include <docDocumentList.h>
#include <docBorderProperties.h>
#include "docRtfTextConverter.h"
#include "docRtfControlWord.h"

struct RtfReader;
typedef struct RtfReader RtfReader;

/************************************************************************/
/*									*/
/*  Context for Reading RTF.						*/
/*									*/
/************************************************************************/

struct RtfFieldStackLevel;

typedef struct RtfReadingState {
	int rrsBytesPerUnicode;
	int rrsUnicodeBytesToSkip;

	TextAttribute rrsTextAttribute;
	/************************************/
	/*  Font number is in buffer terms.	*/
	/*  NOT in file terms.		*/
	/************************************/
	int rrsTextCharset;
	ItemShading rrsTextShading;
	int rrsTextShadingChanged;
	ParagraphProperties rrsParagraphProperties;
	TabStopList rrsTabStopList;
	ItemShading rrsParagraphShading;
	FrameProperties rrsParaFrameProperties;

	MemoryBuffer rrsSavedText;

	struct RtfReadingState *rrsPrev;
} RtfReadingState;

typedef int (*RtfAddTextParticule)(struct RtfReader *rr, const char *text,
				   int len);

struct RtfReader {
	RtfReadingState *rrcState;
	RtfAddTextParticule rrcAddParticule;
	SimpleInputStream *rrcSis;

	/**
				 *  Type of BufferItem. Still retated 
				 *  to the depth in the document
				 */
	int rrcLevel;

	/**
				 *  Incremented/Decremented around groups 
				 *  with an unknown control word. This is 
				 *  to ignore everything inside the group and 
				 *  to only complain about the unknown group 
				 *  and to shut up about its contents.
				 */
	int rrcInIgnoredGroup;

	/**
				 *  Complain about unknown control words
				 */
	int rrcComplainUnknown;

	/**
				 *  Character that could not be unread
				 *  using ungetc().
				 */
	int rrcCharacterAhead;

	int rrcAfterNoteref;

	int rrReadFlags;

	int rrCurrentLine;
	struct BufferDocument *rrDocument;
	struct DocumentTree *rrcTree;
	struct BufferItem *rrcNode;
	/****************************************/
	/*  The current position in the input.	*/
	/****************************************/
	/****************************************/
	/*  Text attributes of the current pos.	*/
	/****************************************/
	FrameProperties rrcRowFrameProperties;

	CellProperties rrcCellProperties;
	PropertyMask rrcCellPropertyMask;
	ItemShading rrcCellShading;

	SectionProperties rrcSectionProperties;
	PropertyMask rrcSectionPropertyMask;
	int rrcSectionColumn;

	RowProperties rrcRowProperties;
	PropertyMask rrcRowPropertyMask;
	ItemShading rrcRowShading;

	BorderProperties rrcBorderProperties;

	struct DrawingShape *rrDrawingShape;
	const RtfControlWord *rrShapeProperty;
	MemoryBuffer rrShapePropertyName;
	MemoryBuffer rrShapePropertyValue;

	int rrcNextObjectVertex;
	/**
				     *  The style in the stylesheet that is 
				     *  built up before it is inserted in the 
				     *  document. It is abused to hold the 
				     *  new properties in a property change.
				     */
	DocumentStyle rrcStyle;
	DocumentProperties rrcDocumentProperties;
	PropertyMask rrcDocPropertyMask;
	TabStop rrcTabStop;
	RGB8Color rrcColor;
	int rrcGotComponent;
	struct tm rrcTm;
	unsigned char *rrcInfoText;
	SelectionScope rrcSelectionScope;

	ParagraphNumber rrcParagraphNumber;
	ItemShading rrcParagraphNumberTextShading;
	ParagraphNumber *rrcParagraphNumbers;
	int rrcParagraphNumberCount;

	DocumentList rrcDocumentList;
	ListLevel rrcDocumentListLevel;
	MemoryBuffer rrcListLevelText;
	MemoryBuffer rrcListLevelNumbers;

	ListOverride rrcListOverride;
	ListOverrideLevel rrcListOverrideLevel;

	/****************************************/
	/*  Document properties.		*/
	/****************************************/
	DocumentFont rrcCurrentFont;
	EncodedFont rrcCurrentEncodedFont;
	PagedList rrcEncodedFontList;

	int rrcDefaultFont;
	int rrcDefaultFontDbch;
	int rrcDefaultFontLoch;
	int rrcDefaultFontHich;
	int rrcDefaultFontBi;

	/****************************************/
	/*  For reading the font table.		*/
	/*  Style sheet.			*/
	/****************************************/
	int rrcInsertedObjectNr;
	PictureProperties rrcPictureProperties;
	PropertyMask rrcPicturePropMask;
	MemoryBuffer rrcBookmark;
	struct RtfFieldStackLevel *rrcFieldStack;
	int rrcLastFieldNumber;
	/****************************************/
	/*  For reading 'objects' and pictures.	*/
	/*  For reading 'fields'.		*/
	/****************************************/
	int rrAfterParaHeadField;
	int rrParagraphBreakOverride;
	int rrcGotDocGeometry;
	/****************************************/
	/*  For coping with the way word saves	*/
	/*  {\pntext ... }			*/
	/****************************************/

	struct TextConverter *rrRtfTextConverter;
	struct TextConverter *rrTextTextConverter;

	/**
				 * Only used for reading Undo/Redo traces.
				 * -1: old; 1: new
				 */
	int rrcTraceReadWhat;
	int rrcTraceCommand;
	int rrcTraceSelectionPosition;
	int rrcTraceFieldKind;
	int rrcTraceInProps;

	SelectionScope rrcTraceOldSelectionScope;
	EditRange rrcTraceOldRange;
	int rrcTraceOldCol0;
	int rrcTraceOldCol1;
	int rrcTraceOldPage;
	int rrcTraceOldColumn;

	int rrcTracePropLevel;
	int rrcTraceTargetType;

	SelectionScope rrcTraceNewSelectionScope;
	EditRange rrcTraceNewRange;
	int rrcTraceNewCol0;
	int rrcTraceNewCol1;
	int rrcTraceNewPage;
	int rrcTraceNewColumn;

	NoteProperties rrcNoteProperties;
	PropertyMask rrcNotePropertyMask;
};

/************************************************************************/
/*									*/
/*  What you can find in an RTF file.					*/
/*									*/
/************************************************************************/

#define RTFfiCTRLGROUP 1
#define RTFfiWORD 2
#define RTFfiCHAR 3
#define RTFfiTAB 4
#define RTFfiCLOSE 5
#define RTFfiSTARGROUP 6
#define RTFfiTEXTGROUP 7

/************************************************************************/

/************************************************************************/
/*									*/
/*  Shortcuts in the definition of property tables.			*/
/*									*/
/************************************************************************/

#define RTF_TEXT_GROUP(s, id, co) \
	RTF_DEST_CO(s, id, docRtfApplyDocEncodedTextGroup, co)

#define RTF_BYTE_GROUP(s, id, co) \
	RTF_DEST_CO(s, id, docRtfApplyRawBytesGroup, co)

/************************************************************************/

typedef enum RtfLookupId {
	RTFlookupXEF,
	RTFlookupBXE,
	RTFlookupIXE,

	RTFlookupTC,
	RTFlookupTCN,
	RTFlookupTCF,
	RTFlookupTCL,

	RTFlookup_COUNT
} RtfLookupId;

/************************************************************************/
/*									*/
/*  Common data.							*/
/*									*/
/************************************************************************/

extern RtfControlWord docRtfDocumentGroups[];
extern const char DOC_RTF_LENIENT_MESSAGE[];

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void docRtfPopReadingState(RtfReader *rr);

const RtfControlWord *docRtfFindPropertyWord(const char *controlWord);

const RtfControlWord *
docRtfFindShapePropertyWord(const char *controlWord);

int docRtfFindControl(RtfReader *rr, int *pC, char *controlWord,
			     int *pGotArg, int *pArg);

int docRtfIgnoreWord(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfIgnoreText(RtfReader *rr, const char *text, int len);

int docRtfRefuseText(RtfReader *rr, const char *text, int len);

int docRtfSaveDocEncodedText(RtfReader *rr, const char *text, int len);

int docRtfSaveFontEncodedText(RtfReader *rr, const char *text, int len);

int docRtfSaveRawBytes(RtfReader *rr, const char *text, int len);

int docRtfStoreSavedText(char **pTarget, int *pSize, RtfReader *rr,
				int removeSemicolon);

int docRtfFontTable(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfColorTable(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfRevisionTable(const RtfControlWord *rcw, int arg,
			       RtfReader *rr);

int docRtfStylesheet(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfListTable(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfReadInfo(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfRememberDocProperty(const RtfControlWord *rcw, int arg,
				     RtfReader *rr);

int docRtfReadUnknownGroup(RtfReader *rr);

int docRtfRememberParaFrameProperty(const RtfControlWord *rcw, int arg,
					   RtfReader *rr);

int docRtfRememberRowFrameProperty(const RtfControlWord *rcw, int arg,
					  RtfReader *rr);

int docRtfRememberProperty(const RtfControlWord *rcw, int arg,
				  RtfReader *rr);

int docRtfPopScopeFromFieldStack(RtfReader *rr);
int docRtfPopParaFromFieldStack(RtfReader *rr, int paraNr);

int docRtfRememberParagraphProperty(const RtfControlWord *rcw, int arg,
					   RtfReader *rr);

int docRtfBeginBorder(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfBrdrProperty(const RtfControlWord *rcw, int arg,
			      RtfReader *rr);

int docRtfRememberSectionProperty(const RtfControlWord *rcw, int arg,
					 RtfReader *rr);

int docRtfRememberTextProperty(const RtfControlWord *rcw, int arg,
				      RtfReader *rr);

int docRtfRememberPntextProperty(const RtfControlWord *rcw, int arg,
					RtfReader *rr);

int docRtfRememberCellProperty(const RtfControlWord *rcw, int arg,
				      RtfReader *rr);

int docRtfRememberCellInstanceProperty(const RtfControlWord *rcw,
					      int arg, RtfReader *rr);

int docRtfRememberRowProperty(const RtfControlWord *rcw, int arg,
				     RtfReader *rr);

int docRtfRememberStyleProperty(const RtfControlWord *rcw, int arg,
				       RtfReader *rr);

int docRtfRememberListLevelProperty(const RtfControlWord *rcw, int arg,
					   RtfReader *rr);

int docRtfRememberListProperty(const RtfControlWord *rcw, int arg,
				      RtfReader *rr);

void docRtfPushReadingState(RtfReader *rr, RtfReadingState *rrs);

const RtfControlWord *docRtfFindWord(const char *controlWord,
					    const RtfControlWord *controlWords);

int docRtfApplyControlWord(const RtfControlWord *rcw, int gotArg,
				  int arg, RtfReader *rr);

int docRtfReadGroup(const RtfControlWord *rcw, int gotArg, int arg,
			   RtfReader *rr, const RtfControlWord *groupWords,
			   RtfAddTextParticule addParticule,
			   RtfCommitGroup commitGroup);

int docRtfReadGroupX(const RtfControlWord *rcw,
			    const RtfControlWord *applyFirst, int gotArg,
			    int arg, RtfReader *rr,
			    const RtfControlWord *groupWords,
			    RtfAddTextParticule addParticule,
			    RtfCommitGroup commitGroup);

int docRtfSkipGroup(const RtfControlWord *groupRcw, int ignored_arg,
			   RtfReader *rr);

int docRtfConsumeGroup(const RtfControlWord *applyFirst, int gotArg,
			      int arg, RtfReader *rr,
			      const RtfControlWord *groupWords,
			      RtfAddTextParticule addParticule);

int docRtfReadPict(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfReadShpXPict(const RtfControlWord *rcw, int arg,
			      RtfReader *rr);

int docRtfReadObject(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfReadDrawingObject(const RtfControlWord *rcw, int arg,
				   RtfReader *rr);

int docRtfReadShape(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfTextParticule(RtfReader *rr, const char *text, int len);

int docRtfReadField(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfReadTextField(const RtfControlWord *rcw, int arg,
			       RtfReader *rr);

int docRtfLookupEntry(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfReadExtTree(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfReadFootnote(const RtfControlWord *rcw, int arg,
			      RtfReader *rr);

int docRtfBkmkStart(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfBkmkEnd(const RtfControlWord *rcw, int arg, RtfReader *rr);

DocumentField *docRtfSpecialField(int fieldKind, const char *fieldinst,
					 int fieldsize, const char *fieldRslt,
					 RtfReader *rr);

int docRtfTextSpecialToField(const RtfControlWord *rcw, int arg,
				    RtfReader *rr);

int docRtfRememberListOverrideLevelProperty(const RtfControlWord *rcw,
						   int arg, RtfReader *rr);

int docRtfRememberListOverrideProperty(const RtfControlWord *rcw,
					      int arg, RtfReader *rr);

int docRtfListOverrideTable(const RtfControlWord *rcw, int arg,
				   RtfReader *rr);

int docRtfRememberTabStopProperty(const RtfControlWord *rcw, int arg,
					 RtfReader *rr);

int docRtfFontProperty(const RtfControlWord *rcw, int arg,
			      RtfReader *rr);

int docRtfObjectProperty(const RtfControlWord *rcw, int arg,
				RtfReader *rr);

int docRtfPictureProperty(const RtfControlWord *rcw, int arg,
				 RtfReader *rr);

int docRtfTextSpecialChar(const RtfControlWord *rcw, int arg,
				 RtfReader *rr);

int docRtfTextUnicode(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfTextSpecialParticule(const RtfControlWord *rcw, int arg,
				      RtfReader *rr);

int docRtfTextBidiMark(const RtfControlWord *rcw, int arg,
			      RtfReader *rr);

int docRtfDrawingObjectProperty(const RtfControlWord *rcw, int arg,
				       RtfReader *rr);

int docRtfDrawingObjectCoordinate(const RtfControlWord *rcw, int arg,
					 RtfReader *rr);

int docRtfShpProperty(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfPnProperty(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfHierarchy(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfReadDocumentTree(const RtfControlWord *rcw, DocumentTree *dt,
				  int *pExtItKind, RtfReader *rr,
				  int ignoreEmpty, const SelectionScope *ss);

int docRtfShapeProperty(const RtfControlWord *rcw, int arg,
			       RtfReader *rr);
int docRtfShapePropertyName(const RtfControlWord *rcw, int arg,
				   RtfReader *rr);
int docRtfShapePropertyValue(const RtfControlWord *rcw, int arg,
				    RtfReader *rr);

int docRtfReadRowProperties(const RtfControlWord *rcw, int arg,
				   RtfReader *rr);

int docRtfLookupWord(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfColorComp(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfColorIgnored(const RtfControlWord *rcw, int arg,
			      RtfReader *rr);

int docRtfCommitDocPropText(const RtfControlWord *rcw, RtfReader *rr);

int docRtfDocTimeGroup(const RtfControlWord *rcw, int arg,
			      RtfReader *rr);

void docRtfRefreshTextShading(RtfReader *rr, RtfReadingState *rrs);

int docRtfRefreshParagraphProperties(BufferDocument *bd,
					    RtfReadingState *rrs);

int docRtfSetParaProperties(ParagraphProperties *pp, BufferDocument *bd,
				   int mindTable, RtfReadingState *rrs,
				   int breakOverride);

int docRtfAdaptToParaProperties(struct BufferItem *paraNode,
				       BufferDocument *bd, RtfReadingState *rrs,
				       int breakOverride);

void docRtfSetForRow(struct BufferItem *node);

void docRtfResetParagraphProperties(RtfReadingState *rrs);

void docRtfResetTextAttribute(RtfReadingState *rrs, BufferDocument *bd);

int docRtfSkipPn(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfReadPnseclvl(const RtfControlWord *rcw, int arg,
			      RtfReader *rr);

int docRtfRememberFieldProperty(const RtfControlWord *rcw, int arg,
				       RtfReader *rr);

int docRtfRememberNoteProperty(const RtfControlWord *rcw, int arg,
				      RtfReader *rr);

int docRtfApplyDocEncodedTextGroup(const RtfControlWord *rcw, int arg,
					  RtfReader *rr);

int docRtfApplyRawBytesGroup(const RtfControlWord *rcw, int arg,
				    RtfReader *rr);

int docRtfReadTimeField(const RtfControlWord *rcw, int arg,
			       RtfReader *rr);

struct BufferItem *docRtfGetParaNode(RtfReader *rr);
struct BufferItem *docRtfGetSectNode(RtfReader *rr);

int docRtfFinishCurrentNode(const RtfControlWord *rcw, RtfReader *rr);

void docRtfRestartFont(RtfReader *rr);

int docRtfReadMapFont(const RtfReader *rr, int *pDocFontNum,
			     int *pCharset, int fileFontNum);

int docRtfRememberTextShadingProperty(const RtfControlWord *rcw, int arg,
					     RtfReader *rr);

int docRtfRememberParaShadingProperty(const RtfControlWord *rcw, int arg,
					     RtfReader *rr);

int docRtfRememberCellShadingProperty(const RtfControlWord *rcw, int arg,
					     RtfReader *rr);

int docRtfRememberRowShadingProperty(const RtfControlWord *rcw, int arg,
					    RtfReader *rr);

int docRtfReadGetBorderNumber(RtfReader *rr);

int docRtfReadListLevelGroup(const RtfControlWord *rcw, RtfReader *rr);

int docRtfMemoryBufferSetText(MemoryBuffer *mb, RtfReader *rr,
				     int removeSemicolon);

int docRtfMemoryBufferAppendText(MemoryBuffer *mb, RtfReader *rr);

int docRtfSelectionScopeProperty(const RtfControlWord *rcw, int arg,
					RtfReader *rr);

int docRtfEditRangeProperty(const RtfControlWord *rcw, int arg,
				   RtfReader *rr);

int docRtfSelectionOpen(const RtfControlWord *rcw, int arg,
			       RtfReader *rr);

int docRtfStoreStyleProperties(RtfReader *rr);

int docRtfRememberList(const RtfControlWord *rcw, int arg,
			      RtfReader *rr);

int docRtfRememberListLevel(const RtfControlWord *rcw, int arg,
				   RtfReader *rr);

int docRtfCommitListLevelText(const RtfControlWord *rcw, RtfReader *rr);
int docRtfCommitListLevelNumbers(const RtfControlWord *rcw,
					RtfReader *rr);
int docRtfCommitListName(const RtfControlWord *rcw, RtfReader *rr);
int docRtfCommitListStyleName(const RtfControlWord *rcw, RtfReader *rr);

void docRtfResetCellProperties(RtfReader *rr);

void docRtfReadSetupTextConverters(RtfReader *rr);

RtfReader *docRtfOpenReader(SimpleInputStream *sis, BufferDocument *bd,
				   int flags);

void docRtfCloseReader(RtfReader *rr);

#endif /*	RTF_READER_IMPL_H	*/
