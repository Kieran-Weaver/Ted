#ifndef PS_PRINT_SHAPE_H
#define PS_PRINT_SHAPE_H

#include <stdio.h>
#include <sioGeneral.h>
#include <geo2DInteger.h>

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void psDrawRoundRectPath(SimpleOutputStream *sos,
				const rect *drAround, int r,
				const char *psOperator);

#endif /*  PS_PRINT_SHAPE_H  */
