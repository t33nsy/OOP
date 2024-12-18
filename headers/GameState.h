#ifndef _t33nsy_GAMESTATE
#define _t33nsy_GAMESTATE

#include <fstream>

#include "GameField.h"
#include "ShipManager.h"
#include "SkillManager.h"

class GameState {
 public:
  enum PlayerType { Player, Computer };

  friend auto operator<<(std::ostream& out,
                         const GameState& state) -> std::ostream&;

  friend auto operator>>(std::istream& in, GameState& state) -> std::istream&;

  auto SetSerializedManager(std::string serialized_manager,
                            PlayerType who) -> void;

  auto SetSerializedGameField(std::string serialized_game_field,
                              PlayerType who) -> void;

  auto SetSerializedShipPlacement(
      std::vector<GameField::ShipPlacement> ship_placement,
      PlayerType who) -> void;
      
  auto SetSerializedSkillManager(std::string serialized_skill_manager) -> void;

  auto GetSerializedGameField(PlayerType who) const -> std::string;

  auto GetSerializedManager(PlayerType who) const -> std::string;

  auto GetShipPlacement(PlayerType who) const
      -> std::vector<GameField::ShipPlacement>;

  auto GetSerializedSkillManager() const -> std::string;

  auto crypt(std::string str) const -> std::string;

 private:
  std::string serialized_ship_manager_, serialized_opponent_ship_manager_;
  std::string serialized_ship_placement_, serialized_opponent_ship_placement_;
  std::string serialized_game_field_, serialized_opponent_game_field_;
  std::string serialized_skill_manager_;
  std::string game_key_ = "GAME";
};

#endif /* _t33nsy_GAMESTATE */
