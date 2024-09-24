#include "parser.h"

int main() {
  // read file тест.ц
  std::ifstream file("тест.ц");
  std::string code((std::istreambuf_iterator<char>(file)),
                   std::istreambuf_iterator<char>());
  auto текстКоду = new ТекстКоду((char*)"...", (char*)code.c_str());
  auto parseResult = розібрати_ціль(текстКоду);
  if (parseResult.успіх) {
    for (int i = 0; i < parseResult.тіло->довжина; ++i) {
      const auto& astValue = parseResult.тіло->елементи[i];
      std::cout << tsil::parser::АСДЗначенняВString(astValue) << std::endl;
    }
  } else {
    std::cout << "Failed" << std::endl;
    std::cout << parseResult.помилка->повідомлення << std::endl;
  }
  return 0;
}