#include "../headers/Game.h"

Game::~Game() {
  if (field_ != nullptr) delete field_;
  if (ship_manager_ != nullptr) ship_manager_;
  if (skill_manager_ != nullptr) skill_manager_;
  if (opponent_field_ != nullptr) delete opponent_field_;
  if (opponent_ship_manager_ != nullptr) delete opponent_ship_manager_;
}

auto Game::StartNewGame(int fieldx, int fieldy, int ship_num,
                        std::vector<int> ship_sizes) -> void {
  field_ = new GameField(fieldx, fieldy);
  ship_manager_ = new ShipManager(ship_num, ship_sizes);
  skill_manager_ = new SkillManager();
  if (ship_placements_.size() > 0) ship_placements_.clear();
}

auto Game::StartNewGame(int fieldx, int fieldy) -> void {
  field_ = new GameField(fieldx, fieldy);
  ship_manager_ = new ShipManager();
  skill_manager_ = new SkillManager();
  if (ship_placements_.size() > 0) ship_placements_.clear();
}

auto Game::AddShip(int x, int y, int size, Orientation orientation) -> void {
  try {
    ship_manager_->AddShipToGameField(*field_, x, y, orientation, size);
  } catch (OutOfFieldException &e) {
    throw e;
  } catch (CollisionException &e) {
    throw e;
  }
  ship_placements_.push_back(GameField::ShipPlacement{
      orientation, (int)ship_placements_.size(), x, y});
}

auto Game::AddShipOnField(size_t index, int x, int y,
                          Orientation orientation) -> void {
  try {
    ship_manager_->InitGameField(*field_, x, y, orientation, index);
  } catch (OutOfFieldException &e) {
    throw e;
  } catch (CollisionException &e) {
    throw e;
  }
  ship_placements_.push_back(
      GameField::ShipPlacement{orientation, (int)index, x, y});
}

auto Game::RandomlyPlaceShips() -> void {
  ship_placements_ = ship_manager_->RandomlyInitGameField(*field_);
}

auto Game::StartNewRound() -> void {
  enemy_ = new ComputerEnemy();
  opponent_field_ = new GameField(field_->GetWidth(), field_->GetHeight());
  opponent_ship_manager_ = new ShipManager(ship_manager_->GetShipNum(),
                                           ship_manager_->GetShipSizes());
  opponent_ship_placements_ =
      opponent_ship_manager_->RandomlyInitGameField(*opponent_field_);
  opponent_field_->DoLikeItOpponents();
  Serialize();
}

auto Game::checkForWin() -> bool {
  return opponent_ship_manager_->CheckForEnd();
}

auto Game::checkForLose() -> bool { return ship_manager_->CheckForEnd(); }

auto Game::SaveGame(std::string filename) -> void {
  Serialize();
  FileHandler fh(filename, FileType::WRITE);
  // std::ofstream out(filename, std::ios_base::binary);  // RAII output stream
  try {
    fh.WriteState(state_);
  } catch (const char *e) {
    throw e;
  }
  // if (out.is_open())
  //   out << state_;
  // else
  //   throw "Failed to save game, something with file";
}

auto Game::LoadGame(std::string filename) -> void {
  // std::ifstream in(filename, std::ios_base::binary);  // RAII input stream
  // if (!in.is_open()) throw "Failed to load game, something with file";
  // in >> state_;
  FileHandler fh(filename, FileType::READ);
  try {
    fh.ReadState(state_);
  } catch (const char *e) {
    throw e;
  }
  ShipManager *temp_ship_manager, *temp_opp_manager;
  GameField *temp_game_field, *temp_opp_field;
  SkillManager *temp_skill_manager;
  try {
    temp_ship_manager = new ShipManager(
        state_.GetSerializedManager(GameState::PlayerType::Player));
    temp_game_field = new GameField(
        state_.GetSerializedGameField(GameState::PlayerType::Player));
    ship_placements_ = state_.GetShipPlacement(GameState::PlayerType::Player);
    temp_skill_manager = new SkillManager(state_.GetSerializedSkillManager());
    temp_opp_manager = new ShipManager(
        state_.GetSerializedManager(GameState::PlayerType::Computer));
    temp_opp_field = new GameField(
        state_.GetSerializedGameField(GameState::PlayerType::Computer));
    opponent_ship_placements_ =
        state_.GetShipPlacement(GameState::PlayerType::Computer);
    enemy_ = new ComputerEnemy();
  } catch (...) {
    throw "Failed to load game";
  }
  ship_manager_ = temp_ship_manager;
  opponent_ship_manager_ = temp_opp_manager;
  field_ = temp_game_field;
  opponent_field_ = temp_opp_field;
  skill_manager_ = temp_skill_manager;
  for (auto i : ship_placements_) {
    try {
      ship_manager_->InitGameField(*field_, i.x, i.y, i.orient, i.index);
    } catch (...) {
      throw "Failed to load game";
    }
  }
  for (auto i : opponent_ship_placements_) {
    try {
      opponent_ship_manager_->InitGameField(*opponent_field_, i.x, i.y,
                                            i.orient, i.index);
    } catch (...) {
      throw "Failed to load game";
    }
  }
}

auto Game::DoTurn(TurnType type, int x, int y) -> Result {
  Result result;
  try {
    if (type == TurnType::ATTACK) {
      result = opponent_field_->Attack(x, y, 1);
    } else if (type == TurnType::SKILL) {
      result = skill_manager_->UseOwnedSkill(x, y, *opponent_field_);
    }
  } catch (OutOfFieldException &e) {
    throw e;
  } catch (NoSkillsException &e) {
    throw e;
  } catch (ShipKilled &e) {
    throw e;
  }
  if (result == Result::FULL_DESTROYED) {
    skill_manager_->GetRandomSkill();
  }
  if (checkForWin()) {
    return Result::WIN;
  }
  return result;
}

auto Game::ComputerTurn(int &x, int &y) -> Result {
  Result result = enemy_->DoAttack(*field_, x, y);
  Serialize();
  if (checkForLose()) {
    return Result::LOSE;
  }
  return result;
}

auto Game::Serialize() -> void {
  state_.SetSerializedGameField(field_->Serialize(),
                                GameState::PlayerType::Player);
  state_.SetSerializedManager(ship_manager_->Serialize(),
                              GameState::PlayerType::Player);
  state_.SetSerializedShipPlacement(ship_placements_,
                                    GameState::PlayerType::Player);
  state_.SetSerializedGameField(opponent_field_->Serialize(),
                                GameState::PlayerType::Computer);
  state_.SetSerializedManager(opponent_ship_manager_->Serialize(),
                              GameState::PlayerType::Computer);
  state_.SetSerializedShipPlacement(opponent_ship_placements_,
                                    GameState::PlayerType::Computer);
  state_.SetSerializedSkillManager(skill_manager_->Serialize());
}

auto Game::getFieldSizes() -> std::pair<int, int> {
  return std::make_pair(field_->GetWidth(), field_->GetHeight());
}

auto Game::getFieldInChar() -> std::vector<std::vector<char>> {
  return field_->ToCharArray(true);
}

auto Game::getOpponentFieldInChar() -> std::vector<std::vector<char>> {
  return opponent_field_->ToCharArray(false);
}