/************************************************************************/
/*									*/
/*  Header file for internal use by the FileChooser implementation.	*/
/*									*/
/************************************************************************/

#include "appFrame.h"
#include "guiOptionmenu.h"

/************************************************************************/
/*									*/
/*  For opening/saving documents.					*/
/*									*/
/************************************************************************/

#define ACIrespNONE 0
#define ACIrespSAVE 1
#define ACIrespCANCEL 2
#define ACIrespOPEN 3
#define ACIrespFAILURE 4

typedef struct AppFileChooserResources {
	char *acrNoFilenameMessage;
	char *acrIsDirecoryMessage;
	char *acrNotWritableMessage;
	char *acrNotReadableMessage;
	char *acrOverwriteMessage;
	char *acrNoSuchDirMessage;
} AppFileChooserResources;

typedef int (*APP_OPEN_DOCUMENT)(EditApplication *ea, void *through,
				 APP_WIDGET relative, APP_WIDGET option,
				 const MemoryBuffer *filename);

typedef int (*APP_SAVE_DOCUMENT)(EditDocument *ed, void *through,
				 APP_WIDGET relative, APP_WIDGET option,
				 int format, const MemoryBuffer *filename);

typedef struct AppChooserInformation {
#ifdef GTK_RESPONSE_ACCEPT
	APP_WIDGET aciWidget;
#endif
	AppDialog aciDialog;
#define aciWidget aciDialog.adTopWidget

	EditApplication *aciApplication;
	EditDocument *aciDocument;
	MemoryBuffer aciFilename;
	void *aciThrough;
	APP_OPEN_DOCUMENT aciOpenDocument;
	APP_SAVE_DOCUMENT aciSaveDocument;
	const AppFileExtension *aciExtensions;
	int aciExtensionCount;
	AppOptionmenu aciFilterOptionmenu;
	APP_WIDGET aciOption;
	APP_WIDGET aciRelativeTo;
	int aciFormat;

	const AppFileChooserResources *aciResources;
} AppChooserInformation;

#define FILE_CHOOSER_CAN_OPEN(afe)                          \
	(((afe)->afeUseFlags & APPFILE_CAN_OPEN) &&         \
	 (!((afe)->afeUseFlags & APPFILE_IS_BASIC_TYPE)) && \
	 (!((afe)->afeUseFlags & APPFILE_HIDE_OPEN)))

/************************************************************************/
/*									*/
/*  Procedure declarations.						*/
/*									*/
/************************************************************************/

void appFileChooserGetTexts(EditApplication *ea, AppChooserInformation *aci);

int appFileChooserTestNameForOpen(const AppChooserInformation *aci);

int appFileChooserTestNameForWrite(const AppChooserInformation *aci);

int appChooserSaveFilename(AppChooserInformation *aci,
			   const MemoryBuffer *filename, const char *extension);

int appRunSaveChooser(APP_WIDGET option, APP_WIDGET relative,
		      unsigned int useFlags, APP_SAVE_DOCUMENT saveDocument,
		      EditDocument *ed, void *through);

int appRunPrintToFileChooser(APP_WIDGET option, APP_WIDGET relative,
			     APP_SAVE_DOCUMENT saveDocument, EditDocument *ed,
			     void *through);

void appRunOpenChooser(APP_WIDGET option, APP_WIDGET relative,
		       int extensionCount, AppFileExtension *openExtensions,
		       const char *defaultFilter, const MemoryBuffer *dir,
		       APP_OPEN_DOCUMENT openDocument, EditApplication *ea,
		       void *through);

int appFileFilterGetDescriptions(EditApplication *ea,
				 AppFileExtension *extensions,
				 int extensionCount);

int appFileChooserConfirmOverWrite(const AppChooserInformation *aci,
				   const char *filename);

int appChooserOpenDocument(EditApplication *ea, void *through,
			   APP_WIDGET relative, APP_WIDGET option,
			   const MemoryBuffer *filename);
