#ifndef _t33nsy_TRACKER
#define _t33nsy_TRACKER

#include "Game.h"
#include "GameRenderer.h"

class Tracker {
 public:
  Tracker() = default;

  auto TriggerWin() -> void;

  auto TriggerLose() -> void;

  auto TriggerBuilding() -> void;

  auto TriggerGameStart() -> void;

  auto TriggerRoundStart() -> void;

  auto TriggerXIncremented() -> void;

  auto TriggerYIncremented() -> void;

  auto TriggerXDecremented() -> void;

  auto TriggerYDecremented() -> void;

  auto TriggerOrientation() -> void;

  auto TriggerSizeIncremented() -> void;

  auto TriggerSizeDecremented() -> void;

  auto TriggerTurnDone(Result result) -> void;

  auto TriggerOpponentTurn(Result result, int x, int y) -> void;

  auto TriggerSaveLoaded(int x, int y, std::vector<std::vector<char>> field,
                         std::vector<std::vector<char>> opponent_field) -> void;

  auto TriggerShipPlaced() -> void;

  auto TriggerInfo(std::string info) -> void;

  auto GetChosenSize() -> int;

  auto GetChosenOrientation() -> Orientation;

  auto GetChosenX() -> int;

  auto GetChosenY() -> int;

  auto GetFieldWidth() -> int;

  auto GetFieldHeight() -> int;

  auto IsFieldBuilt() -> bool;

  auto IsGameStarted() -> bool;

  auto IsRoundStarted() -> bool;

  auto SetFieldSizes() -> void;

 private:
  bool field_built_ = false, game_started_ = false, round_started = false,
       info_shown_ = false;
  int chosen_x_ = 0, chosen_y_ = 0, chosen_size_ = 1, field_x_ = INT_MAX,
      field_y_ = INT_MAX;
  Orientation chosen_orientation_ = Orientation::HORIZONTAL;
  Result turn_result_;
  GameRenderer<TerminalField> renderer_;

  auto CheckInfo() -> void;
};

#endif /* _t33nsy_TRACKER */
