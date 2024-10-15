#include "../headers/ShipManager.h"

ShipManager::ShipManager(size_t ship_num, std::vector<int> ship_lens)
    : ship_num_(ship_num) {
  ships_ = std::vector<Ship*>(ship_num);
  for (size_t i = 0; i < ship_num; ++i) {
    try {
      ships_[i] = new Ship(ship_lens[i]);
    } catch (const char* error_message) {
      std::cout << error_message << '\n';
    }
  }
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
    srand(time(0));
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

auto ShipManager::Print() -> void {
  std::cout << "Ships in manager: ";
  for (size_t i = 0; i < ship_num_; ++i) {
    std::cout << "(";
    for (size_t j = 0; j < ships_[i]->GetLength(); ++j) {
      if (ships_[i]->GetSegmentState(j) == Ship::State::INTACT)
        std::cout << "[]";
      else if (ships_[i]->GetSegmentState(j) == Ship::State::DAMAGED)
        std::cout << "::";
      else
        std::cout << "X";
    }
    std::cout << "), ";
  }
  std::cout << '\n';
}

auto ShipManager::GetShipNum() -> size_t { return ship_num_; }

auto ShipManager::CheckForEnd() -> bool {
  for (size_t i = 0; i < ship_num_; ++i) {
    if (ships_[i]->CheckKilled() == false) return false;
  }
  return true;
}