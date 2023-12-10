/************************************************************************/
/*									*/
/*  Implements a mapping between font names as implemented by the	*/
/*  GhostScript 'Fontmap' file.						*/
/*									*/
/************************************************************************/

int utilFontmapReadMap(const char *filename);

const char *utilFontmapGetEntry(const char *from);
