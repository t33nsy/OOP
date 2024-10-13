#ifndef _GAME_H_
#define _GAME_H_
#include <conio.h>

#include <ctime>
#include <random>

#include "ShipManager.h"
#include "SkillManager.h"

class Game {
 public:
  Game();
  auto start() -> void;
  auto play() -> void;

 private:
  std::vector<int> ship_lens_;
  HANDLE hstdout_;
  int field_size_x_, field_size_y_, x_, y_, n_;
  char flag_;
  ShipManager *ship_manager_;
  GameField *field_;
  SkillManager *skill_manager_;
};

#endif