/************************************************************************/
/*									*/
/*  Header file for geometry/formatting/drawing related functionality	*/
/*									*/
/************************************************************************/

#ifndef DOC_SCREEN_LAYOUT_H
#define DOC_SCREEN_LAYOUT_H

#include <docBuf.h>
#include "docLayout.h"
#include <utilIndexMapping.h>
/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int docScreenTextWidth(int screenFont, const TextAttribute *ta,
		       const LayoutContext *lc, const char *s, int len);

int docOpenScreenFont(const LayoutContext *lc, int attributeNumber);

int docStartScreenLayoutForTree(LayoutJob *lj, DocumentTree *ei, int page,
				int column);

int docScreenLayoutOpenParaFonts(const LayoutContext *lc,
				 struct BufferItem *paraNode);

int docScreenLayoutNode(int *pReachedBottom, struct BufferItem *node,
			const LayoutContext *lc, DocumentRectangle *drChanged);

int docScreenLayoutDocumentBody(int *pReachedBottom, BufferDocument *bd,
				const LayoutContext *lc);

void docScreenCloseObject(const BufferDocument *bd,
			  const struct TextParticule *tp);

void docSetScreenLayoutFunctions(LayoutJob *lj);

#endif /*  DOC_SCREEN_LAYOUT_H	*/
