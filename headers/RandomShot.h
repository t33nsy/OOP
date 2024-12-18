#ifndef RANDOMSHOT_H
#define RANDOMSHOT_H
#include "Skill.h"

class RandomShot : public Skill {
 public:
  Result UseSkill(size_t x, size_t y, GameField& field) override;
};

#endif