#include "../headers/GameState.h"

auto operator<<(std::ostream& out, const GameState& state) -> std::ostream& {
  out << state.crypt(state.serialized_game_field_) << "\n"
      << state.crypt(state.serialized_ship_manager_) << "\n"
      << state.crypt(state.serialized_opponent_game_field_) << "\n"
      << state.crypt(state.serialized_opponent_ship_manager_) << "\n"
      << state.crypt(state.serialized_ship_placement_) << "\n"
      << state.crypt(state.serialized_opponent_ship_placement_) << "\n"
      << state.crypt(state.serialized_skill_manager_) << "\n";
  return out;
}

auto operator>>(std::istream& in, GameState& state) -> std::istream& {
  std::string temp;
  getline(in, temp);
  state.SetSerializedGameField(state.crypt(temp),
                               GameState::PlayerType::Player);
  getline(in, temp);
  state.SetSerializedManager(state.crypt(temp), GameState::PlayerType::Player);
  getline(in, temp);
  state.SetSerializedGameField(state.crypt(temp),
                               GameState::PlayerType::Computer);
  getline(in, temp);
  state.SetSerializedManager(state.crypt(temp),
                             GameState::PlayerType::Computer);
  getline(in, temp);
  state.serialized_ship_placement_ = state.crypt(temp);
  getline(in, temp);
  state.serialized_opponent_ship_placement_ = state.crypt(temp);
  getline(in, temp);
  state.serialized_skill_manager_ = state.crypt(temp);
  return in;
}

auto GameState::SetSerializedManager(std::string serialized_manager,
                                     PlayerType who) -> void {
  if (who == PlayerType::Player)
    serialized_ship_manager_ = serialized_manager;
  else
    serialized_opponent_ship_manager_ = serialized_manager;
}

auto GameState::SetSerializedGameField(std::string serialized_game_field,
                                       PlayerType who) -> void {
  if (who == PlayerType::Player)
    serialized_game_field_ = serialized_game_field;
  else
    serialized_opponent_game_field_ = serialized_game_field;
}

auto GameState::SetSerializedShipPlacement(
    std::vector<GameField::ShipPlacement> ship_placement,
    PlayerType who) -> void {
  if (who == PlayerType::Player) {
    serialized_ship_placement_ = "";
    for (auto i : ship_placement) {
      serialized_ship_placement_ +=
          std::to_string(i.orient) + "," + std::to_string(i.index) + "," +
          std::to_string(i.x) + "," + std::to_string(i.y);
      serialized_ship_placement_ += "-";
    }
  } else {
    serialized_opponent_ship_placement_ = "";
    for (auto i : ship_placement) {
      serialized_opponent_ship_placement_ +=
          std::to_string(i.orient) + "," + std::to_string(i.index) + "," +
          std::to_string(i.x) + "," + std::to_string(i.y);
      serialized_opponent_ship_placement_ += "-";
    }
  }
}

auto GameState::SetSerializedSkillManager(std::string serialized_skill_manager)
    -> void {
  serialized_skill_manager_ = serialized_skill_manager;
}

auto GameState::GetSerializedGameField(PlayerType who) const -> std::string {
  if (who == PlayerType::Player) {
    return serialized_game_field_;
  }
  return serialized_opponent_game_field_;
}

auto GameState::GetSerializedManager(PlayerType who) const -> std::string {
  if (who == PlayerType::Player) {
    return serialized_ship_manager_;
  }
  return serialized_opponent_ship_manager_;
}

auto GameState::GetShipPlacement(PlayerType who) const
    -> std::vector<GameField::ShipPlacement> {
  std::vector<GameField::ShipPlacement> ship_placement;
  std::string temp;
  if (who == PlayerType::Player) {
    temp = serialized_ship_placement_;
  } else {
    temp = serialized_opponent_ship_placement_;
  }
  while (temp.size() > 0) {
    std::string tmp = temp.substr(0, temp.find("-"));
    Orientation orient =
        static_cast<Orientation>(std::stoi(tmp.substr(0, tmp.find(","))));
    tmp = tmp.substr(tmp.find(",") + 1);
    int index = std::stoi(tmp.substr(0, tmp.find(",")));
    tmp = tmp.substr(tmp.find(",") + 1);
    int ship_x = std::stoi(tmp.substr(0, tmp.find(",")));
    tmp = tmp.substr(tmp.find(",") + 1);
    int ship_y = std::stoi(tmp.substr(0, tmp.find(",")));
    ship_placement.push_back(
        GameField::ShipPlacement{orient, index, ship_x, ship_y});
    temp = temp.substr(temp.find("-") + 1, temp.size());
  }
  return ship_placement;
}

auto GameState::GetSerializedSkillManager() const -> std::string {
  return serialized_skill_manager_;
}

auto GameState::crypt(std::string str) const -> std::string {
  std::string str_ = str;
  for (int i = 0; i < str.size(); ++i) {
    str_[i] = str[i] ^ game_key_[i % game_key_.size()];
  }
  return str_;
}