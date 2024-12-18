#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "TerminalInputHandler.h"
#include "Tracker.h"
template <typename InputType>
class GameController {
 public:
  explicit GameController(Game &game) : game_(game) {}

  auto Start() -> void {
    while (true) {
      CommandType command = input.GetCommand();
      // std::cout << command << std::endl;
      switch (command) {
        case START_GAME: {
          if (!tracker_.IsGameStarted()) {
            game_.StartNewGame(tracker_.GetChosenX() + 1,
                               tracker_.GetChosenY() + 1);
            tracker_.TriggerGameStart();
            tracker_.TriggerBuilding();
            tracker_.SetFieldSizes();
          }
          break;
        }
        case SAVE_GAME: {
          if (!tracker_.IsRoundStarted()) break;
          try {
            game_.SaveGame(save_file_name_);
          } catch (...) {
            tracker_.TriggerInfo("Saving went wrong. Something with file?");
            continue;
          }
          break;
        }
        case LOAD_GAME: {
          try {
            game_.LoadGame(save_file_name_);
          } catch (const char *e) {
            tracker_.TriggerInfo(e);
            continue;
          }
          auto sizes = game_.getFieldSizes();
          std::vector<std::vector<char>> f = game_.getFieldInChar(),
                                         o = game_.getOpponentFieldInChar();
          tracker_.TriggerSaveLoaded(sizes.first - 1, sizes.second - 1, f, o);
          break;
        }
        case START_ROUND: {
          if (tracker_.IsRoundStarted() || !tracker_.IsGameStarted()) break;
          game_.StartNewRound();
          tracker_.TriggerRoundStart();
          break;
        }
        case ADD_SHIP: {
          if (!tracker_.IsFieldBuilt() || tracker_.IsRoundStarted()) break;
          try {
            game_.AddShip(tracker_.GetChosenX(), tracker_.GetChosenY(),
                          tracker_.GetChosenSize(),
                          tracker_.GetChosenOrientation());
          } catch (OutOfFieldException &e) {
            tracker_.TriggerInfo(e.what());
            break;
          } catch (CollisionException &e) {
            tracker_.TriggerInfo(e.what());
            break;
          }
          tracker_.TriggerShipPlaced();
          break;
        }
        case X_DECREASE: {
          tracker_.TriggerXDecremented();
          break;
        }
        case X_INCREASE: {
          tracker_.TriggerXIncremented();
          break;
        }
        case Y_DECREASE: {
          tracker_.TriggerYDecremented();
          break;
        }
        case Y_INCREASE: {
          tracker_.TriggerYIncremented();
          break;
        }
        case CHANGE_ORIENTATION: {
          tracker_.TriggerOrientation();
          break;
        }
        case ATTACK: {
          if (!tracker_.IsGameStarted() || !tracker_.IsRoundStarted()) break;
          Result result;
          try {
            result = game_.DoTurn(Game::TurnType::ATTACK, tracker_.GetChosenX(),
                                  tracker_.GetChosenY());
          } catch (OutOfFieldException &e) {
            tracker_.TriggerInfo(e.what());
            break;
          } catch (ShipKilled &e) {
            tracker_.TriggerTurnDone(Result::DESTROYED);
            tracker_.TriggerInfo(e.what());
            break;
          }
          if (result == Result::WIN) {
            game_.StartNewRound();
            tracker_.TriggerWin();
            continue;
          }
          if (result == Result::FULL_DESTROYED) {
            tracker_.TriggerInfo("You destroyed and got skill!");
          }
          tracker_.TriggerTurnDone(result);
          int x, y;
          result = game_.ComputerTurn(x, y);
          if (result == Result::LOSE) {
            tracker_.TriggerLose();
            continue;
          }
          tracker_.TriggerOpponentTurn(result, x, y);
          break;
        }
        case SKILL: {
          if (!tracker_.IsRoundStarted() || !tracker_.IsGameStarted()) break;
          Result result;
          try {
            result = game_.DoTurn(Game::TurnType::SKILL, tracker_.GetChosenX(),
                                  tracker_.GetChosenY());
          } catch (OutOfFieldException &e) {
            tracker_.TriggerInfo(e.what());
            break;
          } catch (NoSkillsException &e) {
            tracker_.TriggerInfo(e.what());
            break;
          } catch (ShipKilled &e) {
            tracker_.TriggerInfo(e.what());
            break;
          }
          switch (result) {
            case Result::SHIP_FOUND: {
              tracker_.TriggerInfo("Ship found in square 2x2");
              break;
            }
            case Result::SHIP_NOT_FOUND: {
              tracker_.TriggerInfo("No ship found in square 2x2");
              break;
            }
            case Result::DESTROYED: {
              tracker_.TriggerTurnDone(result);
              break;
            }
          }
          break;
        }
        case QUIT: {
          return;
        }
        case SIZE_INCREASE: {
          if (tracker_.IsRoundStarted()) break;
          tracker_.TriggerSizeIncremented();
          break;
        }
        case SIZE_DECREASE: {
          if (tracker_.IsRoundStarted()) break;
          tracker_.TriggerSizeDecremented();
          break;
        }

        default: {
          break;
        }
      }
    }
  }

 private:
  Game &game_;  // reference to the game
  Tracker tracker_;
  std::string save_file_name_ = "../test.txt";
  InputType input;
};

#endif  // GAMERCONTROLLER_H