extern "C" {
#include <libgen.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#if defined(_WIN32)
#include <windows.h>
#elif defined(__linux__)
#include <limits.h>
#elif defined(__APPLE__)
#include <mach-o/dyld.h>
#include <sys/syslimits.h>
#endif

#define п8 uint8_t
#define п16 uint16_t
#define п32 uint32_t
#define п64 uint64_t
#define ц8 int8_t
#define ц16 int16_t
#define ц32 int32_t
#define ц64 int64_t
#define р32 float
#define р64 double
#define логічне uint8_t
#define природне п64
#define ціле ц64
#define ніщо void
#define адреса_ніщо void*
#define памʼять_ніщо void*
typedef struct кд {
  п8* дані;
  природне розмір;
} кд;
typedef struct ю8 {
  п8* дані;
  природне розмір;
} ю8;

static char* get_exe_path(void) {
#if defined(_WIN32)
  DWORD size = 256;
  char* buffer = NULL;

  while (1) {
    char* new_buf = realloc(buffer, size);
    if (!new_buf) {
      free(buffer);
      return NULL;
    }
    buffer = new_buf;

    DWORD len = GetModuleFileNameA(NULL, buffer, size);
    if (len == 0) {
      free(buffer);
      return NULL;
    }
    if (len < size) {
      return buffer;
    }
    size *= 2;
  }

#elif defined(__linux__)
  size_t size = 256;
  char* buffer = NULL;

  while (1) {
    char* new_buf = (char*)realloc(buffer, size);
    if (!new_buf) {
      free(buffer);
      return NULL;
    }
    buffer = new_buf;

    ssize_t len = readlink("/proc/self/exe", buffer, size - 1);
    if (len == -1) {
      free(buffer);
      return NULL;
    }

    if ((size_t)len < size - 1) {
      buffer[len] = '\0';
      return buffer;
    }
    size *= 2;
  }

#elif defined(__APPLE__)
  uint32_t size = 0;
  if (_NSGetExecutablePath(NULL, &size) != -1) {
    return NULL;
  }

  char* buffer = malloc(size);
  if (!buffer)
    return NULL;

  if (_NSGetExecutablePath(buffer, &size) == 0) {
    return buffer;
  }

  free(buffer);
  return NULL;

#else
  return NULL;
#endif
}

void __КЦ__отримати_версію_цілі_як_ю8(ю8* вихід) {
  вихід->дані = (п8*)TSIL_VERSION;
  вихід->розмір = strlen(TSIL_VERSION);
}

void __КЦ__отримати_шлях_до_цілі_як_ю8(ю8* вихід) {
  char* exe_path = get_exe_path();
  if (!exe_path) {
    вихід->дані = NULL;
    вихід->розмір = 0;
    return;
  }
  вихід->дані = (п8*)exe_path;
  вихід->розмір = strlen(exe_path);
}

ц32 почати(природне кількість_аргументів, ю8* аргументи);
}

int main(int argc, char** argv) {
  auto аргументи = (ю8*)malloc(sizeof(ю8) * argc);
  for (int i = 0; i < argc; ++i) {
    ю8 байти = {.дані = (п8*)argv[i], .розмір = strlen(argv[i])};
    аргументи[i] = байти;
  }
  int res = почати(argc, аргументи);
  free(аргументи);
  return res;
}