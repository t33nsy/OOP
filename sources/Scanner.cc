#include "../headers/Scanner.h"

auto Scanner::UseSkill(size_t x, size_t y, GameField& field) -> bool {
  bool flag = false;
  for (size_t i = x; i < x + 2; ++i) {
    for (size_t j = y; j < y + 2; ++j) {
      try {
        flag = field.CheckCell(i, j);
      } catch (OutOfFieldException& e) {
        throw e;
      }
      if (flag) {
        std::cout << "In some cells of the 2x2 square from (" << x << " ," << y
                  << ") to (" << x + 2 << " ," << y + 2
                  << ") opponent has ship\n";
        return false;
      }
    }
  }
  std::cout << "In the cells of the 2x2 square from (" << x << " ," << y
            << ") to (" << x + 2 << " ," << y + 2
            << ") opponent has not ship\n";
  return false;
}