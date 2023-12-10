/************************************************************************/
/*									*/
/*  Simple io streams translating from/to the MIME (RFC 2045)		*/
/*  'Base 64' content transfer encoding.				*/
/*									*/
/************************************************************************/

#include "sioGeneral.h"

SimpleInputStream *sioInBase64Open(SimpleInputStream *sisBase64);

SimpleOutputStream *sioOutBase64Open(SimpleOutputStream *sosBase64);
