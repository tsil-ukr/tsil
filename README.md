<img src="./assets/logo.png" width="100" height="100" />

# Ціль

Сучасна компільована українська мова програмування.

## Приклад

Створіть файл `привіт.ц`:

```ціль
зовнішня дія друк_сі(значення: комірка<п8>);

дія старт() {
  друк_сі(сі"привіт!");
}
```

Створіть файл `extension.cpp`:

```shell
#include <iostream>

extern "C" void друк_сі(char* val) {
  std::cout << val << std::endl;
}
```

Скомпілюйте та виконайте програму:

```shell
ціль сплавити привіт.ц привіт.ll
clang++ -o привіт привіт.o extension.cpp
./привіт
```