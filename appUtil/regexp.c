/* Regular expressions via PCRE */

#include <config.h>
#include <string.h>
#include <reg.h>
#define PCRE2_CODE_UNIT_WIDTH 8
#include <pcre2.h>
#include <appDebugon.h>

static char *regEscape(const char *pattern)
{
	static const char escape[] = "\\^$.[|()?*+{";
	int l = 2 * strlen(pattern);
	char *escaped = (char *)malloc(2 * l + 1);

	if (escaped) {
		const char *from = pattern;
		char *to = escaped;

		while (*from) {
			if (memchr(escape, *from, sizeof(escape))) {
				*(to++) = '\\';
			}

			*(to++) = *(from++);
		}

		*to = '\0';
	}

	return escaped;
}

regProg *regCompile(const char *pattern, int options)
{
	pcre2_code *re;
	int error = 0;
	PCRE2_SIZE erroffset = 0;
	unsigned char errormsg[256];
	char *escaped = (char *)0;

	if (options & REGflagESCAPE_REGEX) {
		escaped = regEscape(pattern);
		if (!escaped) {
			SXDEB(pattern, escaped);
			return (regProg *)0;
		}
		pattern = escaped;
	}

	re = pcre2_compile((PCRE2_SPTR8)pattern, PCRE2_ZERO_TERMINATED,
			   PCRE2_UTF, &error, &erroffset, NULL);

	if (!re) {
		pcre2_get_error_message(error, errormsg, sizeof(errormsg));
		XSSDEB(re, (char *)errormsg, pattern + erroffset);
	}

	if (escaped) {
		free(escaped);
	}

	return (void *)re;
}

int regFindLeftToRight(ExpressionMatch *em, const regProg *prog,
		       const char *string, int fromByte, int byteLength)
{
	pcre2_match_data *match_data;
	PCRE2_SIZE *ovector;
	int res;
	int i;

	match_data =
		pcre2_match_data_create_from_pattern((pcre2_code *)prog, NULL);

	res = pcre2_match((pcre2_code *)prog, (PCRE2_SPTR8)string, byteLength,
			  fromByte, PCRE2_NO_UTF_CHECK, match_data, NULL);

	ovector = pcre2_get_ovector_pointer(match_data);

	if (res <= 0) {
		pcre2_match_data_free(match_data);
		return 0;
	}

	memset(em->emMatches, 0, sizeof(em->emMatches));

	for (i = 0; i < (res * 2); i++) {
		em->emMatches[i] = ovector[i];
	}

	pcre2_match_data_free(match_data);

	return 1;
}

int regFindRightToLeft(ExpressionMatch *em, const regProg *prog,
		       const char *string, int fromByte, int byteLength)
{
	int res;

	pcre2_match_data *match_data;
	PCRE2_SIZE *ovector;

	match_data =
		pcre2_match_data_create_from_pattern((pcre2_code *)prog, NULL);

	int cur = fromByte;
	int i;

	while (cur > 0) {
		res = pcre2_match((pcre2_code *)prog, (PCRE2_SPTR8)string,
				  fromByte, cur,
				  PCRE2_NO_UTF_CHECK | PCRE2_ANCHORED,
				  match_data, NULL);

		if (res > 0)
			break;

		cur--;
	}

	if ((res <= 0) || (cur <= 0)) {
		/* Error */
		pcre2_match_data_free(match_data);
		return 0;
	}

	ovector = pcre2_get_ovector_pointer(match_data);
	memset(em->emMatches, 0, sizeof(em->emMatches));

	for (i = 0; i < (res * 2); i++) {
		em->emMatches[i] = ovector[i];
	}

	pcre2_match_data_free(match_data);

	return 1;
}

int regGetMatch(int *pFrom, int *pPast, const ExpressionMatch *em, int n)
{
	if (n >= REG_MAX_MATCH) {
		LLDEB(n, REG_MAX_MATCH);
		return -1;
	}

	if (em->emMatches[0] >= 0 && em->emMatches[2 + n + 0] >= 0) {
		*pFrom = em->emMatches[2 + n + 0];
		*pPast = em->emMatches[2 + n + 1];
		return 0;
	}

	return -1;
}

int regGetFullMatch(int *pFrom, int *pPast, const ExpressionMatch *em)
{
	if (em->emMatches[0] >= 0) {
		*pFrom = em->emMatches[0];
		*pPast = em->emMatches[1];
		return 0;
	}

	return -1;
}

void regFree(regProg *prog)
{
	pcre2_code_free((pcre2_code_8 *)prog);
}
