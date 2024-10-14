#include "../headers/Ship.h"

Ship::Ship(int len) {
  SetLength(len);
  segments_ = std::vector<State>(len, State::INTACT);
}

Ship::Ship(int len, bool vertical) {
  SetLength(len);
  SetVertical(vertical);
  segments_ = std::vector<State>(len, State::INTACT);
}

Ship::~Ship() { segments_.clear(); };

auto Ship::SetLength(int length) -> void { ship_length_ = length; }

auto Ship::GetLength() -> int { return ship_length_; }

auto Ship::SetVertical(bool vertical) -> void {
  if (vertical == true) {
    vertical_ = Orientation::VERTICAL;
  } else
    vertical_ = Orientation::HORIZONTAL;
}

auto Ship::GetVertical() -> Orientation { return vertical_; }

auto Ship::GetSegmentState(int index) -> Ship::State {
  return segments_[index];
}

auto Ship::Hit(size_t index) -> bool {
  if (segments_[index] == INTACT) {
    segments_[index] = DAMAGED;
  } else if (segments_[index] == DAMAGED) {
    segments_[index] = KILLED;
  }
  for (int i = 0; i < ship_length_; ++i) {
    if (segments_[i] != KILLED) {
      return false;
    }
  }
  return true;
}