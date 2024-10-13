#include "Skill.h"

class Scanner : public Skill {
 public:
  void UseSkill(size_t x, size_t y, GameField& field) override;
};