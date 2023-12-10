/************************************************************************/
/*									*/
/*  Simple io streams translating from/to the MIME (RFC 2045)		*/
/*  'Quoted Printable' content transfer encoding.			*/
/*									*/
/************************************************************************/

#include "sioGeneral.h"

SimpleInputStream *
sioInQuotedPrintableOpen(SimpleInputStream *sisQuoted);

SimpleOutputStream *
sioOutQuotedPrintableOpen(SimpleOutputStream *sosQuoted);
