/************************************************************************/
/*									*/
/*  Information on sets of characters or glyphs in fonts.		*/
/*									*/
/************************************************************************/

#ifndef PS_GLYPHS_H
#define PS_GLYPHS_H

/************************************************************************/
/*									*/
/*  Declarations.							*/
/*									*/
/************************************************************************/

const char *const psAppleTtfGlyphNames[258]; /*  258 !  */

const char *psUnicodeToGlyphName(int unicode);
int psGlyphNameToUnicode(const char *glyphname);

#endif
