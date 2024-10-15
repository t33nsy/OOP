#ifndef DD_H
#define DD_H
#include "Skill.h"

class DoubleDamage : public Skill {
 public:
  bool UseSkill(size_t x, size_t y, GameField& field) override;
};

#endif