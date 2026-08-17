#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef int32_t ц32;
typedef uint8_t п8;
typedef size_t природне;

typedef struct {
  п8* дані;
  природне розмір;
} Аргумент;

ц32 почати(природне к, Аргумент* а);

int main(int argc, char** argv) {
  Аргумент* а = (Аргумент*)malloc(argc);
  for (size_t i = 0; i < argc; i++) {
    а[i].дані = (п8*)argv[i];
    а[i].розмір = (природне)strlen(argv[i]);
  }

  return почати(argc, а);
}