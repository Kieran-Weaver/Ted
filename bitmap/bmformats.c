#include <config.h>

#include "bmintern.h"
#include <string.h>
#include <appSystem.h>
#include <appDebugon.h>

static BitmapFileType bmBmpFile = {
	bmWriteBmpFile,
	bmCanWriteBmpFile,
	bmReadBmpFile,
	"bmp",
	"*.bmp",
	"bmpFile",
	"Microsoft Bitmap ( *.bmp )",
};

static BitmapFileType bmJpgFile = {
	bmWriteJpegFile, bmCanWriteJpegFile, bmReadJpegFile,   "jpg",
	"*.jpg",	 "jpgFile",	     "JPEG ( *.jpg )",
};

static BitmapFileType bmJpegFile = {
	bmWriteJpegFile, bmCanWriteJpegFile, bmReadJpegFile,	"jpeg",
	"*.jpeg",	 "jpegFile",	     "JPEG ( *.jpeg )",
};

static BitmapFileType bmGifFile = {
	bmWriteGifFile,
	bmCanWriteGifFile,
	bmReadGifFile,
	"gif",
	"*.gif",
	"gifFile",
	"Compuserve GIF ( *.gif )",
};

static BitmapFileType bmPngFile = {
	bmWritePngFile,
	bmCanWritePngFile,
	bmReadPngFile,
	"png",
	"*.png",
	"pngFile",
	"Portable Network Graphics ( *.png )",
};

BitmapFileType *bmFileTypes[] = {
	&bmPngFile, &bmJpegFile, &bmJpgFile,
	&bmBmpFile, &bmGifFile,
};

BitmapFileFormat bmFileFormats[] = {
	{ "PNG  Portable Network Graphics", "png1File", 0, &bmPngFile },
	{ "JPG  Independent JPEG Group (.jpg)", "jpg1File", 1, &bmJpgFile },
	{ "JPEG  Independent JPEG Group (.jpeg)", "jpeg1File", 1, &bmJpegFile },
	{ "BMP  Microsoft Windows 3.x bitmap", "bmp3File", 40, &bmBmpFile },
	{ "GIF  Compuserve GIF", "gif87File", 87, &bmGifFile },
};

const int bmNumberOfFileFormats =
	sizeof(bmFileFormats) / sizeof(BitmapFileFormat);
const int bmNumberOfFileTypes = sizeof(bmFileTypes) / sizeof(BitmapFileType *);

static int bmTestWrite(const BitmapDescription *bd, const MemoryBuffer *ext,
		       const BitmapFileFormat *bff)
{
	if (!utilMemoryBufferIsEmpty(ext) &&
	    strcmp(bff->bffFileType->bftFileExtension,
		   utilMemoryBufferGetString(ext))) {
		return -1;
	}
	if (!bff->bffFileType->bftWrite) {
		return -1;
	}
	if ((*bff->bffFileType->bftCanWrite)(bd, bff->bffPrivate)) {
		return -1;
	}

	return 0;
}

int bmSuggestFormat(const MemoryBuffer *filename, int suggestedFormat,
		    const BitmapDescription *bd)
{
	int format = suggestedFormat;

	MemoryBuffer ext;

	if (format >= bmNumberOfFileFormats) {
		LLDEB(format, bmNumberOfFileFormats);
		format = -1;
		goto ready;
	}

	utilInitMemoryBuffer(&ext);

	if (appFileGetFileExtension(&ext, filename)) {
		LDEB(1);
		format = -1;
		goto ready;
	}

	if (utilMemoryBufferIsEmpty(&ext) || format < 0 ||
	    bmTestWrite(bd, &ext, bmFileFormats + format)) {
		int i;
		BitmapFileFormat *bff;

		bff = bmFileFormats;
		for (i = 0; i < bmNumberOfFileFormats; bff++, i++) {
			if (!bmTestWrite(bd, &ext, bff)) {
				format = i;
				break;
			}
		}

		if (i == bmNumberOfFileFormats) {
			SLLDEB(utilMemoryBufferGetString(&ext), i,
			       bmNumberOfFileFormats);
		}
	}

ready:

	utilCleanMemoryBuffer(&ext);

	return format;
}
