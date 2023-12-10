/************************************************************************/
/*									*/
/*  Simple io streams, Data on the stream travels in hexadecimal	*/
/*  format.								*/
/*									*/
/************************************************************************/

#include "sioGeneral.h"

SimpleInputStream *sioInHexOpen(SimpleInputStream *sisHex);

SimpleOutputStream *sioOutHexOpenFolded(SimpleOutputStream *sosHex,
					       int wide, int lastNl);

SimpleOutputStream *sioOutHexOpen(SimpleOutputStream *sosHex);
