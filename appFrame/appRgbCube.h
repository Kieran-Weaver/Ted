/************************************************************************/
/*									*/
/*  Draw an RGB cube to allow the user to select colors.		*/
/*									*/
/************************************************************************/

#ifndef APP_RGB_CUBE_H
#define APP_RGB_CUBE_H

#include <drawDrawingSurface.h>
#include <geoAffineTransform.h>

typedef struct RgbColorBlock {
	RGB8Color rcbRgbColor;

	int rcbSelected;
	int rcbMappedIndex;
	/*  Calculated index, based on color values	*/
	/*  does not work: blocks are sorted.	*/
	/*  At the calculated position, remember	*/
	/*  where the color now is.			*/

	double rcbX0;
	double rcbY0;
	double rcbZ0;

	double rcbX1;
	double rcbY1;
	double rcbZ1;

	double rcbZ;
} RgbColorBlock;

typedef struct RgbCube {
	int rcRedSteps;
	int rcGreenSteps;
	int rcBlueSteps;

	int rcRedStep;
	int rcGreenStep;
	int rcBlueStep;

	RGB8Color rcSplitValues;
	RGB8Color rcBSplitValues;
	int rcSplitColor; /* enum */

	AffineTransform3D rcAt;

	int rcColorBlockCount;
	RgbColorBlock *rcColorBlocks;

	RGB8Color rcBackColor;
	RGB8Color rcSelectedColor;
	int rcColorSelected;
} RgbCube;

typedef enum RgbCubeSplitColor {
	RCsplitNONE = 0,
	RCsplitRED,
	RCsplitGREEN,
	RCsplitBLUE,

	RCsplit_COUNT
} RgbCubeSplitColor;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void appInitRgbCube(RgbCube *rc);

void appCleanRgbCube(RgbCube *rc);

void appRedrawRgbCube(RgbCube *rc, int wide, int high,
		      const DocumentRectangle *drClip,
		      struct DrawingSurface *ds);

int appPrepareRgbCube(RgbCube *rc, struct DrawingSurface *ds, int redSteps,
		      int greenSteps, int blueSteps);

void appRotateRgbCube(RgbCube *rc, int mouseX, int mouseY, int wide, int high);

int appRgbCubeFindColor(RGB8Color *rgb8, int *pOnOutside, RgbCube *rc,
			int mouseX, int mouseY, int wide, int high);

void appRgbCubeSetSplit(RgbCube *rc, int splitColor,
			const RGB8Color *splitValues);

void appRgbCubeSelectColor(RgbCube *rc, const RGB8Color *rgb8);

void appRgbCubeRefreshSplit(RgbCube *rc, const RGB8Color *rgb8);

#endif
