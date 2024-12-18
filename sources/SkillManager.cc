#include "../headers/SkillManager.h"

SkillManager::SkillManager() {
  // srand(time(NULL));
  std::vector<int> added(3, -1);
  for (int i = 0; i < 3; ++i) {
    switch (i) {
      case 0:
        added[i] = rand() % 3;
        AddSkill(added[i]);
        break;
      case 1:
        added[i] = rand() % 3;
        while (added[i] == added[i - 1]) added[i] = rand() % 3;
        AddSkill(added[i]);
        break;
      case 2:
        added[i] = rand() % 3;
        while (added[i] == added[i - 1] || added[i] == added[i - 2])
          added[i] = rand() % 3;
        AddSkill(added[i]);
        break;
      default:
        break;
    }
  }
}

SkillManager::SkillManager(std::queue<SkillManager::SkillType> types) {
  while (!types.empty()) {
    AddSkill(types.front());
    types.pop();
  }
}

SkillManager::SkillManager(std::string serialized) {
  for (auto i : serialized) AddSkill(i - '0');
}

auto SkillManager::GetRandomSkill() -> void { AddSkill(rand() % 3); }

auto SkillManager::AddSkill(int num) -> void {
  switch (num) {
    case DOUBLEDAMAGE:  // enum
      skills_.push(new DoubleDamage());
      types_.push(DOUBLEDAMAGE);
      break;

    case RANDOMSHOT:
      skills_.push(new RandomShot());
      types_.push(RANDOMSHOT);
      break;

    case SCANNER:
      skills_.push(new Scanner());
      types_.push(SCANNER);
      break;

    default:
      return;
  }
}

auto SkillManager::UseOwnedSkill(size_t x, size_t y,
                                 GameField& field) -> Result {
  if (skills_.empty()) throw NoSkillsException();
  auto skill = skills_.front();
  Result skill_result = Result::MISS;
  try {
    skill_result = skill->UseSkill(x, y, field);
  } catch (OutOfFieldException& e) {
    throw e;
  } catch (ShipKilled& e) {
    throw e;
  }
  skills_.pop();
  types_.pop();
  return skill_result;
}

auto SkillManager::WhatSkillNow() -> SkillType {
  if (skills_.empty()) throw NoSkillsException();
  auto type = types_.front();
  return type;
}

auto SkillManager::Serialize() -> std::string {
  std::string serialized;
  std::queue<SkillType> tmp;
  std::queue<Skill*> temp;
  while (!skills_.empty()) {
    auto type = types_.front();
    serialized += std::to_string(type);
    tmp.push(type);
    temp.push(skills_.front());
    skills_.pop();
    types_.pop();
  }
  while (!tmp.empty()) {
    skills_.push(temp.front());
    types_.push(tmp.front());
    temp.pop();
    tmp.pop();
  }
  return serialized;
}