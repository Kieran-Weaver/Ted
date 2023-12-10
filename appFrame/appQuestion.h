/************************************************************************/
/*									*/
/*  Run dialogs.							*/
/*									*/
/************************************************************************/

#ifndef APP_QUESTION_H
#define APP_QUESTION_H

#include "appFrame.h"

#ifdef __cplusplus
extern "C"{
#endif

/************************************************************************/
/*									*/
/*  Routine declarations.						*/
/*									*/
/************************************************************************/

int appQuestionRunSubjectYesNoCancelDialog(EditApplication *ea,
						  APP_WIDGET relative,
						  APP_WIDGET option,
						  const char *subject,
						  const char *question);

int appQuestionRunYesNoCancelDialog(EditApplication *ea,
					   APP_WIDGET relative,
					   APP_WIDGET option,
					   const char *question);

void appQuestionRunSubjectErrorDialog(EditApplication *ea,
					     APP_WIDGET relative,
					     APP_WIDGET option,
					     const char *subject,
					     const char *message);

void appQuestionRunFilenameErrorDialog(EditApplication *ea,
					      APP_WIDGET relative,
					      APP_WIDGET option,
					      const MemoryBuffer *filename,
					      const char *message);

void appQuestionRunErrorDialog(EditApplication *ea, APP_WIDGET relative,
				      APP_WIDGET option, const char *message);

int appQuestionRunOkCancelDialog(EditApplication *ea,
					APP_WIDGET relative, APP_WIDGET option,
					const char *question);

int appQuestionRunSubjectOkCancelDialog(EditApplication *ea,
					       APP_WIDGET relative,
					       APP_WIDGET option,
					       const char *subject,
					       const char *question);

int appQuestionRunFilenameOkCancelDialog(EditApplication *ea,
						APP_WIDGET relative,
						APP_WIDGET option,
						const MemoryBuffer *filename,
						const char *question);

int appQuestionRunSubjectYesNoDialog(EditApplication *ea,
					    APP_WIDGET relative,
					    APP_WIDGET option,
					    const char *subject,
					    const char *message);

#ifdef __cplusplus
}
#endif

#endif
