#include "headers/GameController.h"

int main() {
  srand(time(nullptr));
  Game game;
  GameController<TerminalHandler> game_control(game);
  game_control.Start();
  return 0;
}