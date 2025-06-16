#include <arpa/inet.h>
#include <liburing.h>
#include <netinet/in.h>
#include <poll.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

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
#define невідома_адреса void *
#define невідома_памʼять void *
#define памʼять_п8 п8 *
#define адреса_памʼять_п8 п8 **
#define памʼять_памʼять_п8 п8 **
#define адреса_позитивне позитивне *
typedef struct т8 {
  позитивне розмір;
  памʼять_п8 дані;
} т8;
typedef struct ю8 {
  позитивне розмір;
  памʼять_п8 дані;
} ю8;
#define памʼять_т8 т8 *
#define памʼять_ю8 ю8 *

extern void __біб__вивести_позитивне(позитивне значення) {
  printf("%lu", значення);
  fflush(stdout);
}

extern void __біб__надрукувати_позитивне(позитивне значення) {
  printf("%lu\n", значення);
  fflush(stdout);
}

extern логічне прочитати_файл_повністю_ю8(ю8 шлях, ю8 *вихід) {
  char *filename = malloc(шлях.розмір + 1);
  strncpy(filename, (char *)шлях.дані, шлях.розмір);
  FILE *file = fopen(filename, "rb"); // Open in binary mode
  free(filename);
  if (!file) {
    perror("Failed to open file");
    return false;
  }

  // Seek to the end to get the file size
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file); // Go back to the beginning

  // Allocate buffer
  char *buffer = (char *)malloc(size + 1);
  if (!buffer) {
    perror("Failed to allocate memory");
    fclose(file);
    return false;
  }

  // Read the file into the buffer
  size_t read_size = fread(buffer, 1, size, file);
  buffer[read_size] = '\0'; // Null-terminate the string

  fclose(file);

  вихід->розмір = strlen(buffer);
  вихід->дані = (памʼять_п8)buffer;

  return true;
}