/************************************************************************/
/*									*/
/*  Simple io streams, Data on the stream travels in 256 byte packets	*/
/*  The last packet of the stream has zero length indicator.		*/
/*  [Like in the GIF spec.]						*/
/*									*/
/************************************************************************/

#include "sioGeneral.h"
SimpleInputStream *sioInBlockedOpen(SimpleInputStream *sisBlocks);

SimpleOutputStream *sioOutBlockedOpen(SimpleOutputStream *sosBlocks);
