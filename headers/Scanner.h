#ifndef SCANNER_H
#define SCANNER_H
#include "Skill.h"

class Scanner : public Skill {
 public:
  bool UseSkill(size_t x, size_t y, GameField& field) override;
};

#endif