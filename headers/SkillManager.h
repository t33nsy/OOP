#ifndef SKILL_MANAGER_H
#define SKILL_MANAGER_H
#include <queue>

#include "NoSkillsException.h"
#include "DoubleDamage.h"
#include "RandomShot.h"
#include "Scanner.h"

class SkillManager {
 public:
  SkillManager();
  void GetRandomSkill();
  void AddSkill(int num);
  void UseOwnedSkill(size_t x, size_t y, GameField& field);
  void WhatSkillNow();

 private:
  std::queue<Skill*> skills_;
};

#endif