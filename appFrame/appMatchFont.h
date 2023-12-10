/************************************************************************/
/*									*/
/*  Basic structures for a Gui document manipulator application.	*/
/*									*/
/************************************************************************/

#ifndef APP_MATCH_FONT_H
#define APP_MATCH_FONT_H

#include <utilDocFontList.h>
#include <textAttribute.h>
#include <psPostScriptFontList.h>

#ifdef __cplusplus
"C" {
#endif

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int appFcListFonts(PostScriptFontList *psfl);

AfmFontInfo *appFcGetFontInfoForAttribute(const char *familyName, int styleInt,
					  const IndexSet *unicodesUsed,
					  const TextAttribute *ta,
					  const PostScriptFontList *psfl);

AfmFontInfo *appGetFontInfo(const char *familyName, int styleInt,
				   const IndexSet *unicodesUsed,
				   const TextAttribute *ta,
				   const PostScriptFontList *psfl);

const AfmFontInfo *
appGetFontInfoForAttribute(const IndexSet **pUnicodesWanted,
			   const TextAttribute *ta, const DocumentFontList *dfl,
			   const PostScriptFontList *psfl);

int appFcGetFontMetrics(AfmFontInfo *afi);

int appGetDeferredFontMetrics(AfmFontInfo *afi);
int appGetDeferredFontMetricsForList(PostScriptFontList *psfl);

#ifdef __cplusplus
}
#endif

#endif
