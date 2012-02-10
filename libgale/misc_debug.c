#include "gale/misc.h"
#include "gale/core.h"
#include "gale/globals.h"

#include <stdarg.h>

static void debug(int level,int idelta,const char *fmt,va_list ap) {
	static int indent = 0;
	int i;
	if (idelta < 0) indent += idelta;
	for (i = 0; i < indent; ++i) fputc(' ',stderr);
	vfprintf(stderr,fmt,ap);
	fflush(stderr);
	if (idelta > 0) indent += idelta;
}

void gale_dprintf(int level,const char *fmt,...) {
	va_list ap;
	if (level >= gale_global->debug_level) return;
	va_start(ap,fmt);
	debug(level,0,fmt,ap);
	va_end(ap);
}

void gale_diprintf(int level,int indent,const char *fmt,...) {
	va_list ap;
	if (level >= gale_global->debug_level) return;
	va_start(ap,fmt);
	debug(level,indent,fmt,ap);
	va_end(ap);
}
