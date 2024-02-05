#ifndef APP_UNIT_H
#define APP_UNIT_H

/************************************************************************/
/*									*/
/*  Unit types and conversions between units.				*/
/*									*/
/************************************************************************/

struct tm;

#define UNITtyCM 1
#define UNITtyINCH 2
#define UNITtyPOINTS 3
#define UNITtyPICAS 4
#define UNITtyMM 5

/************************************************************************/
/*									*/
/*  Procedure declarations.						*/
/*									*/
/************************************************************************/

int appUnitTypeInt(const char *unitTypeString);

const char *appUnitTypeString(int unitTypeInt);

double appUnitFromTwips(int twips, int unitTypeInt);

double appUnitToTwips(double units, int unitTypeInt);

int appWordFormatDate(char *target, int maxlen, const struct tm *tm,
		      const char *wordPicture);

void utilInvalidateTime(struct tm *tm);

#endif /*  APP_UNIT_H  */
