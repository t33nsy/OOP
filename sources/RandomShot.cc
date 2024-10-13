#include "../headers/RandomShot.h"

auto RandomShot::UseSkill(size_t x, size_t y, GameField& field) -> void {
  srand(time(NULL));
  size_t x, y;
  for (x = rand() % field.GetWidth(), y = rand() % field.GetHeight();
       field.CheckCell(x, y) != true;) {
    x = rand() % field.GetWidth();
    y = rand() % field.GetHeight();
  }
  field.Attack(x, y);
  return;
}