#include "../headers/DoubleDamage.h"

auto DoubleDamage::UseSkill(size_t x, size_t y, GameField& field) -> void {
  for (size_t i = 0; i < 2; ++i) {
    try {
      field.Attack(x, y);
    } catch (OutOfFieldException& e) {
      throw e;
    }
  }
}