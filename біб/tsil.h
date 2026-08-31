#ifndef TSIL_H
#define TSIL_H
#include <stdint.h>

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
typedef п64 природне;
typedef ц64 ціле;
typedef void ніщо;
typedef void* адреса_ніщо;
typedef void* памʼять_ніщо;

typedef struct кд кд;
typedef struct ю8 ю8;

struct кд {
  п8* дані;
  природне розмір;
};

struct ю8 {
  п8* дані;
  природне розмір;
};

#endif // TSIL_H