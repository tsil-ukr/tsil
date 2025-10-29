extern "C" {
#include <libgen.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern "C" void* д_константа_Т8_розмір = nullptr;
extern "C" void* д_константа_Т8_дані = nullptr;
extern "C" void* д_константа_Т8_т8 = nullptr;
extern "C" void* д_константа_Т8_т32 = nullptr;
extern "C" void* д_константа_Т8_ю8 = nullptr;
extern "C" void* д_константа_Т8_ю32 = nullptr;
extern "C" void* д_константа_Т8_ніщо = nullptr;
extern "C" void* д_константа_Т8_адреса = nullptr;
extern "C" void* д_константа_Т8_невідома_адреса = nullptr;
extern "C" void* д_константа_Т8_памʼять = nullptr;
extern "C" void* д_константа_Т8_невідома_памʼять = nullptr;
extern "C" void* д_константа_Т8_логічне = nullptr;
extern "C" void* д_константа_Т8_ціле = nullptr;
extern "C" void* д_константа_Т8_позитивне = nullptr;
extern "C" void* д_константа_Т8_природне = nullptr;
extern "C" void* д_константа_Т8_натуральне = nullptr;
extern "C" void* д_константа_Т8_ц8 = nullptr;
extern "C" void* д_константа_Т8_ц16 = nullptr;
extern "C" void* д_константа_Т8_ц32 = nullptr;
extern "C" void* д_константа_Т8_ц64 = nullptr;
extern "C" void* д_константа_Т8_п8 = nullptr;
extern "C" void* д_константа_Т8_п16 = nullptr;
extern "C" void* д_константа_Т8_п32 = nullptr;
extern "C" void* д_константа_Т8_п64 = nullptr;
extern "C" void* д_константа_Т8_н8 = nullptr;
extern "C" void* д_константа_Т8_н16 = nullptr;
extern "C" void* д_константа_Т8_н32 = nullptr;
extern "C" void* д_константа_Т8_н64 = nullptr;
extern "C" void* д_константа_Т8_р32 = nullptr;
extern "C" void* д_константа_Т8_р64 = nullptr;
extern "C" void* д_константа_Т8_д32 = nullptr;
extern "C" void* д_константа_Т8_д64 = nullptr;
extern "C" void* д_константа_Т8_так = nullptr;
extern "C" void* д_константа_Т8_ні = nullptr;
extern "C" void* д_константа_Т8_пусто = nullptr;
extern "C" void* д_константа_Т8_визначення = nullptr;
extern "C" void* д_константа_Т8_заявлення = nullptr;
extern "C" void* д_константа_Т8_біб = nullptr;
extern "C" void* д_константа_Т8_вміст = nullptr;
extern "C" void* д_константа_Т8__розділювач_шляху = nullptr;
extern "C" void* д_константа_Т8__розділювач_шляху__визначення = nullptr;
extern "C" void* д_константа_Т8__розділювач_шляху__заявлення = nullptr;
extern "C" void* д_константа_Т8__закінчення_шляху__вц = nullptr;
extern "C" void* д_константа_Т8__закінчення_шляху__зц = nullptr;
extern "C" void* д_константа_Т8_тіло_якщо = nullptr;
extern "C" void* д_константа_Т8_тіло_інакше = nullptr;
extern "C" void* д_константа_Т8_тіло_якщо_вихід = nullptr;
extern "C" void* д_константа_Т8_накопичення = nullptr;
extern "C" void* д_константа_Т8_вихід = nullptr;
extern "C" void* д_константа_Т8_початок = nullptr;
extern "C" void* д_константа_Т8_або_інакше = nullptr;
extern "C" void* д_константа_Т8_або_вихід = nullptr;
extern "C" void* д_константа_Т8_умова_поки = nullptr;
extern "C" void* д_константа_Т8_тіло_поки = nullptr;
extern "C" void* д_константа_Т8_тіло_поки_вихід = nullptr;

#define п8 uint8_t
#define п16 uint16_t
#define п32 uint32_t
#define п64 uint64_t
#define ц8 int8_t
#define ц16 int16_t
#define ц32 int32_t
#define ц64 int64_t
#define д32 float
#define д64 double
#define логічне uint8_t
#define позитивне п64
#define ціле ц64
#define дійсне д64
#define ніщо void
#define невідома_адреса void*
#define невідома_памʼять void*
#define памʼять_п8 п8*
#define адреса_памʼять_п8 п8**
#define памʼять_памʼять_п8 п8**
#define адреса_позитивне позитивне*
typedef struct т8 {
  позитивне розмір;
  памʼять_п8 дані;
} т8;
typedef struct ю8 {
  позитивне розмір;
  памʼять_п8 дані;
} ю8;
typedef struct Шлях {
  позитивне розмір;
  памʼять_п8 дані;
} Шлях;
typedef struct Байти {
  позитивне розмір;
  памʼять_п8 дані;
} Байти;

typedef struct Виділяч {
  невідома_адреса користувацькі_дані;

  памʼять_п8 (*виділити_сиру_памʼять)(Виділяч* виділяч, позитивне розмір);

  памʼять_п8 (*перевиділити_сиру_памʼять)(Виділяч* виділяч,
                                          памʼять_п8 значення,
                                          позитивне новий_розмір);

  void (*звільнити_сиру_памʼять)(Виділяч* виділяч, памʼять_п8 значення);
} Виділяч;

extern void __КЦ__прочитати_файл(Виділяч* виділяч,
                                 Шлях* шлях,
                                 Байти* вихід,
                                 логічне* успіх) {
  char* filename =
      (char*)виділяч->виділити_сиру_памʼять(виділяч, шлях->розмір + 1);
  memcpy(filename, шлях->дані, шлях->розмір);
  filename[шлях->розмір] = 0;

  FILE* file = fopen(filename, "rb");

  free(filename);

  if (!file) {
    *успіх = false;
    return;
  }

  fseek(file, 0, SEEK_END);
  long filesize = ftell(file);
  rewind(file);

  char* buffer = (char*)виділяч->виділити_сиру_памʼять(виділяч, filesize);
  if (!buffer) {
    fclose(file);
    *успіх = false;
    return;
  }

  size_t read_size = fread(buffer, 1, filesize, file);

  fclose(file);

  Байти дані = {.розмір = read_size, .дані = (памʼять_п8)buffer};
  *успіх = true;
  *вихід = дані;
}

void __КЦ__записати_файл(Виділяч* виділяч,
                         Шлях* шлях,
                         Байти* значення,
                         логічне* успіх) {
  char* filename =
      (char*)виділяч->виділити_сиру_памʼять(виділяч, шлях->розмір + 1);
  memcpy(filename, шлях->дані, шлях->розмір);
  filename[шлях->розмір] = 0;

  FILE* file = fopen(filename, "wb");

  free((void*)filename);

  if (!file) {
    *успіх = false;
    return;
  }

  fwrite(значення->дані, 1, значення->розмір, file);

  fclose(file);

  *успіх = true;
}

логічне __КЦ__перевірити_чи_шлях_існує(Виділяч* виділяч, Шлях* шлях) {
  char* filename =
      (char*)виділяч->виділити_сиру_памʼять(виділяч, шлях->розмір + 1);
  memcpy(filename, шлях->дані, шлях->розмір);
  filename[шлях->розмір] = 0;

  FILE* file = fopen(filename, "rb");

  if (file) {
    free(filename);
    fclose(file);
    return true;
  } else {
    free(filename);
    return false;
  }
}

логічне __КЦ__отримати_директорію_шляху_до_файлу(Виділяч* виділяч,
                                                 Шлях* вхід,
                                                 Шлях* вихід) {
  char* filename =
      (char*)виділяч->виділити_сиру_памʼять(виділяч, вхід->розмір + 1);
  memcpy(filename, вхід->дані, вхід->розмір);
  filename[вхід->розмір] = 0;

  const char* absolute_path = realpath(filename, NULL);
  free((void*)filename);
  if (absolute_path == NULL) {
    return false;
  }
  const char* parent_path = dirname((char*)absolute_path);
  if (parent_path == NULL) {
    return false;
  } else {
    вихід->розмір = strlen(parent_path);
    вихід->дані = (памʼять_п8)parent_path;
  }
  return true;
}

логічне __КЦ__отримати_поточну_директорію_процесу(Виділяч* виділяч,
                                                  Шлях* вихід) {
  const char* cwd = getcwd(NULL, 0);
  вихід->розмір = strlen(cwd);
  вихід->дані = (памʼять_п8)cwd;
  return true;
}

логічне __КЦ__отримати_абсолютний_шлях(Виділяч* виділяч,
                                       Шлях* вхід,
                                       Шлях* вихід) {
  char* filename =
      (char*)виділяч->виділити_сиру_памʼять(виділяч, вхід->розмір + 1);
  memcpy(filename, вхід->дані, вхід->розмір);
  filename[вхід->розмір] = 0;

  char* absolute_path = realpath(filename, NULL);

  free((void*)filename);

  вихід->розмір = strlen(absolute_path);
  вихід->дані = (памʼять_п8)absolute_path;
  return true;
}

void __КЦ__отримати_версію_цілі_як_ю8(ю8* вихід) {
  вихід->розмір = strlen(TSIL_VERSION);
  вихід->дані = (памʼять_п8)TSIL_VERSION;
}

ц32 розпочати(позитивне кількість_аргументів, Байти* байти);
}

int main(int argc, char** argv) {
  auto аргументи = (Байти*)malloc(sizeof(Байти) * argc);
  for (int i = 0; i < argc; ++i) {
    Байти байти = {.розмір = strlen(argv[i]), .дані = (памʼять_п8)argv[i]};
    аргументи[i] = байти;
  }
  int res = розпочати(argc, аргументи);
  free(аргументи);
  return res;
}