#ifndef _GAMEFIELD_H_
#define _GAMEFIELD_H_

#include "OutOfFieldException.h"
#include "CollisionException.h"
#include "Ship.h"

class GameField {
 public:
  //* enum class with three types of cell state
  enum CellState { UNKNOWN, EMPTY, SHIP };

  //* constructor with arguments of width and height
  GameField(size_t size_x, size_t size_y);

  //* copy constructor
  GameField(const GameField& other);

  // * copy assignment operator
  auto operator=(const GameField& other) -> GameField&;

  // * move constructor
  GameField(GameField&& other);

  // * move assignment operator
  auto operator=(GameField&& other) -> GameField&;

  //* destructor
  ~GameField();

  //* method for adding a ship to the field on given coordinates with given
  // direction (vertical or horizontal)
  auto AddShip(Ship* ship, const size_t& x, const size_t& y, const bool& vertical) -> void;

  //* method for printing the field to the console
  auto PrintField() -> void;

  //* method for printing the field to the console
  auto PrintField(HANDLE& hStdOut) -> void;

  //* method for doing a field look like opponents (all cells in unknown state)
  auto DoLikeItOpponents() -> void;

  //* method for doing a field look like yours (all cell states are known)
  auto DoVisible() -> void;

  //* method for attacking a ship on given coordinates
  auto Attack(const size_t& x, const size_t& y) -> void;

  //* method for checking if there is a ship's collision on given coordinates
  auto CheckForCollision(const size_t& x, const size_t& y) -> void;

  //* method for getting field's width
  auto GetWidth() -> size_t;

  //* method for getting field's height
  auto GetHeight() -> size_t;

 private:
  size_t size_x_, size_y_;
  std::vector<std::vector<CellState>> field_;
  std::vector<std::vector<std::pair<Ship*, size_t>>> ship_indices_;
};

#endif