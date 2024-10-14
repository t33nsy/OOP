#ifndef _SHIP_H_
#define _SHIP_H_
#include <stdint.h>

#include <iostream>
#include <vector>
#include <windows.h>

class Ship {
 public:
  //* enum class with given three states of the ship segment
  enum State { KILLED, DAMAGED, INTACT };

  enum Orientation { HORIZONTAL, VERTICAL };

  //* parameterized constructor which gets size of the ship
  explicit Ship(int len);

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
  //* method for getting orientation of the ship
  auto GetVertical() -> Orientation;
  //* method for getting segment state of the ship
  auto GetSegmentState(int index) -> State;

  //* method for hitting the ship's segment
  auto Hit(size_t index) -> bool;

 private:
  int ship_length_;
  Orientation vertical_;
  std::vector<State> segments_;
};

#endif