#ifndef TSILINT_H
#define TSILINT_H

/* ========================================================================== */
/* EXACT-WIDTH SIGNED INTEGERS                                                */
/* ========================================================================== */

#if defined(__INT8_TYPE__)
typedef __INT8_TYPE__ int8_t;
#else
typedef signed char int8_t;
#endif

#if defined(__INT16_TYPE__)
typedef __INT16_TYPE__ int16_t;
#else
typedef short int16_t;
#endif

#if defined(__INT32_TYPE__)
typedef __INT32_TYPE__ int32_t;
#elif defined(_MSC_VER)
/* MSVC: int is 32-bit on every supported (x86 / x64 / ARM) target */
typedef int int32_t;
#elif defined(_WIN32) || defined(__i386__) || defined(__arm__) || \
    defined(__LP64__) || defined(_LP64) || defined(__aarch64__)
/* 32-bit int on these ABIs (incl. LP64 where long is 64-bit but int 32) */
typedef int int32_t;
#else
/* Unknown platform: pick the first type that is actually 32 bits wide */
#include <limits.h>
#if INT_MAX == 0x7FFFFFFF
typedef int int32_t;
#elif LONG_MAX == 0x7FFFFFFF
typedef long int32_t;
#else
#error "tsilint.h: no 32-bit signed integer type available"
#endif
#endif

#if defined(__INT64_TYPE__)
typedef __INT64_TYPE__ int64_t;
#elif defined(_MSC_VER)
typedef __int64 int64_t;
#elif defined(__LP64__) || defined(_LP64)
typedef long int64_t;
#else
typedef long long int64_t;
#endif

/* ========================================================================== */
/* EXACT-WIDTH UNSIGNED INTEGERS                                              */
/* ========================================================================== */

#if defined(__UINT8_TYPE__)
typedef __UINT8_TYPE__ uint8_t;
#else
typedef unsigned char uint8_t;
#endif

#if defined(__UINT16_TYPE__)
typedef __UINT16_TYPE__ uint16_t;
#else
typedef unsigned short uint16_t;
#endif

#if defined(__UINT32_TYPE__)
typedef __UINT32_TYPE__ uint32_t;
#elif defined(_MSC_VER)
typedef unsigned int uint32_t;
#elif defined(_WIN32) || defined(__i386__) || defined(__arm__) || \
    defined(__LP64__) || defined(_LP64) || defined(__aarch64__)
typedef unsigned int uint32_t;
#else
#include <limits.h>
#if UINT_MAX == 0xFFFFFFFF
typedef unsigned int uint32_t;
#elif ULONG_MAX == 0xFFFFFFFF
typedef unsigned long uint32_t;
#else
#error "tsilint.h: no 32-bit unsigned integer type available"
#endif
#endif

#if defined(__UINT64_TYPE__)
typedef __UINT64_TYPE__ uint64_t;
#elif defined(_MSC_VER)
typedef unsigned __int64 uint64_t;
#elif defined(__LP64__) || defined(_LP64)
typedef unsigned long uint64_t;
#else
typedef unsigned long long uint64_t;
#endif

/* ========================================================================== */
/* size_t                                                                      */
/* ========================================================================== */
/* Matches the type returned by sizeof. On GCC/Clang __SIZE_TYPE__ is the     */
/* exact type the compiler uses for sizeof, so it's always correct.            */
#if !defined(_SIZE_T) && !defined(_SIZE_T_DEFINED) && !defined(_SIZE_T_DECLARED)
#if defined(__SIZE_TYPE__)
typedef __SIZE_TYPE__ size_t;
#elif defined(_MSC_VER)
#if defined(_WIN64)
typedef unsigned __int64 size_t;
#else
typedef unsigned int size_t;
#endif
#elif defined(__LP64__) || defined(_LP64)
typedef unsigned long size_t;
#else
typedef unsigned int size_t;
#endif
#define _SIZE_T
#define _SIZE_T_DEFINED
#define _SIZE_T_DECLARED
#endif

/* ========================================================================== */
/* ssize_t  (POSIX, not Standard C)                                          */
/* ========================================================================== */
/* Signed counterpart of size_t with the same width.                          */
/* NOTE: ssize_t is NOT defined by the C standard. If you also include        */
/* <sys/types.h> on a POSIX system, it will already be defined; the guards     */
/* below (_SSIZE_T / _SSIZE_T_DEFINED / _SSIZE_T_DECLARED) prevent a clash.   */
/* On MSVC there is no native ssize_t; BaseTsd.h only has SSIZE_T (uppercase). */
#if !defined(_SSIZE_T) && !defined(_SSIZE_T_DEFINED) && \
    !defined(_SSIZE_T_DECLARED)
#if defined(__PTRDIFF_TYPE__)
/* __PTRDIFF_TYPE__ is pointer-width and signed, so it matches the width  */
/* of __SIZE_TYPE__ on every standard ABI.                                 */
typedef __PTRDIFF_TYPE__ ssize_t;
#elif defined(_MSC_VER)
#if defined(_WIN64)
typedef __int64 ssize_t;
#else
typedef int ssize_t;
#endif
#elif defined(__LP64__) || defined(_LP64)
typedef long ssize_t;
#else
typedef int ssize_t;
#endif
#define _SSIZE_T
#define _SSIZE_T_DEFINED
#define _SSIZE_T_DECLARED
#endif

typedef uint8_t п8;
typedef uint16_t п16;
typedef uint32_t п32;
typedef uint64_t п64;
typedef int8_t ц8;
typedef int16_t ц16;
typedef int32_t ц32;
typedef int64_t ц64;
typedef float р32;
typedef double р64;
typedef uint8_t логічне;
typedef size_t природне;
typedef ssize_t ціле;
typedef void ніщо;
typedef void* адреса;

static const логічне ні = 0;
static const логічне так = 1;
static const адреса пусто = 0;

#endif /* TSILINT */
