#include <stdint.h>
#include <stdio.h>

#define н8 uint8_t
#define ц32 int32_t
#define натуральне uint64_t

extern void вивести_символ(н8 символ) {
  putchar(символ);
}

extern void вивести_натуральне(натуральне символ) {
  printf("%ld", символ);
}

extern ц32 запустити();

int main() {
  return запустити();
}