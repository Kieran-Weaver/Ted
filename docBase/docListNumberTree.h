/************************************************************************/
/*									*/
/*  Manage the numbers in bulleted and numbered lists.			*/
/*									*/
/************************************************************************/

#ifndef DOC_LIST_NUMBER_TREE_H
#define DOC_LIST_NUMBER_TREE_H

typedef struct ListNumberTreeNode {
	/**
				 *  The paragraph number in the document tree
				 *  that this node refers to. Internal nodes 
				 *  in the tree have lntnParaNr == -1.
				 *  Internal nodes are nodes that implement 
				 *  levels that are skipped in the indentation 
				 *  of the tree.
				 */
	int lntnParaNr;
	/**
				 *  The array of children.
				 */
	struct ListNumberTreeNode **lntnChildren;
	/**
				 *  The number of children.
				 */
	int lntnChildCount;
	/**
				 *  != 0 if and only if this node is a leaf.
				 */
	unsigned char x_lntnIsLeaf;
} ListNumberTreeNode;

typedef struct ListNumberTrees {
	ListNumberTreeNode *lntTrees;
	int lntTreeCount;
} ListNumberTrees;

typedef int (*LIST_TREE_FUNC)(int ilvl, void *through);

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void docInitListNumberTreeNode(ListNumberTreeNode *lntn);
void docCleanListNumberTreeNode(ListNumberTreeNode *lntn);

void docInitListNumberTrees(ListNumberTrees *lnt);
void docCleanListNumberTrees(ListNumberTrees *lnt);
int docClaimListNumberTrees(ListNumberTrees *lnt, int count);

void docShiftListNodeReferences(ListNumberTreeNode *root, int paraFrom,
				int paraShift);

void docShiftListTreeReferences(ListNumberTrees *lnt, int paraFrom,
				int paraShift);

ListNumberTreeNode *docGetListNumberTree(ListNumberTrees *lnt, int ls);

int docListNumberTreeInsertParagraph(ListNumberTreeNode *root, int ilvl,
				     int paraNr);

int docListNumberTreesInsertParagraph(ListNumberTrees *lnt, int ls, int ilvl,
				      int paraNr);

int docListNumberTreeDeleteParagraph(ListNumberTreeNode *root, int paraNr);

int docListNumberTreesDeleteParagraph(ListNumberTrees *lnt, int ls, int paraNr);

int docListNumberTreeGetNumberPath(int *numberPath, ListNumberTreeNode *root,
				   int ilvl, int paraNr);

int docListNumberTreeGetPrevPath(int *numberPath, int *pLevel,
				 ListNumberTreeNode *root, int paraNr);

int docListNumberTreeForAll(ListNumberTreeNode *root, LIST_TREE_FUNC forOne,
			    void *through);

#endif
