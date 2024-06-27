<img src="./assets/logo.png" width="70" height="70" />

# Ціль

Проста, швидка та компільована мова програмування з можливістю інтеграції з C/C++.

## Приклад

Створіть файл `привіт.ц`:

```ціль
зовнішня дія друк_ю8(значення: памʼять<п8>);

дія старт() {
  друк_ю8(ю8"Вперед до Цілі!");
}
```

Створіть файл `extension.cpp`:

```c++
#include <iostream>

extern "C" void друк_ю8(unsigned char* val) {
  std::cout << val << std::endl;
}
```

Скомпілюйте та виконайте програму:

```shell
ціль привіт сплавити привіт.ц extension.cpp
./привіт
```

## Розробка

### Вимоги

- Linux, x86_64
- CLang/LLVM
- CMake
- Java 8+ (необовʼзково, треба для ANTLR4)

### Скрипти

Побудова локального проекту:

```shell
bash scripts/build.sh bin
```

Побудова випуску:

```shell
bash scripts/release.sh
```