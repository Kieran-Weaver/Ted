/************************************************************************/
/*									*/
/*  Elementary functionalite to emit XML.				*/
/*									*/
/************************************************************************/

#ifndef XML_WRITER_H
#define XML_WRITER_H

#include "sioGeneral.h"
#include "utilColor.h"
#include "utilMemoryBuffer.h"

typedef struct XmlWriter {
	SimpleOutputStream *xwSos;
	int xwCrlf;
	int xwColumn;
} XmlWriter;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void xmlInitXmlWriter(XmlWriter *xw);

void xmlPutString(const char *s, XmlWriter *xw);

void xmlNewLine(XmlWriter *xw);

void xmlWriteStringAttribute(XmlWriter *xw, const char *name,
				    const char *value);

void xmlWriteIntAttribute(XmlWriter *xw, const char *name, int value);

void xmlWriteRgb8Attribute(XmlWriter *xw, const char *name,
				  const RGB8Color *rgb8);

void xmlEscapeCharacters(XmlWriter *xw, const char *ss, int len);

void xmlEscapeBuffer(XmlWriter *xw, const MemoryBuffer *mb);

#endif /*	XML_WRITER_H	*/
