#include <queue>

#include "../headers/NoSkillsException.h"
#include "DoubleDamage.h"
#include "RandomShot.h"
#include "Scanner.h"

class SkillManager {
 public:
  SkillManager();
  void GetRandomSkill();
  void AddSkill(int num);
  void UseOwnedSkill(size_t x, size_t y, GameField& field);

 private:
  std::queue<Skill*> skills_;
};