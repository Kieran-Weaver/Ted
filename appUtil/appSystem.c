/************************************************************************/
/*									*/
/*  Consult the operating system about certain things.			*/
/*									*/
/*  1)  Note that we use shell commands to consult the file system.	*/
/*	this is the easiest way.					*/
/*									*/
/************************************************************************/

#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <dirent.h>
#include "appSystem.h"
#include <appDebugon.h>
#ifdef NeXT
#include <libc.h>
#endif

#ifndef PATH_MAX
#define PATH_MAX 1000
#endif

/************************************************************************/
/*									*/
/*  Determine the home directory of the user.				*/
/*									*/
/************************************************************************/

int appHomeDirectory(MemoryBuffer *mb)
{
	struct passwd *pwd;

	pwd = getpwuid(getuid());
	if (!pwd) {
		LXDEB(getuid(), pwd);
		return -1;
	}
	if (!pwd->pw_dir) {
		XDEB(pwd->pw_dir);
		return -1;
	}

	if (utilMemoryBufferSetString(mb, pwd->pw_dir)) {
		LDEB(1);
		return -1;
	}

	return mb->mbSize;
}

/************************************************************************/
/*									*/
/*  Determine the current directory.					*/
/*									*/
/************************************************************************/

int appCurrentDirectory(MemoryBuffer *mb)
{
	char scratch[PATH_MAX + 1];

	if (!getcwd(scratch, sizeof(scratch) - 1)) {
		SDEB(strerror(errno));
		return -1;
	}

	if (utilMemoryBufferSetString(mb, scratch)) {
		LDEB(1);
		return -1;
	}

	return mb->mbSize;
}

/************************************************************************/
/*									*/
/*  Check whether a directory exists.					*/
/*									*/
/************************************************************************/

int appTestDirectory(const MemoryBuffer *dir)
{
	struct stat st;

	if (stat(utilMemoryBufferGetString(dir), &st)) {
		if (errno != ENOENT) {
			SSDEB(utilMemoryBufferGetString(dir), strerror(errno));
		}

		return -1;
	}

	if (!S_ISDIR(st.st_mode)) {
		return -1;
	}

	return 0;
}

int appTestFileWritable(const MemoryBuffer *file)
{
	if (access(utilMemoryBufferGetString(file), W_OK)) {
		return -1;
	}

	return 0;
}

int appTestFileReadable(const MemoryBuffer *file)
{
	if (access(utilMemoryBufferGetString(file), R_OK)) {
		return -1;
	}

	return 0;
}

int appTestFileExists(const MemoryBuffer *mb)
{
	struct stat st;

	if (stat(utilMemoryBufferGetString(mb), &st)) {
		if (errno != ENOENT) {
			SSDEB(utilMemoryBufferGetString(mb), strerror(errno));
		}

		return -1;
	}

	if (!S_ISREG(st.st_mode)) {
		return -1;
	}

	return 0;
}

/************************************************************************/
/*									*/
/*  Make a Directory.							*/
/*									*/
/************************************************************************/
static int maybe_mkdir(const char *path)
{
	struct stat st;
	errno = 0;

	if (mkdir(path, S_IRWXU) == 0)
		return 0;

	if (errno != EEXIST) {
		return -errno;
	}

	/* File creation failed, check for dir */
	if (stat(path, &st) != 0)
		return -1;

	if (!S_ISDIR(st.st_mode))
		return -ENOTDIR;

	return 0;
}

int appMakeDirectory(const MemoryBuffer *dir)
{
	const char *cpath = utilMemoryBufferGetString(dir);
	char *path = strdup(cpath);
	char *p;
	int err = 0;

	if (path == NULL)
		return -1;

	for (p = path + 1; *p; p++) {
		if (*p == '/') {
			*p = '\0';
			err = maybe_mkdir(path);
			if (err < 0)
				goto out;
			*p = '/';
		}
	}

	err = maybe_mkdir(path);

out:
	free(path);
	return err;
}

/************************************************************************/
/*									*/
/*  Remove a file.							*/
/*									*/
/************************************************************************/

int appRemoveFile(const MemoryBuffer *filename)
{
	const char *fn = utilMemoryBufferGetString(filename);

	if (remove(fn)) {
		SLSDEB(fn, errno, strerror(errno));
		return -1;
	}

	return 0;
}

/************************************************************************/
/*									*/
/*  Move a file by copying it.						*/
/*									*/
/************************************************************************/

static int appMoveFileContents(const char *fn, const char *fo, int removeSource)
{
	int rval = 0;

	int fdo = -1;
	int fdn = -1;

	char buf[1024];
	int done;

	fdn = open(fn, O_WRONLY | O_CREAT, 0666);
	if (fdn < 0) {
		SLLSDEB(fn, fdn, errno, strerror(errno));
		rval = -1;
		goto ready;
	}

	fdo = open(fo, O_RDONLY, 0);
	if (fdo < 0) {
		SLLSDEB(fo, fdo, errno, strerror(errno));
		rval = -1;
		goto ready;
	}

	while ((done = read(fdo, buf, sizeof(buf))) > 0) {
		if (write(fdn, buf, done) != done) {
			SLLSDEB(fn, done, errno, strerror(errno));
			rval = -1;
			goto ready;
		}
	}

	if (done < 0) {
		SLLSDEB(fo, done, errno, strerror(errno));
		rval = -1;
		goto ready;
	}

	if (close(fdn)) {
		SLLSDEB(fn, fdn, errno, strerror(errno));
		rval = -1;
		goto ready;
	}
	fdn = -1;

	if (close(fdo)) {
		SLLSDEB(fo, fdo, errno, strerror(errno));
		rval = -1;
		goto ready;
	}
	fdo = -1;

	if (removeSource && unlink(fo)) {
		SLSDEB(fo, errno, strerror(errno));
		rval = -1;
		goto ready;
	}

ready:

	if (fdn >= 0 && close(fdn)) {
		SLSDEB(fn, errno, strerror(errno));
	}
	if (fdn >= 0 && unlink(fn)) {
		SLSDEB(fn, errno, strerror(errno));
	}

	if (fdo >= 0 && close(fdo)) {
		SLSDEB(fo, errno, strerror(errno));
	}

	return rval;
}

/************************************************************************/
/*									*/
/*  Rename a file.							*/
/*  Behavior is undefined if we have the file open.			*/
/*									*/
/************************************************************************/

int appRenameFile(const MemoryBuffer *newName, const MemoryBuffer *oldName)
{
	int rval = 0;

	const char *fn = utilMemoryBufferGetString(newName);
	const char *fo = utilMemoryBufferGetString(oldName);
	int res;

	res = rename(fo, fn);

#ifdef EXDEV

	if (res < 0 && errno == EXDEV) {
		const int removeSource = 1;

		res = appMoveFileContents(fn, fo, removeSource);
		if (res) {
			SSLSDEB(fo, fn, errno, strerror(errno));
			rval = -1;
			goto ready;
		}
	}

#else

	if (res) {
		SSLSDEB(fo, fn, errno, strerror(errno));
		rval = -1;
		goto ready;
	}

#endif

ready:

	return rval;
}

/************************************************************************/
/*									*/
/*  Call a function for all files matching a certain criterion.		*/
/*									*/
/************************************************************************/

#define FILEL 1000

int appForAllFiles(const MemoryBuffer *dir, const char *ext, void *through,
		   FILE_CALLBACK callback)
{
	int rval = 0;
	DIR *d = opendir(utilMemoryBufferGetString(dir));
	struct dirent *de;

	MemoryBuffer absolute;
	MemoryBuffer relative;

	utilInitMemoryBuffer(&absolute);
	utilInitMemoryBuffer(&relative);

	if (!d) {
		SSDEB(utilMemoryBufferGetString(dir), strerror(errno));
		rval = -1;
		goto ready;
	}

	de = readdir(d);
	while (de) {
		char *dot = strrchr(de->d_name, '.');

#ifdef __VMS
		char *semicolon = strrchr(de->d_name, ';');

		if (semicolon) {
			*semicolon = '\0';
		}
#endif

		if (!strcmp(de->d_name, ".")) {
			de = readdir(d);
			continue;
		}
		if (!strcmp(de->d_name, "..")) {
			de = readdir(d);
			continue;
		}

		if (!ext || (dot && !strcmp(dot + 1, ext))) {
			const int relativeIsFile = 0;

			if (utilMemoryBufferSetString(&relative, de->d_name)) {
				LDEB(1);
				rval = -1;
				goto ready;
			}

			if (appAbsoluteName(&absolute, &relative,
					    relativeIsFile, dir) < 0) {
				LDEB(1);
				rval = -1;
				goto ready;
			}

			if ((*callback)(&absolute, through)) {
				SDEB(de->d_name);
				rval = -1;
				break;
			}
		}

		de = readdir(d);
	}

ready:

	utilCleanMemoryBuffer(&absolute);
	utilCleanMemoryBuffer(&relative);

	if (d && closedir(d)) {
		SDEB(strerror(errno));
		rval = -1;
	}

	return rval;
}
