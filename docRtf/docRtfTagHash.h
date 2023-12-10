/************************************************************************/
/*									*/
/*  Hash functions for tags.						*/
/*									*/
/************************************************************************/

#ifndef DOC_RTF_TAG_HASH_H
#define DOC_RTF_TAG_HASH_H

unsigned long docRtfTagHash(const unsigned char *tagkey, int len);

int docRtfTagIndex(const unsigned char *tagkey, int len);

unsigned long docRtfShapePropHash(const unsigned char *tagkey, int len);

int docRtfShapePropIndex(const unsigned char *tagkey, int len);

#endif /*  DOC_RTF_TAG_HASH_H	*/
