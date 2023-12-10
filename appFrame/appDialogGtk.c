#include <config.h>

#include <stdio.h>

#include "appFrame.h"

#include <appDebugon.h>


#include <gdk/gdkkeysyms.h>

/************************************************************************/
/*									*/
/*  Make a dialog with a vertical organisation.				*/
/*									*/
/************************************************************************/

void appMakeVerticalDialog(AppDialog *ad, APP_WIDGET *pColumn,
			   EditApplication *ea,
			   APP_CLOSE_CALLBACK_T closeCallback,
			   APP_DESTROY_CALLBACK_T destroyCallback,
			   void *through)
{
	APP_WIDGET shell;
	APP_WIDGET column;


	shell = gtk_dialog_new();

	gtk_window_set_position(GTK_WINDOW(shell), GTK_WIN_POS_CENTER);

	if (closeCallback) {
		gtk_signal_connect(GTK_OBJECT(shell), "delete_event",
				   (GtkSignalFunc)closeCallback, through);
	}

	if (destroyCallback) {
		gtk_signal_connect(GTK_OBJECT(shell), "destroy_event",
				   (GtkSignalFunc)destroyCallback, through);
	}

	gtk_container_set_border_width(GTK_CONTAINER(shell), WINDOW_BORDER_GTK);

	column = gtk_bin_get_child(GTK_BIN(shell));

	ad->adAccelGroup = gtk_accel_group_new();
	gtk_window_add_accel_group(GTK_WINDOW(shell), ad->adAccelGroup);

	ad->adTopWidget = shell;
	*pColumn = column;
	return;
}

static void appGuiGtkDialogBreak(GtkWidget *w, GdkEvent *event, void *voidad)
{
	AppDialog *ad = (AppDialog *)voidad;

	ad->adCloseId = 0;

	gtk_main_quit();

	return;
}

void appGuiRunDialog(AppDialog *ad, int initial, EditApplication *ea)
{
	gtk_window_set_modal(GTK_WINDOW(ad->adTopWidget), TRUE);

	ad->adResponse = initial;

	ad->adCloseId = gtk_signal_connect(GTK_OBJECT(ad->adTopWidget),
					   "delete_event",
					   (GtkSignalFunc)appGuiGtkDialogBreak,
					   (void *)ad);

	gtk_main();

	if (ad->adCloseId) {
		gtk_signal_disconnect(GTK_OBJECT(ad->adTopWidget),
				      ad->adCloseId);

		if (ad->adResponse == AQDrespCLOSED) {
			appGuiHideDialog(ad);
		}

		ad->adCloseId = 0;
	}

	if (ad->adResponse != AQDrespCLOSED) {
		gtk_window_set_modal(GTK_WINDOW(ad->adTopWidget), FALSE);
	}

	return;
}

void appGuiBreakDialog(AppDialog *ad, int response)
{
	ad->adResponse = response;
	gtk_main_quit();
}

void appGuiSetDefaultButtonForDialog(AppDialog *ad, APP_WIDGET button)
{
	unsigned int keyMask = 0;
	unsigned int keyCode = GDK_Return;

	gtk_widget_add_accelerator(button, "clicked", ad->adAccelGroup, keyCode,
				   (GdkModifierType)keyMask, GTK_ACCEL_VISIBLE);
}

void appGuiSetCancelButtonForDialog(AppDialog *ad, APP_WIDGET button)
{
	unsigned int keyMask = 0;
	unsigned int keyCode = GDK_Escape;

	gtk_widget_add_accelerator(button, "clicked", ad->adAccelGroup, keyCode,
				   (GdkModifierType)keyMask, GTK_ACCEL_VISIBLE);
}

void appGuiShowDialog(EditApplication *ea, AppDialog *ad, APP_WIDGET relative)
{
	gint x;
	gint y;
	gint wide;
	gint high;

	if (relative) {
		gtk_window_set_transient_for(GTK_WINDOW(ad->adTopWidget),
					     GTK_WINDOW(relative));

		gtk_window_set_position(GTK_WINDOW(ad->adTopWidget),
					GTK_WIN_POS_NONE);

		gtk_widget_realize(ad->adTopWidget);

		gdk_window_get_position(relative->window, &x, &y);
		gdk_window_get_size(relative->window, &wide, &high);

		gdk_window_move(ad->adTopWidget->window, x + wide / 5,
				y + high / 5);
	} else {
		gtk_window_set_position(GTK_WINDOW(ad->adTopWidget),
					GTK_WIN_POS_CENTER);
	}

	gtk_widget_show(ad->adTopWidget);
}

void appGuiHideDialog(AppDialog *ad)
{
	gtk_widget_hide(ad->adTopWidget);

	gtk_window_set_transient_for(GTK_WINDOW(ad->adTopWidget),
				     (GtkWindow *)0);
}

