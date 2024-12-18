#ifndef _SHIP_H_
#define _SHIP_H_
#include <stdint.h>
#include <windows.h>

#include <algorithm>
#include <iostream>
#include <vector>

#include "ShipKilled.h"

enum Result {
  FULL_DESTROYED,
  HALF_HP,
  DESTROYED,
  MISS,
  SHIP_FOUND,
  SHIP_NOT_FOUND,
  WIN,
  LOSE
};

enum State { KILLED = 0, DAMAGED = 1, INTACT = 2 };

enum Orientation { HORIZONTAL = 0, VERTICAL = 1, UNSET = 2 };

class Ship {
 public:
  //* enum class with given three states of the ship segment
  //* parameterized constructor which gets size of the ship
  explicit Ship(int len);

  explicit Ship(std::string serialized);

  Ship(int len, std::vector<State> segments);

  //* parameterized constructor which gets size of the ship and orientation of
  //* the ship
  Ship(int len, bool vertical);

  //* destructor
  ~Ship();

  //* getters and setters
  //* method for setting length of the ship
  auto SetLength(int length) -> void;
  //* method for getting length of the ship
  auto GetLength() -> int;
  //* method for setting orientation of the ship
  auto SetVertical(bool vertical) -> void;
  auto SetVertical(Orientation orientation) -> void;
  //* method for getting orientation of the ship
  auto GetVertical() -> Orientation;
  //* method for getting segment state of the ship
  auto GetSegmentState(int index) -> State;

  auto Serialize() -> std::string;
  //* method for hitting the ship's segment
  auto Hit(size_t index) -> Result;

  auto HitWithDoubleDamage(size_t index) -> Result;

  auto CheckKilled() -> bool;

 private:
  int ship_length_;
  Orientation vertical_ = Orientation::UNSET;
  std::vector<State> segments_;
};

#endif