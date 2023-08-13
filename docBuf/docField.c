/************************************************************************/
/*									*/
/*  Evaluate fields+ the list of kinds of fields.			*/
/*									*/
/************************************************************************/

#include <config.h>

#include <appDebugon.h>

#include "docBuf.h"
#include "docField.h"
#include "docEvalField.h"

/************************************************************************/
/*									*/
/*  The Kinds of Fields actively supported.				*/
/*									*/
/************************************************************************/

#define NOT_IN_RTF 0
#define FIELD_IN_RTF 1

#define NO_DEST 0
#define DEST_IN_RTF 1

#define RESULT_READONLY 0
#define RESULT_EDITABLE 1

#define MULTI_PARAGRAPH 0
#define SINGLE_PARAGRAPH 1

const FieldKindInformation DOC_FieldKinds[] = {
	{
		"-UNKNOWN",
		DOClevANY,
		NOT_IN_RTF,
		NO_DEST,
		(CALCULATE_TEXT_PARTICULES)0,
		(CALCULATE_TEXT_STRING)0,
		FIELDdoNEVER,
		RESULT_READONLY,
		MULTI_PARAGRAPH,
	},
	{
		"HYPERLINK",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateHyperlinkField,
		(CALCULATE_TEXT_STRING)0,
		FIELDdoDOC_COMPLETE, /* Must Be: FIELDdoNEVER, */
		RESULT_EDITABLE,
		SINGLE_PARAGRAPH,
	},
	{
		"-XE",
		DOClevSPAN,
		NOT_IN_RTF,
		DEST_IN_RTF,
		(CALCULATE_TEXT_PARTICULES)0,
		(CALCULATE_TEXT_STRING)0,
		FIELDdoNEVER,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
		"xe",
	},
	{
		"-TC",
		DOClevSPAN,
		NOT_IN_RTF,
		NO_DEST,
		(CALCULATE_TEXT_PARTICULES)0,
		(CALCULATE_TEXT_STRING)0,
		FIELDdoNEVER,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
		"tc",
	},
	{
		"-TCN",
		DOClevSPAN,
		NOT_IN_RTF,
		NO_DEST,
		(CALCULATE_TEXT_PARTICULES)0,
		(CALCULATE_TEXT_STRING)0,
		FIELDdoNEVER,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
		"tcn",
	},
	{
		"-BOOKMARK",
		DOClevCELL,
		NOT_IN_RTF,
		NO_DEST,
		(CALCULATE_TEXT_PARTICULES)0,
		(CALCULATE_TEXT_STRING)0,
		FIELDdoNEVER,
		RESULT_EDITABLE,
		MULTI_PARAGRAPH,
	},
	{
		"SEQ",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculateSeqFieldString,
		FIELDdoDOC_COMPLETE | FIELDdoSEQ,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"SECTION",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculateSectionFieldString,
		FIELDdoDOC_FORMATTED,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"SECTIONPAGES",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculateSectionPagesFieldString,
		FIELDdoDOC_FORMATTED,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"PAGE",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculatePageFieldString,
		FIELDdoPAGE_NUMBER | FIELDdoDOC_FORMATTED,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"PAGEREF",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculatePagerefFieldString,
		FIELDdoDOC_FORMATTED,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"NUMPAGES",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculateNumpagesFieldString,
		FIELDdoDOC_FORMATTED,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"REF",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculateRefFieldString,
		FIELDdoDOC_COMPLETE,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"CREATEDATE",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculateDocDateFieldString,
		FIELDdoDOC_INFO,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"SAVEDATE",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculateDocDateFieldString,
		FIELDdoDOC_INFO,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"PRINTDATE",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculateDocDateFieldString,
		FIELDdoDOC_INFO,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"DATE",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculateDocDateFieldString,
		FIELDdoDOC_COMPLETE,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"TIME",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculateDocDateFieldString,
		FIELDdoDOC_COMPLETE,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"AUTHOR",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculateDocStringFieldString,
		FIELDdoDOC_INFO,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"COMMENTS",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculateDocStringFieldString,
		FIELDdoDOC_INFO,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"DOCCOMM",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculateDocStringFieldString,
		FIELDdoDOC_INFO,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"KEYWORDS",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculateDocStringFieldString,
		FIELDdoDOC_INFO,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"SUBJECT",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculateDocStringFieldString,
		FIELDdoDOC_INFO,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"TITLE",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculateDocStringFieldString,
		FIELDdoDOC_INFO,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"FILENAME",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaStringTextParticules,
		docCalculateFilenameFieldString,
		FIELDdoDOC_INFO,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"MERGEFIELD",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateMergeField,
		(CALCULATE_TEXT_STRING)0,
		FIELDdoDOC_INFO,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"FORMTEXT",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		(CALCULATE_TEXT_PARTICULES)0,
		(CALCULATE_TEXT_STRING)0,
		FIELDdoNEVER,
		RESULT_EDITABLE,
		SINGLE_PARAGRAPH,
	},
	{
		"FORMCHECKBOX",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		(CALCULATE_TEXT_PARTICULES)0,
		(CALCULATE_TEXT_STRING)0,
		FIELDdoNEVER,
		RESULT_EDITABLE,
		SINGLE_PARAGRAPH,
	},
	{
		"SYMBOL",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateParaSymbolTextParticules,
		docCalculateSymbolFieldString,
		FIELDdoDOC_COMPLETE,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"-CHFTN",
		DOClevSPAN,
		NOT_IN_RTF,
		NO_DEST,
		docRecalculateParaChftnTextParticules,
		docCalculateChftnFieldString,
		FIELDdoDOC_COMPLETE | FIELDdoCHFTN,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"-CHATN",
		DOClevSPAN,
		NOT_IN_RTF,
		NO_DEST,
		docRecalculateParaChftnTextParticules,
		docCalculateChftnFieldString,
		FIELDdoDOC_COMPLETE | FIELDdoCHFTN,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"-LISTTEXT",
		DOClevSPAN,
		NOT_IN_RTF,
		NO_DEST,
		docRecalculateParaListtextTextParticules,
		docCalculateDocStringFieldString, /* as dummy */
		FIELDdoDOC_COMPLETE | FIELDdoLISTTEXT,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"INCLUDEPICTURE",
		DOClevSPAN,
		FIELD_IN_RTF,
		NO_DEST,
		docRecalculateIncludePictureField,
		(CALCULATE_TEXT_STRING)0,
		FIELDdoDOC_COMPLETE,
		RESULT_READONLY,
		SINGLE_PARAGRAPH,
	},
	{
		"TOC",
		DOClevCELL,
		FIELD_IN_RTF,
		NO_DEST,
		(CALCULATE_TEXT_PARTICULES)0,
		(CALCULATE_TEXT_STRING)0,
		FIELDdoTOC, /* Have their own call */
		RESULT_READONLY,
		MULTI_PARAGRAPH,
	},
};

const int DOC_FieldKindCount =
	sizeof(DOC_FieldKinds) / sizeof(FieldKindInformation);
