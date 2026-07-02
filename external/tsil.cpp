extern "C" {
#include <libgen.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

void __КЦ__отримати_версію_цілі_як_ю8(ю8* вихід) {
  вихід->дані = (п8*)TSIL_VERSION;
  вихід->розмір = strlen(TSIL_VERSION);
}

ц32 розпочати(природне кількість_аргументів, ю8* байти);
}

int main(int argc, char** argv) {
  auto аргументи = (ю8*)malloc(sizeof(ю8) * argc);
  for (int i = 0; i < argc; ++i) {
    ю8 байти = {.дані = (п8*)argv[i], .розмір = strlen(argv[i])};
    аргументи[i] = байти;
  }
  int res = розпочати(argc, аргументи);
  free(аргументи);
  return res;
}