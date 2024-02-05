/************************************************************************/
/*									*/
/*  Simple io streams, Data on the stream travels in In/Deflate format	*/
/*  using zlib.								*/
/*									*/
/************************************************************************/

#include "sioGeneral.h"

SimpleInputStream *sioInFlateOpen(SimpleInputStream *sisFlate);

SimpleOutputStream *sioOutFlateOpen(SimpleOutputStream *sosFlate,
				    int gzipEmbedded);
