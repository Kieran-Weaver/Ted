/************************************************************************/
/*									*/
/*  Mapping of string values to (void *)pointers.			*/
/*									*/
/************************************************************************/

#ifndef UTIL_TREE_H
#define UTIL_TREE_H

typedef int (*UTIL_TREE_CALLBACK)(const char *key, void *val, void *through);

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

/**
					 *  Build a tree.
					 *  @param ownKeys If ownKeys is 
					 *	true, the tree will keep 
					 *	its own copy of the keys.
					 *	If ownKeys is false, the tree
					 *	will use the key values 
					 *	internally. In that case, it is
					 *	the responsibility of the caller
					 *	to keep the keys alive while 
					 *	they own values in the tree and
					 *	to free them after that.
					 */
void *utilTreeMakeTree(int ownKeys);

/**/
int utilTreeStoreValue(void *tree, void **pPreviousValue,
		       const char **pStoredKey, const char *key, void *val);

/**/
void *utilTreeGetLT(void *tree, const char **pKey, const char *key);

void *utilTreeGetLE(void *tree, const char **pKey, const char *key);

void *utilTreeGetEQ(const void *tree, const char **pKey, const char *key);

void *utilTreeGetGE(void *tree, const char **pKey, const char *key);

void *utilTreeGetGT(void *tree, const char **pKey, const char *key);

/**/
void *utilTreeGetFirst(void *tree, const char **pKey);

void *utilTreeGetPrevious(void *tree, const char **pKey);

void *utilTreeGetCurrent(void *tree, const char **pKey);

void *utilTreeGetNext(void *tree, const char **pKey);

void *utilTreeGetLast(void *tree, const char **pKey);

/**/
int utilTreeDeleteEQ(void *tree, const char *key, UTIL_TREE_CALLBACK callback,
		     void *through);

int utilTreeDeleteCurrent(void *tree, UTIL_TREE_CALLBACK callback,
			  void *through);

/**/
int utilTreeForAll(void *tree, int stopOnFailure, UTIL_TREE_CALLBACK callback,
		   void *through);

/**/
int utilTreeFreeTree(void *tree, UTIL_TREE_CALLBACK callback, void *through);

/**/
int utilTreeFreeValue(const char *key, void *val, void *through);

#endif /*	UTIL_TREE_H	*/
