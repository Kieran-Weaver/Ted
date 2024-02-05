/************************************************************************/
/*									*/
/*  Operating system related functionality.				*/
/*									*/
/************************************************************************/

#ifndef APP_SYSTEM_H
#define APP_SYSTEM_H

#include <utilMemoryBuffer.h>
typedef int (*FILE_CALLBACK)(const MemoryBuffer *name, void *through);

typedef void (*APP_COMPLAIN)(void *through, int errorId,
			     const char *errorSubject);

/************************************************************************/
/*									*/
/*  Error numbers. (Can be translated to strings by the caller.)	*/
/*									*/
/************************************************************************/

#define APP_SYSTEMeNOERROR 0
#define APP_SYSTEMeNOMEM 1
#define APP_SYSTEMeFROM 2
#define APP_SYSTEMeRCPT 3
#define APP_SYSTEMeSMTP 4
#define APP_SYSTEMeWRITE 5
#define APP_SYSTEMeREAD 6
#define APP_SYSTEMeUNAME 7
#define APP_SYSTEMeHOST 8
#define APP_SYSTEMeSERV 9
#define APP_SYSTEMeSOCK 10
#define APP_SYSTEMeCONN 11
#define APP_SYSTEMeBIND 12
#define APP_SYSTEMeLISTEN 13
#define APP_SYSTEMeACCEPT 14

#define APP_SYSTEMeCOUNT 15

/************************************************************************/
/*									*/
/*  Operating system related functionality.. Declarations.		*/
/*									*/
/************************************************************************/

int appHomeDirectory(MemoryBuffer *mb);
int appCurrentDirectory(MemoryBuffer *mb);

int appTestDirectory(const MemoryBuffer *dir);
int appTestFileWritable(const MemoryBuffer *file);
int appTestFileExists(const MemoryBuffer *mb);
int appTestFileReadable(const MemoryBuffer *file);

int appMakeDirectory(const MemoryBuffer *dir);
int appAbsoluteName(MemoryBuffer *absolute, const MemoryBuffer *relative,
		    int relativeIsFile, const MemoryBuffer *nameRelativeTo);

int appRemoveFile(const MemoryBuffer *filename);
int appRenameFile(const MemoryBuffer *newName, const MemoryBuffer *oldName);

int appForAllFiles(const MemoryBuffer *dir, const char *ext, void *through,
		   FILE_CALLBACK callback);

int appFileGetFileExtension(MemoryBuffer *extension,
			    const MemoryBuffer *filename);

int appFileGetRelativeName(MemoryBuffer *relative,
			   const MemoryBuffer *filename);

int appDirectoryOfFileName(MemoryBuffer *dir, const MemoryBuffer *name);

int appFileSetExtension(MemoryBuffer *filename, const char *extension);
int appFileAddExtension(MemoryBuffer *filename, const char *extension);

#endif /*  APP_SYSTEM_H	*/
