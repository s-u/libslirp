/* implementation of string concatenation compatible with
   glib gstring API.

   (C)2022 Simon Urbanek, License: MIT   
*/

#include "glib.h"

#include <stdarg.h>
#include <string.h>

/* default allocation size if none is specified */
#define GSTR_DEFAULT_ALLOC 1024

/* it uses a chain of buffers to avoid re-allocation */
struct GStrings {
    size_t al, len;
    struct GStrings *next;
    char str[1];   
};

static GString *g_string_alloc(const char *init, size_t al) {
    GString *s;
    size_t len = init ? strlen(init) : 0;
    if (len > GSTR_DEFAULT_ALLOC / 2)
	al = len * 2;
    if (!(s = malloc(sizeof(GString) + al))) {
	fprintf(stderr, "ERROR: cannot allocate string.\n");
	exit(1);
    }

    s->al = al;
    s->len = len;
    s->next = 0;
    if (len)
	memcpy(s->str, init, len);
    s->str[len] = 0;
    return s;
}

/* allocates the larger of 2 * strlen(init) and GSTR_DEFAULT_ALLOC */
GString *g_string_new(const char *init) {
    return g_string_alloc(init, GSTR_DEFAULT_ALLOC);
}

void g_string_append_printf (GString* s, const char* fmt, ...) {
    va_list ap;
    int n;
    va_start(ap, fmt);
    while (s && s->next) s = s->next;
    if (!s) return;
    n = vsnprintf(s->str + s->len, s->al - s->len, fmt, ap);
    if (n >= s->al - s->len) { /* did not fit */
	s->str[s->len] = 0;
	s = s->next = g_string_alloc(0, (n > GSTR_DEFAULT_ALLOC / 2) ? (2 * n) : GSTR_DEFAULT_ALLOC);
	n = vsnprintf(s->str + s->len, s->al - s->len, fmt, ap);
    }
    s->len += n;
    s->str[s->len] = 0;
    va_end(ap);
}

char *g_string_free(GString *s, int no_ret) {
    char *str = 0;
    if (!no_ret) { /* collect, free and return */
	GString *sn = s;
	size_t len = 0;
	char *c;
	/* PASS 1: determine total length */
	while (sn) {
	    len += sn->len;
	    sn = sn->next;
	}
	c = str = malloc(len + 1);
	if (!str) {
	    fprintf(stderr, "ERROR: cannot allocate string.\n");
	    exit(1);
	}
	/* PASS 2: copy content + free */
	sn = s;
	while (sn) {
	    GString *nn = sn->next;
	    memcpy(c, sn->str, sn->len);
	    c += sn->len;
	    free(sn);
	    sn = nn;
	}
	*c = 0;
    } else { /* just free */
	while (s) {
	    GString *nn = s->next;
	    free(s);
	    s = nn;
	}
    }
    return str;
}
