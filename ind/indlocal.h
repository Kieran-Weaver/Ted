#include "ind.h"

#define TNfUSED 1
#define TNfACCEPTS 2
#define TNfREAD_ONLY 4

#define INDMAGIC 0xdfadfadf
#define INDMAGIC_R 0xdffaaddf

#define TLsBLOCK 5000
#define TNsBLOCK 5000

#define TLgFREE 0xfffffe
#define TLgUSED 0xffffff

typedef struct TrieNode {
	int tn_transitions;
	unsigned short tn_ntrans;
	unsigned char tn_flags;
	unsigned char tn_unused;
} TrieNode;

typedef struct TrieLink {
	unsigned int tl_key : 16;
	unsigned int tl_to : 32;
} TrieLink;

/************************************************************************/
/*									*/
/*  An 'IND' struct.							*/
/*									*/
/*  Offsets to the location in the file header are prepended as a	*/
/*  comment.								*/
/*									*/
/************************************************************************/

typedef struct IND {
	/*  0  */ int ind_magic; /*  To avoid trouble	*/

	/*  -  */ int ind_fd; /*  For future use.	*/

	/*  8  */ int ind_start;
	/*  -  */ int ind_readonly;

	/*  -  */ TrieNode *ind_nodes;
	/*  -  */ TrieNode **indNodePages;
	/* 24  */ int indNodeCount;
	/* 28  */ int indAllocatedNodes;

	/*  -  */ TrieLink *ind_links;
	/*  -  */ TrieLink **indLinkPages;
	/* 40  */ int indAllocatedLinks;
	/****************************************/
	/*  Range of free slots to optimize	*/
	/*  searches. Actually, the numbers are	*/
	/*  candidates: the slot may have been	*/
	/*  used for a node.			*/
	/****************************************/
	/* 44  */ int indFirstFreeLinkSlot;
	/* 48  */ int indLastHeadLinkSlot;

	/* 52  */ unsigned char *indMmappedFile;
	/* 56  */ unsigned long indMmappedSize;
} IND;

#define NODE(ind, tn) ((ind)->indNodePages[(tn) / TNsBLOCK] + ((tn) % TNsBLOCK))
#define LINK(ind, tl) ((ind)->indLinkPages[(tl) / TLsBLOCK] + ((tl) % TLsBLOCK))

/************************************************************************/
/*									*/
/*  Shift modes for producing spell guesses.				*/
/*									*/
/************************************************************************/

#define INDhASIS 1 /*  knudde -> knudde		*/
#define INDhFIRSTUP 2 /*  Knudde -> knudde		*/
#define INDhIJUP 3 /*  IJsco -> ijsco		*/
#define INDhALLUP 4 /*  KNUDDE -> knudde		*/
#define INDhTAILUP 5 /*  EDAM -> Edam		*/
#define INDhIJTAILUP 6 /*  IJMUIDEN -> IJmuiden	*/

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

IND *indINDmake(int readOnly);
IND *indINDread(const char *filename, int readOnly);

int indINDputUtf8(IND *ind, int tn, const char *key);

int indINDforall(IND *ind, int tn, void *through, IndForAllFun fun);

int indINDforget(IND *ind, const char *key);

void indINDfree(IND *ind);

int indINDwrite(IND *ind, const char *filename);

int indTNmake(IND *ind);
void indTNfree(IND *ind, int tn);
int indTLalloc(IND *ind, int old, int n);
void indTLfree(IND *ind, int tl);
IND *indINDmini(IND *ind);
void indTLprint(IND *, int);
void indTNprint(IND *, int);
void indINDprint(IND *);

void indTLprint2(IND *ind, int from, int upto);

int indINDgetUtf8(int *paccept, IND *ind, int tn, const char *key);

int indINDstep(int *pTrans, IND *ind, int tn, int sym);

int indINDguess(IND *ind, const unsigned short *ucods, int len,
		SpellGuessContext *sgc, int how);

int indWRDget(IND *ind, int *pWhatWasShifted, const char *word, int asPrefix);

int indWRDguess(IND *ind, unsigned short *ucods, int ulen,
		SpellGuessContext *sgc);

IND *indINDrenumber(IND *ind);

void indINDcount(IND *ind);
int indITwalk(IND *ind);
int indTLwalk(IND *ind);

int indShiftWord(char *target, const unsigned short *ucods, int ulen, int how);

int indINDaddSuffix(IND *ind, int tnTo, int tnSuf);
