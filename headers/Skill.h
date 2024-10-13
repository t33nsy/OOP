#include "ShipManager.h"

class Skill {
 public:
  virtual void UseSkill(size_t x, size_t y, GameField& field) = 0;
  virtual ~Skill() = default;
};