/************************************************************************/
/*									*/
/*  Border properties.							*/
/*									*/
/************************************************************************/

#ifndef DOC_BORDER_PROP_H
#define DOC_BORDER_PROP_H

#include <utilPropMask.h>
#include <utilColor.h>
#include <utilPalette.h>

/************************************************************************/
/*									*/
/*  Border Styles: How they are drawn.					*/
/*									*/
/************************************************************************/

typedef enum BorderStyle {
	DOCbsNONE = 0,
	DOCbsS,
	DOCbsTH,
	DOCbsSH,

	DOCbsDB,
	DOCbsHAIR,
	DOCbsDOT,
	DOCbsDASH,
	DOCbsDASHD,
	DOCbsDASHDD,
	DOCbsTRIPLE,

	DOCbsTNTHSG,
	DOCbsTHTNSG,
	DOCbsTNTHTNSG,
	DOCbsTNTHMG,
	DOCbsTHTNMG,
	DOCbsTNTHTNMG,
	DOCbsTNTHLG,
	DOCbsTHTNLG,
	DOCbsTNTHTNLG,

	DOCbsWAVY,
	DOCbsWAVYDB,
	DOCbsDASHSM,
	DOCbsDASHDOTSTR,
	DOCbsEMBOSS,
	DOCbsENGRAVE,
	DOCbsFRAME,
	DOCbsOUTSET,

	DOCbsTBL,
	DOCbsNIL,

	DOCbs_COUNT
} BorderStyle;

#define DOCisBORDER(bp)                                             \
	((bp)->bpStyle != DOCbsNONE && (bp)->bpStyle != DOCbsTBL && \
	 (bp)->bpStyle != DOCbsNIL)

#define BRDRW_MAX 75 /*  Maximum width		*/
#define BRDRW_MAX2 (2 * BRDRW_MAX) /*  Maximum double width	*/

typedef struct BorderProperties {
	unsigned char bpColor;
	unsigned char bpPenWideTwips;
	unsigned char bpStyle; /*  (enum)		*/
	unsigned short bpSpacingTwips; /*  Only used for	*/
	/*  paragraph borders	*/
	unsigned char bpArt;

} BorderProperties;

typedef struct ExpandedBorderProperties {
	int ebpColorExplicit;
	RGB8Color ebpColor;

	int ebpPenWideTwips;
	int ebpStyle;
	int ebpSpacingTwips;
	int ebpArt;
} ExpandedBorderProperties;

typedef enum BorderProperty {
	BRDRprop_NONE = -1,

	BRDRpropCOLOR = 0,
	BRDRpropSPACING,
	BRDRpropPEN_WIDE,
	BRDRpropSTYLE,
	BRDRpropART,

	BRDRprop_COUNT
} BorderProperty;

#define docCleanBorderProperties(bp) /*void*/

/************************************************************************/
/*									*/
/*  Routine Declarations.						*/
/*									*/
/************************************************************************/

void docInitBorderProperties(BorderProperties *bp);

void docUpdateBorderProperties(PropertyMask *pBpDoneMask,
			       BorderProperties *bpTo,
			       const PropertyMask *bpSetMask,
			       const BorderProperties *bpFrom);

void docCopyBorderProperties(BorderProperties *bpTo,
			     const BorderProperties *bpFrom,
			     const int *colorMap);

int docBordersDiffer(const BorderProperties *bp1, const BorderProperties *bp2,
		     const int *colorMap);

void docExpandBorderProperties(ExpandedBorderProperties *ebp,
			       const BorderProperties *bp,
			       const ColorPalette *cp);

int docIndirectBorderProperties(PropertyMask *pBpDoneMask, BorderProperties *bp,
				const PropertyMask *bpSetMask,
				const ExpandedBorderProperties *ebp,
				ColorPalette *cp);

void docInitExpandedBorderProperties(ExpandedBorderProperties *ebp);

int docBorderThick(int *pWide, const BorderProperties *bp);

void docStretchInsetForBorder(int *pInset, const BorderProperties *bp);

void docAddBorderToInset(int *pInset, const BorderProperties *bp);

int docSetBorderProperty(BorderProperties *bp, int prop, int arg);

int docGetBorderProperty(const BorderProperties *bp, int prop);

#endif /*  DOC_BORDER_PROP_H  */
