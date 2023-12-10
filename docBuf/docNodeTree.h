/************************************************************************/
/*									*/
/*  Manipulation of the node tree and navigation over it.		*/
/*									*/
/************************************************************************/

#ifndef DOC_NODE_TREE_H
#define DOC_NODE_TREE_H

/************************************************************************/
/*									*/
/*  Forward declarations of structs.					*/
/*									*/
/************************************************************************/

struct BufferDocument;
struct BufferItem;
struct DocumentTree;
struct RowProperties;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

void docFreeNode(struct BufferDocument *bd, struct DocumentTree *dt,
			struct BufferItem *bi);

struct BufferItem *docInsertNode(const struct BufferDocument *bd,
					struct BufferItem *parent, int n,
					int level);

void docDeleteNodes(struct BufferDocument *bd, struct DocumentTree *dt,
			   struct BufferItem *bi, int first, int count);

int docSplitGroupNode(struct BufferDocument *bd,
			     struct BufferItem **pNewBi,
			     struct BufferItem *oldBi, int n);

int docSplitGroupNodeAtLevel(struct BufferDocument *bd,
				    struct BufferItem **pBeforeNode,
				    struct BufferItem **pAfterNode,
				    struct BufferItem *splitNode, int n,
				    int level);

int docMergeGroupNodes(struct BufferItem *to, struct BufferItem *from);

struct BufferItem *docNextParagraph(struct BufferItem *bi);
struct BufferItem *docPrevParagraph(struct BufferItem *bi);

struct BufferItem *docNextSection(struct BufferItem *bi);
struct BufferItem *docPrevSection(struct BufferItem *bi);

void docDeleteNode(struct BufferDocument *bd, struct DocumentTree *dt,
			  struct BufferItem *bi);

void docInitNode(struct BufferItem *bi, struct BufferItem *parent,
			const struct BufferDocument *bd, int numberInParent,
			int level, int treeType);

struct BufferItem *docInsertRowNode(struct BufferDocument *bd,
					   struct BufferItem *sectBi, int n,
					   const struct RowProperties *rp,
					   int textAttrNr);

struct BufferItem *docGetCellNode(struct BufferItem *bi);
struct BufferItem *docGetRowNode(struct BufferItem *bi);
struct BufferItem *docGetRowLevelNode(struct BufferItem *bi);
struct BufferItem *docGetSectNode(struct BufferItem *bi);

int docRowNesting(const struct BufferItem *bi);
int docTableNesting(const struct BufferItem *bi);
void docSetParaTableNesting(struct BufferItem *paraNode);

int docValidChildLevel(int parentLevel, int childLevel);

struct BufferItem *docMakeNode(void);

struct BufferItem *docGetBodySectNode(struct BufferItem *bi,
					     const struct BufferDocument *bd);

#endif
