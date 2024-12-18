#include "../headers/Ship.h"

Ship::Ship(int len) {
  SetLength(len);
  segments_ = std::vector<State>(len, State::INTACT);
}

Ship::Ship(std::string serialized) {
  SetLength(std::stoi(serialized.substr(0, 1)));
  SetVertical(std::stoi(serialized.substr(1, 1)));
  for (int i = 0; i < ship_length_; i++) {
    segments_.push_back(State(std::stoi(serialized.substr(2 + i, 1))));
  }
}

Ship::Ship(int len, std::vector<State> segments) {
  SetLength(len);
  segments_ = segments;
}

Ship::Ship(int len, bool vertical) {
  SetLength(len);
  SetVertical(vertical);
  segments_ = std::vector<State>(len, State::INTACT);
}

Ship::~Ship() { segments_.clear(); };

auto Ship::Serialize() -> std::string {
  std::string serialized = "";
  serialized += std::to_string(ship_length_);
  serialized += std::to_string(vertical_);
  for (int i = 0; i < ship_length_; ++i) {
    serialized += std::to_string(segments_[i]);
  }
  return serialized;
}

auto Ship::SetLength(int length) -> void { ship_length_ = length; }

auto Ship::GetLength() -> int { return ship_length_; }

auto Ship::SetVertical(bool vertical) -> void {
  if (vertical == true) {
    vertical_ = Orientation::VERTICAL;
  } else
    vertical_ = Orientation::HORIZONTAL;
}

auto Ship::SetVertical(Orientation orientation) -> void {
  vertical_ = orientation;
}

auto Ship::GetVertical() -> Orientation { return vertical_; }

auto Ship::GetSegmentState(int index) -> State { return segments_[index]; }

auto Ship::Hit(size_t index) -> Result {
  switch (segments_[index]) {
    case INTACT:
      segments_[index] = State::DAMAGED;
      return Result::HALF_HP;
      break;
    case DAMAGED:
      segments_[index] = State::KILLED;
      break;
    default:
      throw ShipKilled();
  }
  if (CheckKilled()) return Result::FULL_DESTROYED;
  return Result::DESTROYED;
}

auto Ship::HitWithDoubleDamage(size_t index) -> Result {
  switch (segments_[index]) {
    case INTACT:
    case DAMAGED:
      segments_[index] = State::KILLED;
      break;
    default:
      throw ShipKilled();
  }
  if (CheckKilled()) return Result::FULL_DESTROYED;
  return Result::DESTROYED;
}

auto Ship::CheckKilled() -> bool {
  return std::all_of(segments_.begin(), segments_.end(),
                     [](State s) { return s == State::KILLED; });
}
