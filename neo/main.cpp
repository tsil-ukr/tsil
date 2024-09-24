#include "parser.h"

int main() {
  auto code = "ціль а: ц32 = б;";
  auto текстКоду = new ТекстКоду((char*)"...", (char*)code);
  auto parseResult = розібрати_ціль(текстКоду);
  if (parseResult.успіх) {
    for (int i = 0; i < parseResult.тіло->довжина; ++i) {
      const auto& astValue = parseResult.тіло->елементи[i];
      std::cout << tsil::parser::АСДЗначенняВString(astValue) << std::endl;
    }
  } else {
    std::cout << "Failed" << std::endl;
  }
  return 0;
}