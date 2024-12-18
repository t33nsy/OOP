#ifndef _SHIP_MANAGER_H_
#define _SHIP_MANAGER_H_
#include "GameField.h"

class ShipManager {
 public:
  ShipManager() = default;

  //* parameterized constructor with number of ships and lengths (vector)
  ShipManager(size_t ship_num, std::vector<int> ship_lens);

  ShipManager(size_t ship_num, std::vector<int> ship_lens,
              std::vector<std::vector<State>> ship_states);

  ShipManager(std::string serialized);

  //* destructor
  ~ShipManager();

  //* method for printing all ships lied in manager
  auto Print() -> void;

  auto Serialize() -> std::string;

  //* method for getting current number of ships
  auto GetShipNum() -> size_t;

  auto GetShipSizes() -> std::vector<int>;

  // * method for initializing a game field
  auto InitGameField(GameField &game_field) -> void;

  auto RandomlyInitGameField(GameField &game_field)
      -> std::vector<GameField::ShipPlacement>;

  // * method for initializing a game field without using standart streams
  auto InitGameField(GameField &game_field, int x, int y,
                     Orientation orientation, size_t index) -> void;

  auto AddShipToGameField(GameField &game_field, int x, int y,
                          Orientation orientation, size_t size) -> void;

  auto CheckForEnd() -> bool;

  auto KillShip(size_t index) -> void;

 private:
  std::vector<Ship *> ships_;
  size_t ship_num_ = 0;
};

#endif