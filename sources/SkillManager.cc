#include "../headers/SkillManager.h"

SkillManager::SkillManager() {
  srand(time(NULL));
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

auto SkillManager::GetRandomSkill() -> void { AddSkill(rand() % 3); }

auto SkillManager::AddSkill(int num) -> void {
  switch (num) {
    case 0:
      skills_.push(new DoubleDamage());
      break;

    case 1:
      skills_.push(new RandomShot());
      break;

    case 2:
      skills_.push(new Scanner());
      break;

    default:
      return;
  }
}

auto SkillManager::UseOwnedSkill(size_t x, size_t y, GameField& field) -> void {
  if (skills_.empty()) throw NoSkillsException();
  auto skill = skills_.front();
  skill->UseSkill(x, y, field);
  skills_.pop();
}