#ifndef SKILL_H
#define SKILL_H
#include "ShipManager.h"

class Skill {
 public:
  virtual Result UseSkill(size_t x, size_t y, GameField& field) = 0;
};

#endif