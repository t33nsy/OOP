#include "../headers/DoubleDamage.h"

auto DoubleDamage::UseSkill(size_t x, size_t y, GameField& field) -> bool {
  bool is_killed = false;
  for (int i = 0; i < 2; ++i) {
    try {
      is_killed = field.Attack(x, y, true);
    } catch (OutOfFieldException& e) {
      throw e;
    } catch (ShipKilled& e) {
      return is_killed;
    }
  }
  return is_killed;
}