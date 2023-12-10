/************************************************************************/
/*									*/
/*  Administration of paper sizes					*/
/*									*/
/************************************************************************/

const char *utilPaperDefaultSize(void);

int utilPaperGetInfoByNumber(int n, int *pWidth, int *pHeight,
				    const char **pLabel);

int utilPaperGetNumberBySize(int width, int height);

int utilPaperSizeFromString(int *pFormat, int *pWidth, int *pHeight,
				   int unitType, const char *paperString);
