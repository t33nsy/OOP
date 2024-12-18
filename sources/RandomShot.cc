#include "../headers/RandomShot.h"

auto RandomShot::UseSkill(size_t x, size_t y, GameField& field) -> Result {
  srand(time(NULL));
  size_t x_, y_;
  bool end = false;
  Result skill_result = Result::MISS;
  for (x_ = rand() % field.GetWidth(), y_ = rand() % field.GetHeight();;) {
    x_ = rand() % field.GetWidth();
    y_ = rand() % field.GetHeight();
    try {
      end = field.CheckCell(x_, y_);
    } catch (...) {
      continue;
    }
    if (end) {
      skill_result = field.Attack(x_, y_, false);
      break;
    }
  }
  return Result::MISS;
}