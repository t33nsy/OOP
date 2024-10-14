#include "../headers/RandomShot.h"

auto RandomShot::UseSkill(size_t x, size_t y, GameField& field) -> void {
  srand(time(NULL));
  size_t x_, y_;
  bool end = false;
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
  field.Attack(x_, y_, false);
}