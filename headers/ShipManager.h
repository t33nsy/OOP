#ifndef _SHIP_MANAGER_H_
#define _SHIP_MANAGER_H_
#include "GameField.h"

class ShipManager {
 public:
  //* parameterized constructor with number of ships and lengths (vector)
  ShipManager(size_t ship_num, std::vector<int> ship_lens);

  //* destructor
  ~ShipManager();

  //* method for printing all ships lied in manager
  auto Print() -> void;

  //* method for getting current number of ships
  auto GetShipNum() -> size_t;

  // * method for initializing a game field
  auto InitGameField(GameField &game_field) -> void;

  auto CheckForEnd() -> bool;

 private:
  std::vector<Ship *> ships_;
  size_t ship_num_ = 0;
};

#endif