#ifndef SKILL_MANAGER_H
#define SKILL_MANAGER_H
#include <queue>

#include "DoubleDamage.h"
#include "NoSkillsException.h"
#include "RandomShot.h"
#include "Scanner.h"

class SkillManager {
 public:
  enum SkillType { DOUBLEDAMAGE = 0, RANDOMSHOT = 1, SCANNER = 2 };
  SkillManager();
  explicit SkillManager(std::string serialized);
  explicit SkillManager(std::queue<SkillManager::SkillType> types);
  auto GetRandomSkill() -> void;
  auto AddSkill(int num) -> void;
  auto UseOwnedSkill(size_t x, size_t y, GameField& field) -> Result;
  auto WhatSkillNow() -> SkillType;
  auto Serialize() -> std::string;

 private:
  std::queue<Skill*> skills_;
  std::queue<SkillType> types_;
};

#endif