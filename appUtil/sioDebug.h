/************************************************************************/
/*									*/
/*  Simple io streams, Fork input or output.. Usually for debugging	*/
/*  purposes.								*/
/*									*/
/*  Additionally, a pure debugging output stream is provided.		*/
/*									*/
/************************************************************************/

#include "sioGeneral.h"

SimpleInputStream *sioInDebugOpen(SimpleInputStream *sisIn);

SimpleOutputStream *sioOutDebugOpen(SimpleOutputStream *sosOut);

SimpleOutputStream *sioOutAppDebugOpen(void);
