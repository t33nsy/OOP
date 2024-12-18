#include "../headers/Scanner.h"

auto Scanner::UseSkill(size_t x, size_t y, GameField& field) -> Result {
  bool flag = false;
  for (size_t i = x; i < x + 2; ++i) {
    for (size_t j = y; j < y + 2; ++j) {
      try {
        flag = field.CheckCell(i, j);
      } catch (OutOfFieldException& e) {
        throw e;
      }
      if (flag) {
        return Result::SHIP_FOUND;
      }
    }
  }
  return Result::SHIP_NOT_FOUND;
}