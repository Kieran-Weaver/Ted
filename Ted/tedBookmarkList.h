/************************************************************************/
/*									*/
/*  Ted: The list of bookmarks on the Bookmark and Hyperlink tools.	*/
/*									*/
/************************************************************************/

#ifndef TED_BOOKMARK_LIST_H
#define TED_BOOKMARK_LIST_H

#include <appFrame.h>
#include <docBuf.h>

typedef struct BookmarkList {
	APP_WIDGET blMarkLabelWidget;
	APP_WIDGET blMarkTextWidget;

	APP_WIDGET blMarkListWidget;

	unsigned char blIsLocal;
	unsigned char blMarkChosenExists;
} BookmarkList;

/************************************************************************/
/*									*/
/*  Routine Declarations.						*/
/*									*/
/************************************************************************/

void tedInitBookmarkList(BookmarkList *bl);

void tedFillBookmarkList(BookmarkList *bl, int includeTocMarks,
			 const BufferDocument *bd);

void tedBookmarkFindChosen(BookmarkList *bl, EditApplication *ea,
			   const MemoryBuffer *mbChosen);

void tedBookmarkUpdateSelectionInList(BookmarkList *bl,
				      const MemoryBuffer *mbChosen);

void tedBookmarkListToText(BookmarkList *bl, MemoryBuffer *mbChosen,
			   void *voidlcs, APP_WIDGET w);

#endif /*  TED_BOOKMARK_LIST_H  */
