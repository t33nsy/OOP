#include "../headers/DoubleDamage.h"

auto DoubleDamage::UseSkill(size_t x, size_t y, GameField& field) -> Result {
  Result skill_result = Result::MISS;
  for (int i = 0; i < 2; ++i) {
    try {
      skill_result = field.Attack(x, y, true);
    } catch (OutOfFieldException& e) {
      throw e;
    } catch (ShipKilled& e) {
      return skill_result;
    }
  }
  return skill_result;
}