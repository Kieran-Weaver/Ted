#ifndef UTIL_RANGES_H
#define UTIL_RANGES_H

/************************************************************************/
/*									*/
/*  Procedure declarations.						*/
/*									*/
/************************************************************************/

int utilParseRanges(unsigned char *pages, int count, const char *str);

int utilParseRange(int *pPage0, int *pPage1, const char *str);

int utilRangesString(char *str, int maxSize, const unsigned char *pages,
		     int size);

int utilRangesGetFirst(const unsigned char *pages, int count);

int utilRangesGetLast(const unsigned char *pages, int count);

int utilRangesCountOn(const unsigned char *pages, int count);

#endif /*  UTIL_RANGES_H  */
