#ifndef TED_APP_H
#define TED_APP_H

#include <appFrame.h>

#include <utilPropMask.h>
#include <utilMemoryBuffer.h>

#include <geo2DInteger.h>
#include <docBuf.h>
#include <utilIndexMapping.h>

/************************************************************************/

struct TedDocument;
struct DocumentStatistics;

/************************************************************************/
/*									*/
/*  Shared resources.							*/
/*									*/
/************************************************************************/

extern const int TedClipboardTextTargetCount;
extern AppSelectionTargetType TedClipboardTextTargets[];

extern const int TedPrimaryTargetCount;
extern AppSelectionTargetType TedPrimaryTargets[];

extern const int TedRulerTargetCount;
extern AppSelectionTargetType TedRulerTargets[];

extern const int TedFontTargetCount;
extern AppSelectionTargetType TedFontTargets[];

/************************************************************************/
/*									*/
/*  Routine Declarations.						*/
/*									*/
/************************************************************************/

void tedDocCopy(EditDocument *ed);
void tedDocCut(EditDocument *ed);

void tedDocSelAll(EditDocument *ed);

void tedAdaptFontIndicatorsToSelection(EditDocument *ed);

void tedAdaptToolsToSelection(EditDocument *ed);

int tedExtendSelectionToPosition(EditDocument *ed,
				 const DocumentPosition *dpAnchor,
				 const DocumentPosition *dpFound);

void tedScrollToSelection(EditDocument *ed, int *pScrolledX, int *pScrolledY);

void tedAdaptPageToolToDocument(EditApplication *ea, EditDocument *ed);

void tedGetNamedPictures(EditApplication *ea);

void tedUndrawIBar(const EditDocument *ed);

void tedStartCursorBlink(EditDocument *ed);
void tedStopCursorBlink(EditDocument *ed);
void tedCleanCursorBlink(struct TedDocument *td);

void tedMoveObjectWindows(EditDocument *ed);

int tedSaveObjectPicture(RasterImage *abiTo, const InsertedObject *io);

void tedDrawRectangle(EditDocument *ed, DocumentRectangle *drClip, int ox,
		      int oy);

int tedFinishDocumentSetup(EditDocument *ed);
void tedDocumentFirstVisible(EditDocument *ed);

int tedLayoutDocument(DocumentRectangle *drScreen, DocumentRectangle *drVisible,
		      void *privateData, int format, struct DrawingSurface *ds,
		      const PostScriptFontList *psfl,
		      const DocumentGeometry *defDg);

int tedMakeDocumentWidget(EditApplication *ea, EditDocument *ed);

void tedAdaptFormatToolToDocument(EditDocument *ed, int choosePage);

int tedRunPropertyDialog(EditDocument *ed, const struct DocumentStatistics *ds,
			 APP_WIDGET option, const char *pixmapName);

int tedSaveDocument(EditApplication *ea, struct DrawingSurface *ds,
		    const void *privateData, int format,
		    const MemoryBuffer *documentTitle, int suggestStdout,
		    const MemoryBuffer *filename, int isDocName);

void *tedMakePrivateData(void);

int tedNewDocument(EditDocument *ed, const MemoryBuffer *filename);

int tedPrintDocument(SimpleOutputStream *sos, const struct PrintJob *pj,
		     const struct PrintGeometry *pg);

void tedSuggestPageSetup(struct PrintGeometry *pg, void *privateData,
			 int sheetSize);

void tedFreeDocument(void *voidtd, int format);

void tedRedoDocumentLayout(EditDocument *ed);

void tedFormatSetFindPattern(EditApplication *ea, const char *findPattern,
			     int findRegexp);

void tedHideObjectWindows(EditDocument *ed);

int tedSetIBarSelection(EditDocument *ed, const DocumentPosition *dp,
			int lastLine, int *pScrolledX, int *pScrolledY);

int tedOpenDocumentFile(unsigned char *digest, int *pFormat,
			BufferDocument **pBd, EditApplication *ea,
			int suggestStdin, int formatHint,
			const MemoryBuffer *filename, int complain,
			APP_WIDGET relative, APP_WIDGET option);

int tedObjectDrag(APP_WIDGET w, EditDocument *ed, APP_EVENT *downEvent);

int tedOpenDocument(EditApplication *ea, void *voidtd, int *pFormat,
		    APP_WIDGET relative, APP_WIDGET option, int readOnly,
		    int suggestStdin, int formatHint,
		    const MemoryBuffer *filename);

void tedManagePrimarySelection(EditDocument *ed);

void tedToggleTextAttribute(EditDocument *ed, int set, int prop);

void tedSetFontSupersub(EditDocument *ed, int supersub);

int tedDocFindNext(EditDocument *ed);
int tedDocFindPrev(EditDocument *ed);

void tedShowFindTool(EditDocument *ed);

void tedObserveFocus(EditDocument *ed, int inout);

int tedMakeDocumentCursor(EditApplication *ea);

int tedDocUnlock(EditDocument *ed);
int tedDocRecover(EditDocument *ed);

void tedMakeDocumentReadonly(EditDocument *ed, int readonly);

void tedSetTracedChangedFlag(EditDocument *ed);

#endif /*  TED_APP_H	*/
