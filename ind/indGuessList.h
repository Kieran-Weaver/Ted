#ifndef IND_GUESSS_LIST_H /*  {{	*/
#define IND_GUESSS_LIST_H

/************************************************************************/
/*									*/
/*  A list of Guesses.							*/
/*									*/
/************************************************************************/

typedef struct IndGuessScore {
	unsigned char *igsWord;
	int igsScore;
} IndGuessScore;

typedef struct IndGuessList {
	int iglGuessCount;
	IndGuessScore *iglGuesses;
} IndGuessList;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int indAddGuess(IndGuessList *igl, const char *word, int score);

void indCleanGuessList(IndGuessList *igl);
void indEmptyGuessList(IndGuessList *igl);
void indInitGuessList(IndGuessList *igl);
void indSortGuesses(IndGuessList *igl);

#endif /*	IND_GUESSS_LIST_H	    }}	*/
