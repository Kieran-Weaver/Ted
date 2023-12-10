#ifndef CONFIG_H
#define CONFIG_H

/* Logging settings */
#define LOG_EXPOSES 0
#define LOG_MATCHES 0
#define LOG_GUESSES 0
#define LOG_CUTS 0
#define LOG_PALETTE 0
#define LOG_TRANSACTIONS 0
#define LOG_REDRAWS 0
#define LOG_RELAYOUT 0

#define COLUMN_SPACING_GTK 1
#define WINDOW_BORDER_GTK 4
#define FRAME_BORDER_GTK 4
#define ROW_XPADDING_GTK 1
#define ROW_YPADDING_GTK 0

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

#undef HAVE_LIBPAPER
#undef HAVE_ICONV
#undef USE_LIBPAPER

#define MY_PLATFORM ""
#define MY_HOST_DATE ""
#define MY_RELEASE ""

#endif
