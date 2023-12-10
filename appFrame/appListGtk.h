#include <config.h>
#include "appGuiBase.h"


typedef struct ListAction {
	GtkWidget *laWidget;
	GtkWidget *laParentWidget;
	GtkAdjustment *laAdjustment;
	APP_LIST_CALLBACK_T laListCallback;
	APP_BUTTON_CALLBACK_T laActionCallback;
	void *laThrough;

	int laListHigh;
	int laParentHigh;
	int laItemCount;
	int laSelectedPosition;
} ListAction;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

GtkWidget *appListGtkMakeParent(GtkAdjustment **pVAdjustment,
				       GtkWidget *column);

void appListGtkSetVisibleSize(GtkWidget *tree,
				     GtkWidget *scrolled_window,
				     int visibleItems);

ListAction *appListGtkSetCallbacks(GtkWidget *tree,
					  GtkWidget *scrolled_window,
					  GtkAdjustment *adjustment,
					  APP_LIST_CALLBACK_T listCallback,
					  APP_BUTTON_CALLBACK_T actionCallback,
					  void *through);

ListAction *appListGtkGetListAction(GtkWidget *widget);

void appGuiGtkSetListAdjustment(ListAction *la, int position);

