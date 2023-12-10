/************************************************************************/
/*									*/
/*  Simple io streams translating from/to the PostsScript ASCII base 85	*/
/*  encoding.								*/
/*									*/
/************************************************************************/

#include "sioGeneral.h"

SimpleInputStream *sioInBase85Open(SimpleInputStream *sisBase85);

SimpleOutputStream *sioOutBase85Open(SimpleOutputStream *sosBase85);
