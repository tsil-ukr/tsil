extern "C" {
#include <libgen.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
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
typedef struct Шлях {
  природне розмір;
  п8* дані;
  природне вмісткість;
} Шлях;

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

static char* шлях_до_c_рядка(const Шлях* ш) {
  if (!ш || !ш->дані)
    return NULL;
  char* str = (char*)malloc(ш->розмір + 1);
  if (!str)
    return NULL;
  memcpy(str, ш->дані, ш->розмір);
  str[ш->розмір] = '\0';
  return str;
}

ц32 __КЦ__кланг_лінк(Шлях* вих,
                     природне кф,
                     Шлях* сф,
                     природне кллвір,
                     Шлях* сллвмір) {
  if (!вих || !вих->дані)
    return -1;

  char* вих_str = шлях_до_c_рядка(вих);
  if (!вих_str)
    return -1;

  size_t total_args = 3 + (кф) + (кллвір * 3) + 1;
  char** args = (char**)malloc(sizeof(char*) * total_args);
  if (!args) {
    free(вих_str);
    return -1;
  }

  size_t idx = 0;
  args[idx++] = strdup("clang");
  args[idx++] = strdup("-o");
  args[idx++] = вих_str;

  for (природне i = 0; i < кф; ++i) {
    char* in_str = шлях_до_c_рядка(&сф[i]);
    if (!in_str) {
      for (size_t j = 0; j < idx; ++j)
        free(args[j]);
      free(args);
      return -1;
    }
    args[idx++] = in_str;
  }

  for (природне i = 0; i < кллвір; ++i) {
    char* in_str = шлях_до_c_рядка(&сллвмір[i]);
    if (!in_str) {
      for (size_t j = 0; j < idx; ++j)
        free(args[j]);
      free(args);
      return -1;
    }
    args[idx++] = strdup("-x");
    args[idx++] = strdup("ir");
    args[idx++] = in_str;
  }
  args[idx] = NULL;

  // printf(">");
  // for (size_t i = 0; args[i] != NULL; ++i) {
  //   printf(" %s", args[i]);
  // }
  // printf("\n");
  // fflush(stdout);

  pid_t pid = fork();
  if (pid == 0) {
    execvp("clang", args);
    _exit(127);
  } else if (pid < 0) {
    for (size_t j = 0; j < idx; ++j) {
      free(args[j]);
    }
    free(args);
    return -1;
  }

  int status = 0;
  waitpid(pid, &status, 0);

  for (size_t j = 0; j < idx; ++j) {
    free(args[j]);
  }
  free(args);

  if (WIFEXITED(status)) {
    return WEXITSTATUS(status);
  }

  return -1;
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