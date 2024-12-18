#ifndef _t33nsy_TERMINALFIELD
#define _t33nsy_TERMINALFIELD

#include <windows.h>

#include <iostream>

#include "Ship.h"
class TerminalField {
 public:
  TerminalField() = default;
  TerminalField(int x, int y);
  TerminalField(int x, int y, std::vector<std::vector<char>> field,
                std::vector<std::vector<char>> opponent_field);
  auto PrintOnlyPlayer() -> void;

  auto PrintOnlyComp() -> void;

  auto ResetOpponentField() -> void;

  auto Reset() -> void;

  auto Print() -> void;

  auto ChangeState(int x, int y, Result result) -> void;

  auto ChangeCompState(int x, int y, Result result) -> void;

  auto PrintShip(int x, int y, int size, Orientation orient) -> void;

  auto DeleteShip(int x, int y, int size, Orientation orient) -> void;

  auto PrintInfo(std::string info) -> void;

  auto DeleteInfo() -> void;

  auto FixShip(int x, int y, int size, Orientation orient) -> void;

  auto DisplayPlayerPosition(int x, int y) -> void;

  auto getXcoord() -> short;

  auto getYcoord() -> short;

 private:
  int x_ = 0, y_ = 0;
  HANDLE hstdout_ = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD previous_position_ = {0, 0};
  std::vector<std::vector<char>> player_cells_, enemy_cells_;
};

#endif /* _t33nsy_TERMINALFIELD */
