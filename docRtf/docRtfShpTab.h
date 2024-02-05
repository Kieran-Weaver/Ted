/************************************************************************/
/*									*/
/*  Handle shapes while reading RTF.					*/
/*									*/
/************************************************************************/

#ifndef RTF_SHP_TAB_H
#define RTF_SHP_TAB_H

#include <docRtfReaderImpl.h>
/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int docRtfShpArray(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfShpString(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfShpPicture(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfShapeNumber(const RtfControlWord *rcw, int arg, RtfReader *rr);

int docRtfShpColor(const RtfControlWord *rcw, int arg, RtfReader *rr);

#endif /*	RTF_SHP_TAB_H	*/
