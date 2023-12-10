#ifndef IND_H /*  {{	*/
#define IND_H

#include <sioGeneral.h>
#include "indSpellChecker.h"

/************************************************************************/
/*									*/
/*  A possible 'word' that is collected during the scan of the input.	*/
/*									*/
/************************************************************************/
#define FORM_MAX 60

typedef struct PossibleWord {
	int pwStartAt;
	int pwInsertionPoint;
	int pwRejectedAt;
	int pwAcceptedAt;
	char pwForm[FORM_MAX + 2];

	struct PossibleWord *pwNext;
} PossibleWord;

typedef struct SpellScanJob {
	PossibleWord *ssjPossibleWords;
	int ssjPossibleWordCount;
} SpellScanJob;

/************************************************************************/
/*									*/
/*  Operating environment for a checker.				*/
/*									*/
/************************************************************************/

typedef struct SpellCheckContext {
	const char *sccDictionaryPrefix;
	void *sccStaticInd;
	void *sccForgotInd;
	void *sccLearntInd;
} SpellCheckContext;

typedef struct SpellGuessContext {
	IndGuessList *sgcGuessList;
	SpellCheckContext *sgcCheckContext;
} SpellGuessContext;

/************************************************************************/

typedef int (*IndForAllFun)(void *through, int dir, int tnFrom, int tnTo,
			    unsigned short key, int toAccepts);

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void *indMake(void);
void *indRead(const char *filename, int readOnly);

int indPutUtf8(void *ind, const char *key);

int indPutUtf16(void *ind, const unsigned short *key);

int indPutSuffixUtf16(void *voidind, const unsigned short *key);

int indForget(void *ind, const char *key);
int indGetUtf8(int *, void *ind, const char *key);
int indGetUtf16(int *, void *ind, const unsigned short *key);
void indFree(void *ind);
int indWrite(void *ind, const char *filename);
void *indMini(void *ind);
void *indRenumber(void *ind);

int indGuess(void *voidind, const char *word, SpellGuessContext *sgc,
		    int how);

int indGetWord(int *pWhatWasShifted, void *voidind, const char *word,
		      int asPrefix);

int indGuessWord(void *voidind, const char *word,
			SpellGuessContext *sgc);

void indLogPossibilities(SpellScanJob *ssj);

int indNewPossibility(SpellScanJob *ssj, int position);

void indAddCharacterToPossibilities(SpellScanJob *ssj, int c);

int indCountPossibilities(SpellScanJob *ssj, SpellCheckContext *scc,
				 int position, int rejectPrefices);

void indRejectPossibilities(int *pAcceptedPos, int acceptedPos,
				   SpellScanJob *ssj);

PossibleWord *indMaximalPossibility(SpellScanJob *ssj);

int indMoveWord(void *fromInd, void *toInd, const char *word);

int indReadPrivateDictionary(SimpleInputStream *sis, void **pLearntInd,
				    void **pForgotInd);

int indLearnWord(SimpleOutputStream *sos, void *learntInd,
			void *forgotInd, const char *word);

int indForgetWord(SimpleOutputStream *sos, void *learntInd,
			 void *forgotInd, const char *word);

void indInitSpellScanJob(SpellScanJob *ssj);
void indCleanSpellScanJob(SpellScanJob *ssj);

void indInitSpellGuessContext(SpellGuessContext *sgc, IndGuessList *igl,
				     SpellCheckContext *scc);
void indCleanSpellGuessContext(SpellGuessContext *sgc);

void indInitSpellCheckContext(SpellCheckContext *scc);
void indCleanSpellCheckContext(SpellCheckContext *scc);

void indSpellIso1CharacterKinds(SpellCheckContext *scc);
void indSpellIso2CharacterKinds(SpellCheckContext *scc);
void indSpellIso7CharacterKinds(SpellCheckContext *scc);
void indSpellIso5CharacterKinds(SpellCheckContext *scc);
void indSpellKoi8rCharacterKinds(SpellCheckContext *scc);

int indCollectGuesses(IndGuessList *igl, SpellCheckContext *scc,
			     const char *word);

int indSpellSetup(SpellChecker *sc, SpellComplain complain,
			 void *through);

void indDump(void *voidind);

int indAddSuffixUtf16(void *voidind, const unsigned short *prefix,
			     int suffixNumber);

#endif /*	IND_H						    }}	*/
