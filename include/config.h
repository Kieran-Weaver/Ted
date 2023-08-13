#ifndef CONFIG_H
#define CONFIG_H

#undef HAVE_MKSTEMP
#define HAVE_FT2 1
#define HAVE_XFT 1
#define HAVE_FONTCONFIG 1
#define USE_XFT 1
#define USE_FONTCONFIG 1

#undef DATADIR

#ifdef DATADIR
#define PKGDIR DATADIR
#endif

#ifndef PKGDIR
#define PKGDIR "/usr/share"
#endif

#ifndef AFMDIR
#define AFMDIR PKGDIR "/Ted/afm"
#endif

#ifndef INDDIR
#define INDDIR PKGDIR "/Ted/dfa"
#endif

#ifndef CONFDIR
#define CONFDIR PKGDIR "/Ted/config"
#endif

#ifndef DOCUMENT_DIR
#define DOCUMENT_DIR PKGDIR "/Ted"
#endif

#ifndef PSSCRIPT_DIR
#define PSSCRIPT_DIR PKGDIR "/Ted/ps"
#endif

#ifndef FONT_TPL_DIR
#define FONT_TPL_DIR PKGDIR "/Ted/fontsdocs"
#endif

#undef USE_MOTIF
#define USE_GTK 1

#undef const
#undef STDC_HEADERS
#undef WORDS_BIGENDIAN
#undef HAVE_STRERROR
#undef HAVE_UNAME
#undef UTSNAME_DOMAIN
#undef HAVE_FCNTL_H
#undef HAVE_SYS_TIME_H
#undef HAVE_UNISTD_H
#define HAVE_DIRENT_H 1

#undef HAVE_SOCKET
#undef HAVE_SYS_SOCKET_H

#undef SIZEOF_SHORT
#undef SIZEOF_INT
#undef SIZEOF_LONG
#undef SIZEOF_UNSIGNED_SHORT
#undef SIZEOF_UNSIGNED_INT
#undef SIZEOF_UNSIGNED_LONG

#undef HAVE_LIBPAPER
#undef HAVE_ICONV
#undef USE_LIBPAPER

#undef USE_LIBJPEG
#undef USE_LIBTIFF
#undef USE_LIBPNG
#undef USE_LIBXPM

#define MY_PLATFORM ""
#define MY_HOST_DATE ""
#define MY_RELEASE ""

#include <stdint.h>

typedef uint16_t BmUint16;
typedef uint32_t BmUint32;
typedef uint16_t UtilUint16;
typedef uint32_t UtilUint32;

#endif
