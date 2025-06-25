#include <stdint.h>
#include <stdio.h>

#define п8 uint8_t
#define ц32 int32_t

extern void вивести_символ(п8 символ) {
  putchar(символ);
}

extern ц32 запустити();

int main() {
  return запустити();
}