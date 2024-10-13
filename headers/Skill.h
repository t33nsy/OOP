#include "ShipManager.h"

class Skill {
 public:
  virtual void UseSkill() = 0;
  virtual ~Skill() = default;
};