#ifndef SIO_ENDIAN_H
#define SIO_ENDIAN_H

#include "sioGeneral.h"

int sioEndianGetLeInt16(SimpleInputStream *);
long sioEndianGetLeInt32(SimpleInputStream *);
int sioEndianPutLeInt16(int, SimpleOutputStream *);
int sioEndianPutLeInt32(long, SimpleOutputStream *);

int sioEndianGetBeInt16(SimpleInputStream *);
long sioEndianGetBeInt32(SimpleInputStream *);
int sioEndianPutBeInt16(int, SimpleOutputStream *);
int sioEndianPutBeInt32(long, SimpleOutputStream *);

unsigned int sioEndianGetLeUint16(SimpleInputStream *);
unsigned long sioEndianGetLeUint32(SimpleInputStream *);
int sioEndianPutLeUint16(unsigned int, SimpleOutputStream *);
int sioEndianPutLeUint32(unsigned long, SimpleOutputStream *);

unsigned int sioEndianGetBeUint16(SimpleInputStream *);
unsigned long sioEndianGetBeUint32(SimpleInputStream *);
int sioEndianPutBeUint16(unsigned int, SimpleOutputStream *);
int sioEndianPutBeUint32(unsigned long, SimpleOutputStream *);

float sioEndianGetLeFloat(SimpleInputStream *);
int sioEndianPutLeFloat(float, SimpleOutputStream *);

float sioEndianGetBeFloat(SimpleInputStream *);
int sioEndianPutBeFloat(float, SimpleOutputStream *);

#endif /* SIO_ENDIAN_H */
