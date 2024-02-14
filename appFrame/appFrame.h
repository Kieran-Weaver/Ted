/************************************************************************/
/*									*/
/*  Basic structures for a Gui document manipulator application.	*/
/*									*/
/************************************************************************/

#ifndef APP_FRAME_H
#define APP_FRAME_H

#include <stdio.h>
#include "appGuiBase.h"
#include "appGuiResource.h"
#include <sioGeneral.h>
#include <geo2DInteger.h>
#include <utilDocumentGeometry.h>
#include <utilPrinter.h>
#include "appIcons.h"
#include "guiWidgets.h"
#include <drawDrawingSurface.h>
#include <psPostScriptFontList.h>
#ifdef __cplusplus
extern "C" {
#endif

struct PrintGeometry;
struct PrintJob;

/************************************************************************/
/*									*/
/*  For configuring texts of 'Really' dialogs.				*/
/*									*/
/************************************************************************/

typedef struct AppFileMessageResources {
	/********************************/
	/*  Format for 'New' title	*/
	/********************************/
	char *afmrNamelessTitleFormat;
	/********************************/
	/*  Really Close? Dialog.	*/
	/********************************/
	char *afmrReallyCloseQuestion;
	char *afmrReallyCloseSaveIt;
	char *afmrReallyCloseDontSave;
	char *afmrReallyCloseCancel;
	/********************************/
	/*  Really Quit? Dialog.	*/
	/********************************/
	char *afmrReallyQuitQuestion;
	char *afmrReallyQuitReview;
	char *afmrReallyQuitAnyway;
	char *afmrReallyQuitCancel;
	/********************************/
	/*  Messages about  a file.	*/
	/********************************/
	char *afmrFileNoAccess;
	char *afmrFileReadOnly;
	char *afmrNoSuchFileMessage;
	char *afmrFileNotWritable;
	char *afmrMakeItQuestion;
} AppFileMessageResources;

typedef struct AppMenuItem {
	const char *amiTextResName;
	const char *amiItemText;

	const char *amiKeyResName;
	const char *amiKey;

	const char *amiKeyTextResName;
	const char *amiKeyText;

	MenuItemType amiItemType;
	APP_MENU_CALLBACK_T amiCallback;
	APP_WIDGET amiOptionWidget;
} AppMenuItem;

/************************************************************************/
/*									*/
/*  Kinds of files that an application can open.			*/
/*									*/
/************************************************************************/

#define APPFILE_CAN_OPEN 0x01
#define APPFILE_CAN_SAVE 0x02
#define APPFILE_IS_BASIC_TYPE 0x04
#define APPFILE_HIDE_OPEN 0x08

typedef struct AppFileExtension {
	const char *afeId;
	const char *afeFilter;
	const char *afeDescription;
	const char *afeExtension;
	unsigned int afeUseFlags;
} AppFileExtension;

typedef struct SelectRectangle {
	int srDirection;
#define DOCselNONE 0

#define DOCselN 1
#define DOCselE 2
#define DOCselS 3
#define DOCselW 4

	DocumentRectangle srSelected;
	DocumentRectangle srLTM; /* left/top margins */
	DocumentRectangle srRBM; /* right/bottom margins */
} SelectRectangle;

typedef struct EditDocument {
	struct EditApplication *edApplication;

	MemoryBuffer edFilename;
	MemoryBuffer edTitle;
	int edFormat;
	int edFileReadOnly;
	/**
				 *  Unique number. Can be used to distinguish
				 *  EditDocuments wilhout remembering pointers
				 */
	unsigned int edDocumentId;

	AppToplevel edToplevel;

	APP_WIDGET edMenuBar;
	APP_WIDGET edMainWindow;
	APP_WIDGET edFileMenu;
	APP_WIDGET edFileMenuButton;
	APP_WIDGET edFileCloseOption;
	APP_WIDGET edEditMenu;
	APP_WIDGET edEditMenuButton;
	APP_WIDGET edWindowMenu;
	APP_WIDGET edWindowMenuButton;
	APP_WIDGET edHelpMenu;
	APP_WIDGET edHelpMenuButton;

	APP_WIDGET edToolbar;
	APP_WIDGET edScrolledWindow;
	APP_WIDGET edVerticalScrollbar;
	APP_WIDGET edHorizontalScrollbar;
	APP_WIDGET edWorkWidget;
	GtkAdjustment *edVerticalAdjustment;
	GtkAdjustment *edHorizontalAdjustment;
	DocumentWidget edDocumentWidget;
	struct DrawingSurface *edDrawingSurface;

	APP_WIDGET edLeftRulerWidget;
	APP_WIDGET edTopRulerWidget;
	APP_WIDGET edRightRulerWidget;
	APP_WIDGET edBottomRulerWidget;

	void *edLeftRuler;
	void *edTopRuler;
	void *edRightRuler;
	void *edBottomRuler;

	int edLeftRulerWidePixels;
	int edTopRulerHighPixels;
	int edRightRulerWidePixels;
	int edBottomRulerHighPixels;

	int edHasBeenChanged;
	int edIsReadonly;
	int edIsVisible;

	/**
				     *  The (pixel) rectangle that the whole
				     *  document would occupy on screen.
				     *  I.E: On a huge screen without 
				     *  scrollbars. X0 and X0 are 0 by 
				     *  definition.
				     */
	DocumentRectangle edFullRect;
	/**
				     *  The (pixel) rectangle of the document
				     *  that is visible ob screen. Together 
				     *  with edFullRect, it determines the 
				     *  positions of the scrollbars.
				     */
	DocumentRectangle edVisibleRect;

	/**
				     *  The color to draw where the window is
				     *  not covered by the document.
				     */
	RGB8Color edBackgroundColor;

	void *edPrivateData;

	struct AppSelectionTargetType *edTargetTypes;
	int edTargetTypeCount;

	int edMapped; /*  Struggle with fvwm	*/
	int edNotYetDrawn; /*  For FirstVisible	*/

	SelectRectangle edSelectRectangle;
} EditDocument;

/************************************************************************/
/*									*/
/*  Special calls to the aplication.					*/
/*									*/
/************************************************************************/

typedef struct SpecialCall {
	const char *scCall;
	int (*scExecuteCall)(struct EditApplication *ea, const char *prog,
			     const char *call, int argc, char **argv);
	/****************************************/
	/*  Returns the number of parameters	*/
	/*  consumed or -1 on failure.		*/
	/****************************************/
} SpecialCall;

/************************************************************************/
/*									*/
/*  Describes the application.						*/
/*									*/
/*  1)  Descriptive members.						*/
/*  2)  Allocated at run time.						*/
/*									*/
/************************************************************************/

typedef struct EditApplication {
	/*  1  */
	const char *eaApplicationName;
	const char *eaOptionalComponents;
	const char *eaNameAndVersion;
	const char *eaReference;
	const char *eaPlatformCompiled;
	const char *eaHostDateCompiled;

	/**
			 *  The Application Icon
			 */
	const char *eaMainIcon;
	/**
			 *  The Image on the Splash Screen
			 */
	const char *eaMainPicture;
	AppFileExtension *eaFileExtensions;
	int eaFileExtensionCount;
	const char *eaDefaultFileFilter;
	void *eaResourceData;
	AppConfigurableResource *eaResourceTable;
	int eaResourceCount;
	AppConfigurableResource *eaFileMessageResourceTable;
	int eaFileMessageResourceCount;
	int eaCreateNewFromCommand;

	double eaMagnification;

	int eaLeftRulerWidthMM;
	int eaTopRulerHeightMM;
	int eaRightRulerWidthMM;
	int eaBottomRulerHeightMM;

	int eaLeftRulerWidthMultiple;
	int eaTopRulerHeightMultiple;
	int eaRightRulerWidthMultiple;
	int eaBottomRulerHeightMultiple;

	const char *eaUnitString;
	const char *eaPaperString;
	const char *eaLeftMarginString;
	const char *eaTopMarginString;
	const char *eaRightMarginString;
	const char *eaBottomMarginString;
	int eaUnitInt;
	DocumentGeometry eaDefaultDocumentGeometry;

	char **eaAppFileMenuText;
	AppMenuItem *eaAppFileMenuItems;
	int eaAppFileMenuItemCount;

	char **eaAppWinMenuText;
	AppMenuItem *eaAppWinMenuItems;
	int eaAppWinMenuItemCount;

	char **eaDocFileMenuText;
	AppMenuItem *eaDocFileMenuItems;
	int eaDocFileMenuItemCount;

	char **eaDocEditMenuText;
	AppMenuItem *eaDocEditMenuItems;
	int eaDocEditMenuItemCount;

	char **eaDocWindowMenuText;
	AppMenuItem *eaDocWindowMenuItems;
	int eaDocWindowMenuItemCount;

	char **eaDocHelpMenuText;
	AppMenuItem *eaDocHelpMenuItems;
	int eaDocHelpMenuItemCount;

	char **eaAppHelpMenuText;
	AppMenuItem *eaAppHelpMenuItems;
	int eaAppHelpMenuItemCount;

	void *(*eaMakePrivateData)(void);

	int (*eaMakeDocumentWidget)(struct EditApplication *ea,
				    EditDocument *ed);
	int (*eaOpenDocument)(struct EditApplication *ea, void *privateData,
			      int *pFormat, APP_WIDGET relative,
			      APP_WIDGET option, int readOnly, int suggestStdin,
			      int formatHint, const MemoryBuffer *filename);
	int (*eaNewDocument)(EditDocument *ed, const MemoryBuffer *filename);
	int (*eaLayoutDocument)(DocumentRectangle *drScreen,
				DocumentRectangle *drVisible, void *privateData,
				int format, struct DrawingSurface *ds,
				const PostScriptFontList *psfl,
				const DocumentGeometry *defDg);
	int (*eaFinishDocumentSetup)(EditDocument *ed);
	void (*eaDocumentFirstVisible)(EditDocument *ed);
	int (*eaCanSaveDocument)(const void *privateData, int format);
	int (*eaSaveDocument)(struct EditApplication *ea,
			      struct DrawingSurface *ds,
			      const void *privateData, int format,
			      const MemoryBuffer *documentTitle,
			      int suggestStdout, const MemoryBuffer *filename,
			      int isDocName);
	void (*eaFreeDocument)(void *privateData, int format);
	void (*eaSuggestPageSetup)(struct PrintGeometry *pg, void *privateData,
				   int sheetSize);
	int (*eaPrintDocument)(SimpleOutputStream *sos,
			       const struct PrintJob *pj,
			       const struct PrintGeometry *pg);
	void (*eaDrawRectangle)(EditDocument *ed, DocumentRectangle *drClip,
				int ox, int oy);

	void (*eaVisibleDocumentCountChanged)(struct EditApplication *ea,
					      int from, int to);

	void (*eaMakePrivateApplicationMenus)(struct EditApplication *ea,
					      APP_WIDGET menubar);

	void (*eaMakePrivateDocumentMenus)(struct EditApplication *ea,
					   EditDocument *ed,
					   APP_WIDGET menubar);

	void (*eaDocCopy)(EditDocument *);
	void (*eaDocCut)(EditDocument *);
	void (*eaDocSelAll)(EditDocument *);

	void (*eaSetPageLayout)(struct EditDocument *ed,
				const PropertyMask *setMask,
				const DocumentGeometry *dgNew,
				int wholeDocument);

	/************************************************/
	/*  User input on the document widget:		*/
	/************************************************/
	APP_EVENT_HANDLER_T eaDocumentMouseHandler;
	APP_EVENT_HANDLER_T eaDocumentScrollHandler;
	void (*eaDocGotString)(void *voided, const char *value, int length);
	void (*eaDocGotKey)(void *voided, int key, unsigned int state);
	APP_EVENT_HANDLER_T eaObserveFocus;

	APP_SCROLLBAR_CALLBACK_T eaDocHorizontalScrollbarCallback;
	APP_SCROLLBAR_CALLBACK_T eaDocVerticalScrollbarCallback;

	void (*eaScrollTopRuler)(void *, APP_WIDGET, int);
	/**
				     *  Adapt to a change in size of the 
				     *  document: Remember the visible range.
				     */
	void (*eaSetTopRulerRange)(void *voidtr, APP_WIDGET w, int docX1,
				   int docVisX0, int docVisX1);

	void (*eaScrollLeftRuler)(void *, APP_WIDGET, int);
	void (*eaSetLeftRulerRange)(void *voidtr, APP_WIDGET w, int docY1,
				    int docVisY0, int docVisY1);

	void (*eaScrollRightRuler)(void *, APP_WIDGET, int);
	void (*eaSetRightRulerRange)(void *voidtr, APP_WIDGET w, int docY1,
				     int docVisY0, int docVisY1);

	void (*eaScrollBottomRuler)(void *, APP_WIDGET, int);
	/**
				     *  Adapt to a change in size of the 
				     *  document: Remember the visible range.
				     */
	void (*eaSetBottomRulerRange)(void *voidtr, APP_WIDGET w, int docX1,
				      int docVisX0, int docVisX1);

	int (*eaSetTopRuler)(EditDocument *ed);
	int (*eaSetLeftRuler)(EditDocument *ed);
	int (*eaSetRightRuler)(EditDocument *ed);
	int (*eaSetBottomRuler)(EditDocument *ed);

	void (*eaFreeTopRuler)(void *topRuler);
	void (*eaFreeLeftRuler)(void *leftRuler);
	void (*eaFreeRightRuler)(void *rightRuler);
	void (*eaFreeBottomRuler)(void *bottomRuler);

	struct AppSelectionType *eaDocSelectionTypes;
	int eaDocSelectionTypeCount;

	struct AppSelectionType *eaAppSelectionTypes;
	int eaAppSelectionTypeCount;

	PrintDestination *eaPrintDestinations;
	int eaPrintDestinationCount;
	int eaDefaultPrintDestination;
	int eaPrintDestinationsCollected;

	NamedPicture *eaNamedPictures;
	int eaNamedPictureCount;

	APP_ATOM eaCloseAtom;

	unsigned int eaNextDocumentId;

	/**
				 *  Culture name (Language and teritory) 
				 *  determined at startup.
				 */
	char *eaLocaleName;

	/*  2  */

	int eaScreenPixelsWide;
	int eaScreenPixelsHigh;
	double eaPixelsPerTwip;

	AppToplevel eaToplevel;
	APP_INPUT_METHOD eaInputMethod;
	APP_CURSOR eaDocumentCursor;
	APP_WIDGET eaMainWindow;
	APP_WIDGET eaMenuBar;
	APP_WIDGET eaFileMenu;
	APP_WIDGET eaFileMenuButton;
	APP_WIDGET eaWinMenu;
	APP_WIDGET eaWinMenuButton;
	APP_WIDGET eaHelpMenu;
	APP_WIDGET eaHelpMenuButton;

	void *eaPageTool;
	void *eaPrintDialog;

	int eaArgc;
	char **eaArgv;

	EditDocument *eaCurrentDocument;
	EditDocument **eaOpenDocuments;
	int eaOpenCount;
	int eaVisibleDocumentCount;
	int eaMainVisibleAsAbout;

	char *eaFontDirectory;
	char *eaGhostscriptFontmap;
	char *eaGhostscriptFontToXmapping;
	int eaGhostscriptMappingsRead;
	char *eaCustomPrintCommand;
	char *eaCustomPrinterName;
	char *eaCustomPrintCommand2;
	char *eaCustomPrinterName2;
	char *eaAuthor;
	char *eaFocusColor;

	int eaUsePostScriptFiltersInt;
	int eaUsePostScriptIndexedImagesInt;
	int ea7BitsPostScriptInt;
	int eaSkipEmptyPagesInt;
	int eaSkipBlankPagesInt;
	int eaOmitHeadersOnEmptyPagesInt;
	int eaPreferBase35FontsInt;
	int eaEmbedFontsInt;
	int eaUseKerningInt;
	int eaStyleToolInt;

	AppFileMessageResources eaFileMessageResources;

	char *eaMagnificationString;
	char *eaUsePostScriptFiltersString;
	char *eaUsePostScriptIndexedImagesString;
	char *ea7BitsPostScriptString;
	char *eaSkipEmptyPagesString;
	char *eaSkipBlankPagesString;
	char *eaOmitHeadersOnEmptyPagesString;
	char *eaPreferBase35FontsString;
	char *eaEmbedFontsString;
	char *eaUseKerningString;
	char *eaStyleToolString;

	char *eaCustomPsSetupFilename;

	char *eaLeftRulerWidthMMString;
	char *eaTopRulerHeightMMString;
	char *eaRightRulerWidthMMString;
	char *eaBottomRulerHeightMMString;

	int eaGotPaste;

	PostScriptFontList eaPostScriptFontList;

	void *eaSystemProperties;
	void *eaUserProperties;

	int eaGotResourceTable;
	int eaGotFileMessageResourceTable;
	int eaGotApplicationResources;
} EditApplication;

/************************************************************************/
/*									*/
/*  Describes types of content for Copy/Paste.				*/
/*  The order is the order of desirability for the application.		*/
/*									*/
/************************************************************************/

typedef void (*APP_FORGET_COPY)(APP_WIDGET w, void *through, APP_EVENT *event);

typedef struct AppSelectionTargetType {
	const char *asttTargetString; /*  ContentType	*/
	APP_ATOM asttTargetAtom;
	APP_PASTE_REPLY asttUsePaste;
	APP_GIVE_COPY asttGiveCopy;
} AppSelectionTargetType;

typedef struct AppSelectionType {
	const char *astSelectionString; /*  What	*/
	APP_ATOM astSelectionAtom;

	AppSelectionTargetType *astTargetTypes;
	int astTargetTypeCount;

	APP_FORGET_COPY astForgetCopy;
} AppSelectionType;

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

APP_WIDGET appMakeMenu(APP_WIDGET *pButton, AppToplevel *at,
		       EditApplication *ea, APP_WIDGET parent,
		       const char *itemText, int isHelp, AppMenuItem *items,
		       int itemCount, void *through);

EditDocument *appOpenDocumentFile(EditApplication *ea, APP_WIDGET relative,
				  APP_WIDGET option, int readOnly,
				  int suggestStdin, int formatHint,
				  const MemoryBuffer *filename);

EditDocument *appOpenDocument(EditApplication *ea, APP_WIDGET relative,
			      APP_WIDGET option, int readOnly,
			      const MemoryBuffer *filename);

int appNewDocument(EditApplication *ea, const MemoryBuffer *filename);

int appMain(EditApplication *ea, int argc, char *argv[]);

void appSetDocument(EditApplication *ea, EditDocument *ed);

void appRemoveDocument(EditApplication *ea, EditDocument *ed);

void appCloseDocument(EditDocument *ed);

void appSetCurrentDocument(EditApplication *ea, EditDocument *ed);

void appDocToFront(APP_WIDGET option, void *voided, void *e);

void appDocumentChanged(EditDocument *ed, int changed);

void appQuitApplication(APP_WIDGET option, APP_WIDGET relative,
			EditApplication *ea);

APP_MENU_CALLBACK_H(appAppFileQuit, option, voidea, e);

void appDocVisible(EditApplication *ea, EditDocument *ed, int visible);

APP_MENU_CALLBACK_H(appAppFileOpen, option, voidea, e);
APP_MENU_CALLBACK_H(appAppFileNew, option, voidea, e);

void appDocSetScrollbarValues(EditDocument *ed);

void appMouseWheelUp(EditDocument *ed);
void appMouseWheelDown(EditDocument *ed);
APP_EVENT_HANDLER_H(appScrollEventHandler, w, voided, scrollEvent);

APP_MENU_CALLBACK_H(appDocFileSaveAs, option, voided, e);

APP_MENU_CALLBACK_H(appDocFileNew, option, voided, e);
APP_MENU_CALLBACK_H(appDocFileOpen, option, voided, e);
APP_MENU_CALLBACK_H(appDocFileSave, option, voided, e);
APP_MENU_CALLBACK_H(appDocFileClose, option, voided, e);
APP_MENU_CALLBACK_H(appDocFileQuit, option, voided, e);
APP_MENU_CALLBACK_H(appDocEditCopy, option, voided, e);
APP_MENU_CALLBACK_H(appDocEditCut, option, voided, e);
APP_MENU_CALLBACK_H(appDocEditSelAll, option, voided, e);

APP_CLOSE_CALLBACK_H(appDocFileCloseCallback, w, voided);
APP_CLOSE_CALLBACK_H(appAppWmClose, w, voidea);

void appRunReallyCloseDialog(APP_WIDGET option, EditDocument *ed);

int appRunReallyQuitDialog(APP_WIDGET option, APP_WIDGET relative,
			   EditApplication *ea);

void appMakeDocVisible(EditApplication *ea, EditDocument *ed);

void appShowDefaultsEditor(APP_WIDGET prefOption, void *voidea);

int appGetImagePixmap(EditApplication *ea, const char *name,
		      APP_BITMAP_IMAGE *pImage, APP_BITMAP_MASK *pMask);

void appDiscardImagePixmaps(EditApplication *ea);

int appSetDocumentFilename(EditDocument *ed, const MemoryBuffer *filename);

int appSetDocumentTitle(EditDocument *ed, const MemoryBuffer *title);

int appFinishDocumentSetup(EditDocument *ed);

int appSetupDocument(EditApplication *ea, EditDocument *ed);

void appRenameDocumentOptions(EditApplication *ea, EditDocument *ed,
			      const MemoryBuffer *title);

void *appMakePageTool(EditApplication *ea, APP_WIDGET printOption,
		      const char *pixmapName);

void appShowPageTool(EditApplication *ea);

void appPageToolSetProperties(void *voidapt, const DocumentGeometry *dg);

void appEnablePageTool(void *voidapt, int enabled);

void appRunPrintDialog(EditDocument *ed, const DocumentGeometry *dgDocument,
		       int pageCount, int firstSelected, int lastSelected,
		       APP_WIDGET printOption, const char *pixmapName);

int appPrintDocument(int printer, const struct PrintJob *pj);

void appDocPrintToFile(APP_WIDGET option, APP_WIDGET panel, EditDocument *ed,
		       const struct PrintGeometry *pg);

APP_MENU_CALLBACK_H(appDocAbout, option, voided, e);

APP_EVENT_HANDLER_H(appDocCopyPasteHandler, w, voided, event);
APP_EVENT_HANDLER_H(appAppGotPasteCall, w, voided, event);

void appDocGotPasteReplyGtk(GtkWidget *w, GtkSelectionData *gsd, guint time,
			    void *voided);

void appAppGotPasteReplyGtk(GtkWidget *w, GtkSelectionData *gsd, guint time,
			    void *voidea);

int appDocReleaseSelection(EditDocument *ed, const char *selection);

int appDocOwnSelection(EditDocument *ed, const char *selection,
		       AppSelectionTargetType *targets, int targetCount);

int appDocAskForPaste(EditDocument *ed, const char *selection);

int appAppAskForPaste(EditApplication *ea, const char *selection);

APP_SCROLLBAR_CALLBACK_H(appDocHorizontalScrollbarCallback, bar, voided, e);
APP_SCROLLBAR_CALLBACK_H(appDocVerticalScrollbarCallback, bar, voided, e);

void appReportSaveFailure(EditApplication *ea, APP_WIDGET option,
			  APP_WIDGET relative, const MemoryBuffer *filename);

void appMakeVerticalDialog(AppDialog *ad, APP_WIDGET *pPaned,
			   EditApplication *ea,
			   APP_CLOSE_CALLBACK_T closeCallback,
			   APP_DESTROY_CALLBACK_T destroyCallback,
			   void *through);

int appCallPrintFunction(SimpleOutputStream *sos, const struct PrintJob *pj);

int appImgMakeFileExtensions(AppFileExtension **pAfeList, int *pAfeCount);

int appMakeDocumentWidget(EditApplication *ea, EditDocument *ed);

APP_EVENT_HANDLER_H(appDocExposeHandler, w, d, exposeEvent);

int appFileConvert(EditApplication *ea, const MemoryBuffer *fromName,
		   const MemoryBuffer *toName);

int appPrintToFile(EditApplication *ea, const char *fromName,
		   const char *toName, const char *paperString);

int appPrintToPrinter(EditApplication *ea, const char *fromName,
		      const char *toName, const char *paperString);

APP_DESTROY_CALLBACK_H(appDestroyEditDocument, w, voided);

void appScrollToRectangle(EditDocument *ed, const DocumentRectangle *dr,
			  int *pScrolledX, int *pScrolledY);

void appMakeVerticalTool(APP_WIDGET *pShell, APP_WIDGET *pPaned,
			 EditApplication *ea, APP_BITMAP_IMAGE iconPixmap,
			 APP_BITMAP_MASK iconMask, int userResizable,
			 APP_WIDGET option, APP_CLOSE_CALLBACK_T closeCallback,
			 void *through);

void appGuiGetResourceValues(int *pGotResources, EditApplication *ea,
			     void *pValues, AppConfigurableResource *acr,
			     int acrCount);

void appSetResourceDefaults(EditApplication *ea, AppConfigurableResource *acr,
			    int acrCount);

int appGuiInitApplication(EditApplication *ea, int *pArgc, char ***pArgv);

void appShowShellWidget(EditApplication *ea, APP_WIDGET shell);

/************************************************************************/
/*									*/
/*  Names of the X11 events.						*/
/*									*/
/************************************************************************/

void appDocumentRulerWidth(EditApplication *ea, EditDocument *ed);

int appFinishDocumentWindow(EditDocument *ed);

void appGuiSetShellTitle(APP_WIDGET shell, const MemoryBuffer *title);

void appGuiSetIconTitle(APP_WIDGET shell, const MemoryBuffer *title);

APP_WIDGET appSetMenuItem(APP_WIDGET menu, AppToplevel *at, AppMenuItem *ami,
			  void *target);

APP_WIDGET appSetMenuSeparator(APP_WIDGET menu, AppToplevel *at,
			       AppMenuItem *ami, void *target);

APP_WIDGET appSetToggleMenuItem(APP_WIDGET menu, AppToplevel *at,
				AppMenuItem *ami, void *target);

APP_WIDGET appMakeMenuInParent(APP_WIDGET *pButton, AppToplevel *at,
			       APP_WIDGET menuBar, const char *itemText,
			       int isHelp);

void appGuiRunDialog(AppDialog *ad, int initial, EditApplication *ea);

void appGuiBreakDialog(AppDialog *ad, int response);

void appGuiSetDefaultButtonForDialog(AppDialog *ad, APP_WIDGET button);

void appGuiSetCancelButtonForDialog(AppDialog *ad, APP_WIDGET button);

void appGuiShowDialog(EditApplication *ea, AppDialog *ad, APP_WIDGET relative);

void appGuiHideDialog(AppDialog *ad);

void appDocFillMenu(EditDocument *ed);

void appRunDragLoop(APP_WIDGET w, EditApplication *ea, APP_EVENT *downEvent,
		    APP_EVENT_HANDLER_T upHandler,
		    APP_EVENT_HANDLER_T moveHandler, int timerInterval,
		    APP_TIMER_CALLBACK timerHandler, void *through);

void appGuiSetFocusChangeHandler(APP_WIDGET shell, APP_EVENT_HANDLER_T handler,
				 void *through);

void appGuiSetToggleItemState(APP_WIDGET toggle, int set);

void appSetDestroyCallback(APP_WIDGET shell,
			   APP_DESTROY_CALLBACK_T destroyCallback,
			   void *through);

void appSetCloseCallback(APP_WIDGET shell, EditApplication *ea,
			 APP_CLOSE_CALLBACK_T closeCallback, void *through);

void appGuiSetToggleItemLabel(APP_WIDGET toggle, const char *label);

int appFormatDocumentTitle(MemoryBuffer *windowTitle, MemoryBuffer *iconTitle,
			   EditApplication *ea, const MemoryBuffer *title);

APP_EVENT_HANDLER_H(appDocConfigure, w, voided, event);

void appSetWindowsItemState(APP_WIDGET menu, EditDocument *ed, int changed);

void appRemoveWindowsOption(APP_WIDGET menu, EditDocument *oldEd);

void appRenameWindowsOption(APP_WIDGET menu, EditDocument *ed,
			    const MemoryBuffer *title);

void appAllocateCopyPasteTargetAtoms(EditApplication *ea);

APP_GIVE_COPY(appDocReplyToCopyRequest, w, gsd, voided);

void appGetApplicationResourceValues(EditApplication *ea);

void appDocExposeRectangle(const EditDocument *ed,
			   const DocumentRectangle *drChanged, int scrolledX,
			   int scrolledY);

void appPrintJobForEditDocument(struct PrintJob *pj, EditDocument *ed,
				const struct PrintGeometry *pg);

void appApplicationSettingsToPrintGeometry(struct PrintGeometry *pg,
					   EditApplication *ea);

int appDocumentTestCanSave(EditApplication *ea, const AppFileExtension *afe,
			   void *privateData, unsigned int useFlags,
			   int format);

int appDocumentGetSaveFormat(int *pSuggestStdout, EditApplication *ea,
			     const MemoryBuffer *filename, void *privateData,
			     unsigned int useFlags, int format);

int appFileCanOpen(const EditApplication *ea, int format);

int appDocumentGetOpenFormat(int *pSuggestStdin,
			     const AppFileExtension *testExts, int testExtCount,
			     const MemoryBuffer *filename, int format);

int appPostScriptFontCatalog(EditApplication *ea);

int appGetPrintDestinations(EditApplication *ea);

int appReadSystemProperties(EditApplication *ea);
int appReadUserProperties(EditApplication *ea);
int appSetUserProperty(EditApplication *ea, const char *name,
		       const char *value);

int appSetSystemProperty(EditApplication *ea, const char *name,
			 const char *value);

int appGuiSetFrameTitle(APP_WIDGET w, const char *title);

void appDocScrollToY(EditDocument *ed, int y);
void appDocScrollToX(EditDocument *ed, int x);

void appGuiFocusToWidget(APP_WIDGET w);

const AppSelectionType *appDocGetSelectionType(const EditApplication *ea,
					       const char *selection);

void appInitSelectRectangle(SelectRectangle *sr);

void guiShowMenuOption(APP_WIDGET w, int visible);

int appSaveToPs(EditApplication *ea, struct DrawingSurface *ds,
		SimpleOutputStream *sos, void *privateData,
		const MemoryBuffer *documentTitle, int format);

int appMakeDocumentWindow(EditDocument **pEd, EditApplication *ea, int readOnly,
			  const MemoryBuffer *title,
			  const MemoryBuffer *filename);

void appGetPixelsPerTwip(EditApplication *ea);

int appDocSaveDocument(EditDocument *ed, void *through, APP_WIDGET relative,
		       APP_WIDGET option, int format,
		       const MemoryBuffer *filename);

int appDetermineBoolean(int *pIval, const char *sVal);

#ifdef __cplusplus
}
#endif

#endif
