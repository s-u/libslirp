/* This is a small compatability shim to remove the dependence on
   glib since it impossible to use outside of Linux.
   The main purpose of this is to make libslirp work on macOS.
   This is an implementation of the API, it is not related to
   glib code in any way.

   (C)2022 Simon Urbanek, License: MIT
*/

#ifndef GLIB_COMPAT__
#define GLIB_COMPAT__

/* any alternative sections can be made conditional on NO_GLIB */
#define NO_GLIB 1

#define GLIB_CHECK_VERSION(X, Y, Z) 0

#define G_OS_UNIX 1

/* we only care about x86 and arm64 at this point, so hard-code for LE */
#ifndef G_BYTE_ORDER
#define G_LITTLE_ENDIAN 1
#define G_BYTE_ORDER G_LITTLE_ENDIAN
#endif

#define GUINT16_SWAP_LE_BE(val) ((uint16_t) ((uint16_t) ((uint16_t) (val) >> 8) | (uint16_t) ((uint16_t) (val) << 8)))
#define GUINT32_SWAP_LE_BE(val) ((uint32_t) ( (((uint32_t) (val) & (uint32_t) 0x000000ffU) << 24) | \
					      (((uint32_t) (val) & (uint32_t) 0x0000ff00U) <<  8) | \
					      (((uint32_t) (val) & (uint32_t) 0x00ff0000U) >>  8) | \
					      (((uint32_t) (val) & (uint32_t) 0xff000000U) >> 24)))

#define GUINT16_FROM_BE(val)	(GUINT16_TO_BE (val))
#define GUINT16_TO_BE(val)      (GUINT16_SWAP_LE_BE (val))
#define GUINT32_FROM_BE(val)	(GUINT32_TO_BE (val))
#define GUINT32_TO_BE(val)      (GUINT32_SWAP_LE_BE (val))
#define GINT16_FROM_BE(val)	(GUINT16_TO_BE (val))
#define GINT16_TO_BE(val)       ((int16_t)GUINT16_SWAP_LE_BE (val))
#define GINT32_FROM_BE(val)	(GUINT32_TO_BE (val))
#define GINT32_TO_BE(val)       ((int32_t)GUINT32_SWAP_LE_BE (val))

#define GStrv char**

#define G_LIKELY(expr) (expr)
#define G_UNLIKELY(expr) (expr)

#define G_STATIC_ASSERT(X)
#define G_GNUC_PRINTF(X, Y)
#define G_N_ELEMENTS(arr) (sizeof (arr) / sizeof ((arr)[0]))

#define NOOP_ do { (void) 0; } while (0)

#define g_malloc malloc
#define g_realloc realloc
#define g_free free
#define g_strdup(X) ((X) ? strdup(X) : 0)
#define g_warning printf
#define g_critical printf
#define g_error printf
#define g_strerror strerror
#define g_snprintf snprintf
#define g_vsnprintf vsnprintf
#define g_debug(...)
#define g_assert(...)
#define g_assert_not_reached() { fprintf(stderr, "ERROR: invalid state.\n"); abort(); }

#define g_strlcpy strlcpy
#define g_ascii_strcasecmp strcasecmp
#define g_strstr_len(H, HL, N) strnstr(H, N, HL)

#define g_getenv getenv

#define g_new0(T, N) (T*) calloc(N, sizeof(T))
#define g_new g_new0
#define g_malloc0(N) calloc(N, 1)

#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#define MAX(a, b)  (((a) < (b)) ? (b) : (a))

typedef void* GRand;

#define g_rand_int_range(X, B, E) (rand() % (E - B + 1) + B)
#define g_rand_new() 0
#define g_rand_free(X) NOOP_

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define FALSE 0
#define TRUE  1

#define g_warn_if_fail(E) NOOP_
#define g_return_if_fail(E) { if (!(E)) return; }
#define g_return_val_if_fail(E, VAL) { if (!(E)) return VAL; }

typedef void *gpointer;

typedef struct GStrings GString;

/* our replacement implementations in glib.c */
GString *g_string_new(const char *init);
char *g_string_free(GString *s, int ret);
void g_string_append_printf (GString* s, const char* fmt, ...);

#endif
