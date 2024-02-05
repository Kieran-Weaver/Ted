#ifndef UTIL_ENDIAN_H
#define UTIL_ENDIAN_H

#include <stdio.h>
/************************************************************************/
/*									*/
/*  Pieces of 'endian' subroutines that are used internally in the code	*/
/*									*/
/*  b0 is the most significant byte, b1/b3 the least significant.	*/
/*									*/
/************************************************************************/

#define NEGBYTES32(b3, b2, b1, b0, l) \
	l = -(l + 1);                 \
	b3 = 255 - (l % 256);         \
	l /= 256;                     \
	b2 = 255 - (l % 256);         \
	l /= 256;                     \
	b1 = 255 - (l % 256);         \
	l /= 256;                     \
	b0 = 255 - (l);

#define POSBYTES32(b3, b2, b1, b0, l) \
	b3 = l % 256;                 \
	l /= 256;                     \
	b2 = l % 256;                 \
	l /= 256;                     \
	b1 = l % 256;                 \
	l /= 256;                     \
	b0 = l;

#define NEGBYTES16(b1, b0, l) \
	l = -(l + 1);         \
	b1 = 255 - (l % 256); \
	l /= 256;             \
	b0 = 255 - (l);

#define POSBYTES16(b1, b0, l) \
	b1 = l % 256;         \
	l /= 256;             \
	b0 = l;

#define NEGVALUE32(b0, b1, b2, b3, l, t)     \
	l = ((t)b0 - 255) * 256 * 256 * 256; \
	l += ((t)b1 - 255) * 256 * 256;      \
	l += ((t)b2 - 255) * 256;            \
	l += ((t)b3 - 255);                  \
	l--;

#define POSVALUE32(b0, b1, b2, b3, l, t) \
	l = ((t)b0) * 256 * 256 * 256;   \
	l += ((t)b1) * 256 * 256;        \
	l += ((t)b2) * 256;              \
	l += ((t)b3);

#define NEGVALUE16(b0, b1, l, t) \
	l = ((t)b0 - 255) * 256; \
	l += ((t)b1 - 255);      \
	l--;

#define POSVALUE16(b0, b1, l, t) \
	l = ((t)b0) * 256;       \
	l += ((t)b1);

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int utilGetLeInt16(FILE *);
long utilGetLeInt32(FILE *);
unsigned int utilGetLeUint16(FILE *);
unsigned long utilGetLeUint32(FILE *);
double utilGetLeDouble64(FILE *);
float utilGetLeFloat32(FILE *);

int utilGetBeInt16(FILE *);
long utilGetBeInt32(FILE *);
unsigned int utilGetBeUint16(FILE *);
unsigned long utilGetBeUint32(FILE *);
double utilGetBeDouble64(FILE *);
float utilGetBeFloat32(FILE *);

void utilPutLeInt16(int, FILE *);
void utilPutLeInt32(long, FILE *);
void utilPutLeUint16(unsigned int, FILE *);
void utilPutLeUint32(unsigned long, FILE *);

void utilPutBeInt16(int, FILE *);
void utilPutBeInt32(long, FILE *);
void utilPutBeUint16(unsigned int, FILE *);
void utilPutBeUint32(unsigned long, FILE *);

long utilEndianExtractLeInt32(const unsigned char *s);
int utilEndianExtractLeInt16(const unsigned char *s);
long utilEndianExtractBeInt32(const unsigned char *s);
int utilEndianExtractBeInt16(const unsigned char *s);

unsigned long utilEndianExtractLeUint32(const unsigned char *s);
unsigned int utilEndianExtractLeUint16(const unsigned char *s);
unsigned long utilEndianExtractBeUint32(const unsigned char *s);
unsigned int utilEndianExtractBeUint16(const unsigned char *s);

void utilEndianStoreBeInt32(long l, unsigned char *b);
void utilEndianStoreLeInt32(long l, unsigned char *b);
void utilEndianStoreBeInt16(int i, unsigned char *b);
void utilEndianStoreLeInt16(int i, unsigned char *b);

void utilEndianStoreBeUint32(unsigned long l, unsigned char *b);
void utilEndianStoreLeUint32(unsigned long l, unsigned char *b);
void utilEndianStoreBeUint16(unsigned int i, unsigned char *b);
void utilEndianStoreLeUint16(unsigned int i, unsigned char *b);

#endif /* UTIL_ENDIAN_H */
