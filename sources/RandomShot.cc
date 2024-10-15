#include "../headers/RandomShot.h"

auto RandomShot::UseSkill(size_t x, size_t y, GameField& field) -> bool {
  srand(time(NULL));
  size_t x_, y_;
  bool end = false, is_killed = false;
  for (x_ = rand() % field.GetWidth(), y_ = rand() % field.GetHeight();;) {
    x_ = rand() % field.GetWidth();
    y_ = rand() % field.GetHeight();
    try {
      end = field.CheckCell(x_, y_);
    } catch (...) {
      continue;
    }
    if (end == true) break;
  }
  try {
    is_killed = field.Attack(x_, y_, false);
  } catch (ShipKilled& e) {
    throw e;
  }
  return is_killed;
}