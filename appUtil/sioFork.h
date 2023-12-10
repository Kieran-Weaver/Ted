/************************************************************************/
/*									*/
/*  Simple io streams, Fork input or output.. Usually for debugging	*/
/*  purposes.								*/
/*									*/
/************************************************************************/

#include "sioGeneral.h"

SimpleInputStream *sioInForkOpen(SimpleInputStream *sisIn,
					SimpleOutputStream *sosFork);

SimpleOutputStream *sioOutForkOpen(SimpleOutputStream *sosOut,
					  SimpleOutputStream *sosFork);
