#include "../headers/DoubleDamage.h"

auto DoubleDamage::UseSkill(size_t x, size_t y, GameField& field) -> void {
  for (int i = 0; i < 2; ++i) {
    try {
      field.Attack(x, y, true);
    } catch (OutOfFieldException& e) {
      throw e;
    }
  }
}