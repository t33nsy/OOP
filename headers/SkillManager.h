#ifndef SKILL_MANAGER_H
#define SKILL_MANAGER_H
#include <queue>

#include "DoubleDamage.h"
#include "NoSkillsException.h"
#include "RandomShot.h"
#include "Scanner.h"

class SkillManager {
 public:
  enum SkillType { DOUBLEDAMAGE, RANDOMSHOT, SCANNER };
  SkillManager();
  auto GetRandomSkill() -> void;
  auto AddSkill(int num) -> void;
  auto UseOwnedSkill(size_t x, size_t y, GameField& field) -> bool;
  auto WhatSkillNow() -> SkillType;

 private:
  std::queue<Skill*> skills_;
  std::queue<SkillType> types_;
};

#endif