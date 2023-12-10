/************************************************************************/
/*									*/
/*  Simple io streams, Data on the stream travels in 12 bits LZW	*/
/*  format.								*/
/*									*/
/*  Various implementations of the LZW algorithm differ in details of	*/
/*  the coding of the compressed stream.				*/
/*									*/
/************************************************************************/

#include "sioGeneral.h"

SimpleInputStream *sioInLzwGifOpen(SimpleInputStream *sisLzw,
					  int codeSize);

SimpleOutputStream *sioOutLzwGifOpen(SimpleOutputStream *sosLzw,
					    int codeSize);
