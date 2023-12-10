/************************************************************************/
/*									*/
/*  Printing retaled functionality.					*/
/*									*/
/************************************************************************/

#ifndef APP_PRINT_JOB_H
#define APP_PRINT_JOB_H

#include <drawDrawingSurface.h>

#ifdef __cplusplus
"C" {
#endif

struct PrintGeometry;

/************************************************************************/
/*									*/
/*  Printing..								*/
/*									*/
/************************************************************************/

typedef struct PrintJob {
	void *pjPrivateData;
	int pjFormat;
	const char *pjTitle;
	struct DrawingSurface *pjDrawingSurface;
	struct EditApplication *pjApplication;
	const struct PrintGeometry *pjPrintGeometry;
} PrintJob;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
