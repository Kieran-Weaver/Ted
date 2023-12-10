#ifndef DOC_TABLE_RECTANGLE_H
#define DOC_TABLE_RECTANGLE_H

typedef struct TableRectangle {
	int trCol0;
	int trCol1;
	int trCol11;

	int trRow00;
	int trRow0;
	int trRow1;
	int trRow11;

	int trIsRowSlice;
	int trIsColSlice;
	int trIsTableSlice;
	int trIsWholeTable;
	int trIsSingleCell;

	int trCellColspan;
	int trCellRowspan;

	int trInTableHeader;
} TableRectangle;

/************************************************************************/
/*									*/
/*  Routine Declarations.						*/
/*									*/
/************************************************************************/

void docInitTableRectangle(TableRectangle *tr);

int docIntersectTableRectangle(TableRectangle *tr,
				      const TableRectangle *tr1,
				      const TableRectangle *tr2);

void docExpandTableRectangleToWholeRows(TableRectangle *tr);
void docExpandTableRectangleToWholeColumns(TableRectangle *tr);

#endif /*	DOC_TABLE_RECTANGLE_H	*/
