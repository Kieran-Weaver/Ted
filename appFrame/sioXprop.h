/************************************************************************/
/*									*/
/*  Simple io streams using X11 window properties.			*/
/*									*/
/************************************************************************/

#include "appGuiBase.h"

#include <sioGeneral.h>

#ifdef __cplusplus
extern "C" {
#endif

SimpleInputStream *sioInOpenPaste(APP_WIDGET w, APP_SELECTION_EVENT *event);

SimpleOutputStream *sioOutOpenCopy(APP_WIDGET w, APP_SELECTION_EVENT *event);

#ifdef __cplusplus
}
#endif
