#ifndef _t33nsy_GAMERENDERER
#define _t33nsy_GAMERENDERER

#include "TerminalField.h"
template <typename RenderType>
class GameRenderer {
 public:
  GameRenderer() = default;

  GameRenderer(int x, int y) : x_(x), y_(y) { render_ = RenderType(x, y); }

  // constructor for loading saved game
  GameRenderer(int x, int y, std::vector<std::vector<char>> field,
               std::vector<std::vector<char>> opponent_field)
      : x_(x), y_(y) {
    render_ = RenderType(x, y, field, opponent_field);
  }

  auto PrintOnlyPlayer() -> void { render_.PrintOnlyPlayer(); }

  auto PrintOnlyComp() -> void { render_.PrintOnlyComp(); }

  auto Print() -> void { render_.Print(); }

  auto PrintPlayerTurn(int x, int y, Result result) -> void {
    render_.ChangeState(x, y, result);
  }

  auto PrintCompTurn(int x, int y, Result result) -> void {
    render_.ChangeCompState(x, y, result);
  }

  auto PrintShip(int x, int y, int size, Orientation orient) -> void {
    render_.PrintShip(x, y, size, orient);
  };

  auto DeleteShip(int x, int y, int size, Orientation orient) -> void {
    render_.DeleteShip(x, y, size, orient);
  }

  auto PrintInfo(std::string info) -> void { render_.PrintInfo(info); }

  auto DeleteInfo() -> void { render_.DeleteInfo(); }

  auto FixShip(int x, int y, int size, Orientation orient) -> void {
    render_.FixShip(x, y, size, orient);
  }

  auto DisplayPlayerPosition(int x, int y) -> void {
    render_.DisplayPlayerPosition(x, y);
  }

  auto ResetOpponentField() -> void { render_.ResetOpponentField(); }

  auto Reset() -> void { render_.Reset(); }

 private:
  int x_, y_;
  RenderType render_;
};

#endif /* _t33nsy_GAMERENDERER */
