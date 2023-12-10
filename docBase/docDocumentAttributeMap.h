/************************************************************************/
/*									*/
/*  Map numbered attributes in one document to those in anaother one.	*/
/*									*/
/************************************************************************/

#ifndef DOC_DOCUMENT_ATTRIBUTE_MAP_H
#define DOC_DOCUMENT_ATTRIBUTE_MAP_H

typedef struct DocumentAttributeMap {
	int *damFontMap;
	int *damColorMap;
	int *damRulerMap;
	int *damBorderMap;
	int *damFrameMap;
	int *damShadingMap;
	int *damCellMap;
	int *damListStyleMap;
} DocumentAttributeMap;

/************************************************************************/
/*									*/
/*  Routine Declarations.						*/
/*									*/
/************************************************************************/

void docInitDocumentAttributeMap(DocumentAttributeMap *dam);
void docCleanDocumentAttributeMap(DocumentAttributeMap *dam);

#endif /*	DOC_DOCUMENT_ATTRIBUTE_MAP_H	*/
