/************************************************************************/
/*									*/
/*  Lists: Diagnostic routines.						*/
/*									*/
/************************************************************************/

#ifndef DOC_DEBUG_LIST_NUMBER_TREE_H
#define DOC_DEBUG_LIST_NUMBER_TREE_H

#include "docListNumberTree.h"

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int docListListNumberNode(const ListNumberTreeNode *lntn);
int docCheckListNumberNode(const ListNumberTreeNode *lntn);

int docListNumberTreeLogPath(ListNumberTreeNode **path, int *nums,
				    int level);

int docListNumberTreeFindParagraph(int *pLevel,
					  ListNumberTreeNode **path, int *nums,
					  ListNumberTreeNode *root, int paraNr);

#endif /*	DOC_DEBUG_LIST_NUMBER_TREE_H	*/
