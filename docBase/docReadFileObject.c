/************************************************************************/
/*									*/
/*  Include a file from the file system in an object.			*/
/*									*/
/************************************************************************/

#include <config.h>
#include <appSystem.h>
#include "docObject.h"
#include <appDebugon.h>

/************************************************************************/
/*									*/
/*  Read a bitmap/pixmap image file.					*/
/*									*/
/************************************************************************/

static int docReadIncludedBitmapFile(const MemoryBuffer *fullName,
				     InsertedObject *io)
{
	return docReadBitmapObject(io, fullName);
}

/************************************************************************/
/*									*/
/*  Evaluate an 'INCLUDEPICTURE' field.					*/
/*									*/
/************************************************************************/

int docReadFileObject(const MemoryBuffer *fullName, InsertedObject *io)
{
	int res = -1;
	int included = 0;

	MemoryBuffer extension;

	utilInitMemoryBuffer(&extension);

	if (appFileGetFileExtension(&extension, fullName)) {
		LDEB(1);
		res = -1;
		goto ready;
	}

	if (!included && (utilMemoryBufferEqualsString(&extension, "ps") ||
			  utilMemoryBufferEqualsString(&extension, "eps") ||
			  utilMemoryBufferEqualsString(&extension, "PS") ||
			  utilMemoryBufferEqualsString(&extension, "EPS"))) {
		res = docReadEpsObject(fullName, io);
		if (res) {
			LDEB(res);
			goto ready;
		} else {
			included = 1;
		}
	}

	if (!included) {
		res = docReadIncludedBitmapFile(fullName, io);
		if (res) {
			LDEB(res);
		}
	}

ready:

	utilCleanMemoryBuffer(&extension);

	return res;
}
