#ifndef _GAME_H_
#define _GAME_H_

#include "ComputerEnemy.h"
#include "GameField.h"
#include "GameState.h"
#include "ShipManager.h"
#include "SkillManager.h"
#include "FileHandler.h"

class Game {
 public:
  enum TurnType { SKILL, ATTACK };

  Game() = default;

  ~Game();

  auto StartNewGame(int fieldx, int fieldy, int ship_num,
                    std::vector<int> ship_sizes) -> void;

  auto StartNewGame(int fieldx, int fieldy) -> void;

  auto AddShipOnField(size_t index, int x, int y,
                      Orientation orientation) -> void;

  auto AddShip(int x, int y, int size, Orientation orientation) -> void;

  auto RandomlyPlaceShips() -> void;

  auto StartNewRound() -> void;

  auto SaveGame(std::string filename) -> void;

  auto LoadGame(std::string filename) -> void;

  auto DoTurn(TurnType type, int x, int y) -> Result;

  auto ComputerTurn(int &x, int &y) -> Result;

  auto Serialize() -> void;

  auto getFieldSizes() -> std::pair<int, int>;

  auto getFieldInChar() -> std::vector<std::vector<char>>;

  auto getOpponentFieldInChar() -> std::vector<std::vector<char>>;

 private:
  auto checkForWin() -> bool;

  auto checkForLose() -> bool;

  GameField *field_ = nullptr, *opponent_field_ = nullptr;
  ShipManager *ship_manager_ = nullptr, *opponent_ship_manager_ = nullptr;
  SkillManager *skill_manager_ = nullptr;
  GameState state_;
  ComputerEnemy *enemy_;
  std::vector<GameField::ShipPlacement> ship_placements_,
      opponent_ship_placements_;
};

#endif  //_GAME_H_