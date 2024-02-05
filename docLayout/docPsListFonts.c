/************************************************************************/
/*									*/
/*  List the fonts in a document.					*/
/*  Manage resources for layout.					*/
/*									*/
/************************************************************************/

#include <config.h>

#include <stddef.h>

#include "docParticuleData.h"
#include "docPsPrintImpl.h"
#include <docListFonts.h>
#include <sioHex.h>
#include <sioMemory.h>
#include <docObjectProperties.h>
#include <docTreeNode.h>

#include <appDebugon.h>

/************************************************************************/
/*									*/
/*  Recursively retrieve the list of PostScriptFonts that is used in	*/
/*  a document.								*/
/*									*/
/************************************************************************/

/************************************************************************/

typedef struct GetDocumentFonts {
	const LayoutContext *gdfLayoutContext;
	PostScriptTypeList *gdfPostScriptTypeList;
} GetDocumentFonts;

/************************************************************************/

static int docPsPrintGotSpan(BufferDocument *bd, BufferItem *paraNode,
			     int textAttrNr, const TextAttribute *ta, int from,
			     int upto, void *through)
{
	GetDocumentFonts *gdf = (GetDocumentFonts *)through;
	const LayoutContext *lc = gdf->gdfLayoutContext;
	const DocumentFontList *dfl = bd->bdProperties.dpFontList;
	PostScriptTypeList *pstl = gdf->gdfPostScriptTypeList;
	const IndexSet *unicodesWanted;

	const AfmFontInfo *afi;

	const int appearsInText = 1;

	afi = (*lc->lcGetFontForAttribute)(&unicodesWanted, ta, dfl,
					   lc->lcPostScriptFontList);
	if (!afi) {
		XDEB(afi);
		return -1;
	}

	if (psRememberPostsciptFace(pstl, afi, ta, "f", appearsInText)) {
		LDEB(1);
		return -1;
	}

	return 0;
}

int docPsPrintGetDocumentFonts(PostScriptTypeList *pstl,
			       const LayoutContext *lc)
{
	ScanDocumentFonts sdf;
	GetDocumentFonts gdf;

	docInitScanDocumentFonts(&sdf);

	gdf.gdfPostScriptTypeList = pstl;
	gdf.gdfLayoutContext = lc;

	sdf.sdfDocListSpanFont = docPsPrintGotSpan;
	sdf.sdfThrough = &gdf;

	/*  a  */
	if (docListDocumentFonts(lc->lcDocument, &sdf)) {
		LDEB(1);
		return -1;
		;
	}

	return 0;
}
