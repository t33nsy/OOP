#include "../headers/ShipManager.h"

ShipManager::ShipManager(size_t ship_num, std::vector<int> ship_lens)
    : ship_num_(ship_num) {
  ships_ = std::vector<Ship*>(ship_num);
  for (size_t i = 0; i < ship_num; ++i) {
    ships_[i] = new Ship(ship_lens[i]);
  }
}

ShipManager::ShipManager(size_t ship_num, std::vector<int> ship_lens,
                         std::vector<std::vector<State>> ship_states)
    : ship_num_(ship_num) {
  ships_ = std::vector<Ship*>(ship_num);
  for (size_t i = 0; i < ship_num; ++i) {
    ships_[i] = new Ship(ship_lens[i], ship_states[i]);
  }
}

ShipManager::ShipManager(std::string serialized) {
  ship_num_ = std::stoi(serialized.substr(0, serialized.find('-')));
  serialized = serialized.substr(serialized.find('-') + 1);
  ships_ = std::vector<Ship*>(ship_num_);
  for (size_t i = 0; i < ship_num_; ++i) {
    ships_[i] = new Ship(serialized.substr(0, serialized.find('-')));
    serialized = serialized.substr(serialized.find('-') + 1);
  }
}

auto ShipManager::Serialize() -> std::string {
  std::string result;
  result += std::to_string(ship_num_);
  result += "-";
  for (size_t i = 0; i < ship_num_; ++i) {
    result += ships_[i]->Serialize();
    result += "-";
  }
  return result;
}

ShipManager::~ShipManager() {
  for (size_t i = 0; i < ship_num_; ++i) {
    delete ships_[i];
  }
  ships_.clear();
};

auto ShipManager::InitGameField(GameField& game_field) -> void {
  int x, y, temp, all_place = 0, width = game_field.GetWidth(),
                  height = game_field.GetHeight();
  int max_x = width - 1, max_y = height - 1;
  bool flag;
  char r;
  std::cout << "Write r if you want to add random ships: ";
  std::cin >> r;
  if (r == 'r' || r == 'R') {
    for (size_t i = 0; i < ship_num_; ++i) {
      if (all_place == 2 * width * height) {
        for (size_t k = 0; k < ships_[i]->GetLength(); ++k) {
          for (size_t j = 0; j < 2; ++j) {
            ships_[i]->Hit(k);
          }
        }
        all_place = 0;
        continue;
      }
      flag = temp;
      x = rand() % width;
      y = rand() % height;
      flag = rand() % 2;
      try {
        game_field.AddShip(ships_[i], x, y, flag);
      } catch (...) {
        --i;
        ++all_place;
        continue;
      }
      all_place = 0;
    }
  } else {
    for (size_t i = 0; i < ship_num_; ++i) {
      std::cout << "Write coordinates and orientation for ship with len "
                << ships_[i]->GetLength()
                << " (write <0 <0 <0 to skip and kill current ship) : ";
      std::cin >> x >> y >> temp;
      if (x < 0 && y < 0 && temp < 0) {
        for (size_t k = 0; k < ships_[i]->GetLength(); ++k) {
          for (size_t l = 0; l < 2; ++l) {
            ships_[i]->Hit(k);
          }
        }
        continue;
      }
      if (temp > 1 || temp < 0) {
        std::cout << "Wrong orientation. Try again.\n";
        --i;
        continue;
      }
      flag = temp;
      try {
        game_field.AddShip(ships_[i], x, y, flag);
      } catch (OutOfFieldException& e) {
        std::cout << e.what();
        --i;
        continue;
      } catch (CollisionException& e) {
        std::cout << e.what();
        --i;
        continue;
      }
      system("cls");
      game_field.PrintField();
    }
  }
}

auto ShipManager::InitGameField(GameField& game_field, int x, int y,
                                Orientation orientation, size_t index) -> void {
  try {
    game_field.AddShip(ships_[index], x, y, orientation);
  } catch (OutOfFieldException& e) {
    throw e;
  } catch (CollisionException& e) {
    throw e;
  }
}

auto ShipManager::Print() -> void {
  std::cout << "Ships in manager: ";
  for (size_t i = 0; i < ship_num_; ++i) {
    std::cout << "(";
    for (size_t j = 0; j < ships_[i]->GetLength(); ++j) {
      if (ships_[i]->GetSegmentState(j) == State::INTACT)
        std::cout << "[]";
      else if (ships_[i]->GetSegmentState(j) == State::DAMAGED)
        std::cout << "::";
      else
        std::cout << "X";
    }
    std::cout << "), ";
  }
  std::cout << '\n';
}

auto ShipManager::GetShipNum() -> size_t { return ship_num_; }

auto ShipManager::GetShipSizes() -> std::vector<int> {
  std::vector<int> ans(ship_num_);
  for (int i = 0; i < ship_num_; ++i) {
    ans[i] = ships_[i]->GetLength();
  }
  return ans;
}

auto ShipManager::CheckForEnd() -> bool {
  for (size_t i = 0; i < ship_num_; ++i) {
    if (ships_[i]->CheckKilled() == false) return false;
  }
  return true;
}

auto ShipManager::RandomlyInitGameField(GameField& game_field)
    -> std::vector<GameField::ShipPlacement> {
  std::vector<GameField::ShipPlacement> placed;
  int x, y, temp, all_place = 0, width = game_field.GetWidth(),
                  height = game_field.GetHeight();
  int max_x = width - 1, max_y = height - 1;
  bool flag;
  for (size_t i = 0; i < ship_num_; ++i) {
    if (all_place == 2 * width * height) {
      KillShip(i);
      all_place = 0;
      continue;
    }
    flag = temp;
    x = rand() % width;
    y = rand() % height;
    flag = rand() % 2;
    try {
      game_field.AddShip(ships_[i], x, y, flag);
    } catch (...) {
      --i;
      ++all_place;
      continue;
    }
    all_place = 0;
    placed.push_back(
        GameField::ShipPlacement{static_cast<Orientation>(flag), (int)i, x, y});
  }
  return placed;
}

auto ShipManager::KillShip(size_t index) -> void {
  for (size_t k = 0; k < ships_[index]->GetLength(); ++k) {
    for (size_t j = 0; j < 2; ++j) {
      ships_[index]->Hit(k);
    }
  }
}

auto ShipManager::AddShipToGameField(GameField& game_field, int x, int y,
                                     Orientation orientation,
                                     size_t size) -> void {
  Ship* ship = new Ship(size);
  try {
    game_field.AddShip(ship, x, y, orientation);
  } catch (CollisionException& e) {
    throw e;
  } catch (OutOfFieldException& e) {
    throw e;
  }
  ships_.push_back(ship);
  ++ship_num_;
}