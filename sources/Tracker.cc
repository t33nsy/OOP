#include "../headers/Tracker.h"

auto Tracker::TriggerBuilding() -> void {
  renderer_ = GameRenderer<TerminalField>(chosen_x_, chosen_y_);
  field_built_ = true;
  renderer_.PrintInfo("Field was built");
}

auto Tracker::TriggerGameStart() -> void { game_started_ = true; }

auto Tracker::TriggerRoundStart() -> void {
  round_started = true;
  renderer_.Print();
}

auto Tracker::IsFieldBuilt() -> bool { return field_built_; }

auto Tracker::IsGameStarted() -> bool { return game_started_; }

auto Tracker::IsRoundStarted() -> bool { return round_started; }

auto Tracker::SetFieldSizes() -> void {
  field_x_ = chosen_x_;
  field_y_ = chosen_y_;
}

auto Tracker::GetFieldWidth() -> int { return field_x_; }

auto Tracker::GetFieldHeight() -> int { return field_y_; }

auto Tracker::TriggerXIncremented() -> void {
  CheckInfo();
  if (!field_built_) {
    ++chosen_x_;
    renderer_ = GameRenderer<TerminalField>(chosen_x_, chosen_y_);
    renderer_.PrintOnlyPlayer();
  } else if (!round_started) {
    renderer_.DeleteShip(chosen_x_, chosen_y_, chosen_size_,
                         chosen_orientation_);
    chosen_x_ == field_x_ ? chosen_x_ : ++chosen_x_;
    renderer_.PrintOnlyPlayer();
    renderer_.PrintShip(chosen_x_, chosen_y_, chosen_size_,
                        chosen_orientation_);
  } else {
    chosen_x_ == field_x_ ? chosen_x_ : ++chosen_x_;
    renderer_.PrintOnlyComp();
    renderer_.DisplayPlayerPosition(chosen_x_, chosen_y_);
  }
}

auto Tracker::TriggerYIncremented() -> void {
  CheckInfo();
  if (!field_built_) {
    ++chosen_y_;
    renderer_ = GameRenderer<TerminalField>(chosen_x_, chosen_y_);
    renderer_.PrintOnlyPlayer();
  } else if (!round_started) {
    renderer_.DeleteShip(chosen_x_, chosen_y_, chosen_size_,
                         chosen_orientation_);
    chosen_y_ == field_y_ ? chosen_y_ : ++chosen_y_;
    renderer_.PrintOnlyPlayer();
    renderer_.PrintShip(chosen_x_, chosen_y_, chosen_size_,
                        chosen_orientation_);
  } else {
    chosen_y_ == field_y_ ? chosen_y_ : ++chosen_y_;
    renderer_.PrintOnlyComp();
    renderer_.DisplayPlayerPosition(chosen_x_, chosen_y_);
  }
}

auto Tracker::TriggerXDecremented() -> void {
  CheckInfo();
  if (!field_built_) {
    chosen_x_ == 0 ? chosen_x_ : --chosen_x_;
    renderer_ = GameRenderer<TerminalField>(chosen_x_, chosen_y_);
    renderer_.PrintOnlyPlayer();
  } else if (!round_started) {
    renderer_.DeleteShip(chosen_x_, chosen_y_, chosen_size_,
                         chosen_orientation_);
    chosen_x_ == 0 ? chosen_x_ : --chosen_x_;
    renderer_.PrintOnlyPlayer();
    renderer_.PrintShip(chosen_x_, chosen_y_, chosen_size_,
                        chosen_orientation_);
  } else {
    chosen_x_ == 0 ? chosen_x_ : --chosen_x_;
    renderer_.PrintOnlyComp();
    renderer_.DisplayPlayerPosition(chosen_x_, chosen_y_);
  }
}

auto Tracker::TriggerYDecremented() -> void {
  CheckInfo();
  if (!field_built_) {
    chosen_y_ == 0 ? chosen_y_ : --chosen_y_;
    renderer_ = GameRenderer<TerminalField>(chosen_x_, chosen_y_);
    renderer_.PrintOnlyPlayer();
  } else if (!round_started) {
    renderer_.DeleteShip(chosen_x_, chosen_y_, chosen_size_,
                         chosen_orientation_);
    chosen_y_ == 0 ? chosen_y_ : --chosen_y_;
    renderer_.PrintOnlyPlayer();
    renderer_.PrintShip(chosen_x_, chosen_y_, chosen_size_,
                        chosen_orientation_);
  } else {
    chosen_y_ == 0 ? chosen_y_ : --chosen_y_;
    renderer_.PrintOnlyComp();
    renderer_.DisplayPlayerPosition(chosen_x_, chosen_y_);
  }
}

auto Tracker::TriggerOrientation() -> void {
  CheckInfo();
  renderer_.DeleteShip(chosen_x_, chosen_y_, chosen_size_, chosen_orientation_);
  chosen_orientation_ == Orientation::HORIZONTAL
      ? chosen_orientation_ = Orientation::VERTICAL
      : chosen_orientation_ = Orientation::HORIZONTAL;
  renderer_.PrintOnlyPlayer();
  renderer_.PrintShip(chosen_x_, chosen_y_, chosen_size_, chosen_orientation_);
}

auto Tracker::TriggerSizeIncremented() -> void {
  CheckInfo();
  if (!field_built_) return;
  if (round_started) return;
  renderer_.DeleteShip(chosen_x_, chosen_y_, chosen_size_, chosen_orientation_);
  chosen_size_ < 4 ? ++chosen_size_ : chosen_size_;
  renderer_.PrintOnlyPlayer();
  renderer_.PrintShip(chosen_x_, chosen_y_, chosen_size_, chosen_orientation_);
}

auto Tracker::TriggerSizeDecremented() -> void {
  CheckInfo();
  renderer_.DeleteShip(chosen_x_, chosen_y_, chosen_size_, chosen_orientation_);
  chosen_size_ > 1 ? --chosen_size_ : chosen_size_;
  renderer_.PrintShip(chosen_x_, chosen_y_, chosen_size_, chosen_orientation_);
}

auto Tracker::TriggerTurnDone(Result result) -> void {
  turn_result_ = result;
  renderer_.PrintPlayerTurn(chosen_x_, chosen_y_, turn_result_);
}

auto Tracker::TriggerOpponentTurn(Result result, int x, int y) -> void {
  turn_result_ = result;
  renderer_.PrintCompTurn(x, y, turn_result_);
}

auto Tracker::TriggerSaveLoaded(
    int x, int y, std::vector<std::vector<char>> field,
    std::vector<std::vector<char>> opponent_field) -> void {
  CheckInfo();
  renderer_ = GameRenderer<TerminalField>(x, y, field, opponent_field);
  chosen_size_ = 0;
  chosen_orientation_ = Orientation::VERTICAL;
  field_built_ = true;
  field_x_ = x;
  field_y_ = y;
  TriggerGameStart();
  TriggerRoundStart();
}

auto Tracker::TriggerShipPlaced() -> void {
  CheckInfo();
  renderer_.FixShip(chosen_x_, chosen_y_, chosen_size_, chosen_orientation_);
  renderer_.PrintOnlyPlayer();
}

auto Tracker::TriggerInfo(std::string info) -> void {
  CheckInfo();
  renderer_.PrintInfo(info);
  info_shown_ = true;
}

auto Tracker::GetChosenSize() -> int { return chosen_size_; }

auto Tracker::GetChosenOrientation() -> Orientation {
  return chosen_orientation_;
}

auto Tracker::GetChosenX() -> int { return chosen_x_; }

auto Tracker::GetChosenY() -> int { return chosen_y_; }

auto Tracker::TriggerWin() -> void {
  TriggerInfo("You WON! NEXT ROUND!");
  renderer_.ResetOpponentField();
}

auto Tracker::TriggerLose() -> void {
  TriggerInfo("You LOST! GAME OVER");
  renderer_.Reset();
  field_built_ = false;
  game_started_ = false;
  round_started = false;
}
auto Tracker::CheckInfo() -> void {
  if (info_shown_) {
    renderer_.DeleteInfo();
    info_shown_ = false;
  }
}