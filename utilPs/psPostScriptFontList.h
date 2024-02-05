/************************************************************************/
/*									*/
/*  Data structures that describe postscript fonts.			*/
/*									*/
/************************************************************************/

#include "psFontFamily.h"
#ifndef PS_FONT_LIST_H
#define PS_FONT_LIST_H

typedef struct PostScriptFontList {
	PsFontFamily **psflFamilies;
	int psflFamilyCount;
	AfmFontInfo **psflInfos;
	int psflInfoCount;
	int psflAvoidFontconfig;
	/*  Do not use fontconfig. This is a	*/
	/*  strange place to store this piece	*/
	/*  of information. However: everywhere	*/
	/*  where we need it, we have a font	*/
	/*  list available.			*/

	void *psflFontNameToInfo;
	void *psflFontFileToInfo;
} PostScriptFontList;

/************************************************************************/
/*									*/
/*  Declarations.							*/
/*									*/
/************************************************************************/

void psInitPostScriptFontList(PostScriptFontList *psfl);
void psCleanPostScriptFontList(PostScriptFontList *psfl);

int psPostScriptFontListAddInfo(PostScriptFontList *psfl, AfmFontInfo *afi);

int psPostScriptFontListAddFamily(PostScriptFontList *psfl, PsFontFamily *aff);

int psPostScriptFontListInfosToFamilies(PostScriptFontList *psfl);

int psPostScriptFontListGetFamilyByName(const PostScriptFontList *psfl,
					const char *name);

AfmFontInfo *
psPostScriptFontListGetFontInfoByFaceFile(const PostScriptFontList *psfl,
					  const char *file);

int psPostScriptFontListSetFontInfoForFaceFile(PostScriptFontList *psfl,
					       AfmFontInfo *afi,
					       const char *file);

AfmFontInfo *
psPostScriptFontListGetFontInfoByFontName(const PostScriptFontList *psfl,
					  const char *name);

#endif
