#ifndef REG_H
#define REG_H

/* Regular expressions via PCRE */

#define REGflagESCAPE_REGEX (1 << 0)
#define REGflagCASE_INSENSITIVE (1 << 1)

typedef void regProg;

#define REG_MAX_MATCH 9
typedef struct ExpressionMatch {
	/*  ! Size adapted to PCRE usage */
	int emMatches[2 + (2 * REG_MAX_MATCH) /*!*/ + 1 + REG_MAX_MATCH];
} ExpressionMatch;

int regGetMatch(int *pFrom, int *pPast, const ExpressionMatch *em, int n);

int regGetFullMatch(int *pFrom, int *pPast, const ExpressionMatch *em);

regProg *regCompile(const char *, int options);

void regFree(regProg *prog);

int regFindLeftToRight(ExpressionMatch *em, const regProg *prog,
		       const char *string, int fromByte, int byteLength);

int regFindRightToLeft(ExpressionMatch *em, const regProg *prog,
		       const char *string, int fromByte, int byteLength);

#endif
