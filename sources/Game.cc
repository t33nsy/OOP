#include "../headers/Game.h"

Game::Game() : n_(0), flag_(0), field_size_x_(0), field_size_y_(0) {
  ship_manager_ = nullptr;
  field_ = nullptr;
  ship_lens_ = std::vector<int>(0);
  skill_manager_ = new SkillManager();
}

auto Game::start() -> void {
  hstdout_ = GetStdHandle(STD_OUTPUT_HANDLE);
  std::cout << "Enter num of ships: ";
  std::cin >> n_;
  if (n_ <= 0) {
    while (n_ <= 0) {
      std::cout << "Num of ships must be >0, please rewrite: ";
      std::cin >> n_;
    }
  }
  ship_lens_ = std::vector<int>(n_);
  std::cout << "Write r if you want to do random ship sizes: ";
  std::cin >> flag_;
  if (flag_ == 'r') {
    srand(time(0));
    for (int i = 0; i < n_; ++i) {
      ship_lens_[i] = rand() % 4 + 1;
    }
  } else {
    std::cout << "Enter ship lengths: (len must be > 0 and < 5)\n";
    for (int i = 0; i < n_; ++i) {
      int temp;
      std::cin >> temp;
      while (temp <= 0 || temp >= 5) {
        std::cout << "Ship length must be > 0 and < 5, please rewrite: ";
        std::cin >> temp;
      }
      ship_lens_[i] = temp;
    }
  }
  ship_manager_ = new ShipManager(n_, ship_lens_);
  system("cls");
  std::cout << "Enter width and height of field: ";
  std::cin >> field_size_x_ >> field_size_y_;
  if (field_size_x_ <= 0) {
    while (field_size_x_ <= 0) {
      std::cout << "Width must be > 0, please rewrite: ";
      std::cin >> field_size_x_;
    }
  }
  if (field_size_y_ <= 0) {
    while (field_size_y_ <= 0) {
      std::cout << "Height must be > 0, please rewrite: ";
      std::cin >> field_size_y_;
    }
  }
  system("cls");
  field_ = new GameField(field_size_x_, field_size_y_);
  ship_manager_->InitGameField(*field_);
  field_->PrintField(hstdout_);
  std::cout
      << "Do you want to do field look like opponent's? Y - yes, N - no\n";
  std::cin >> flag_;
  if (flag_ == 'Y' || flag_ == 'y') {
    field_->DoLikeItOpponents();
    field_->PrintField(hstdout_);
  } else
    field_->PrintField(hstdout_);
}

auto Game::play() -> void {
  // field_->ShellingAnimation(hstdout_);
  // field_->PrintField(hstdout_);
  while (true) {
    std::cout << "Enter x and y coordinates of ship to fire: (enter -1 -1 to "
                 "use skill or -4 -4 to end)\n";
    std::cin >> x_ >> y_;
    bool ship_killed = false;
    std::string message_for_user = "";
    if (x_ == -4 && y_ == -4) {
      field_->DoVisible();
      field_->PrintField(hstdout_);
      std::cout << "\n\n\t\t\tGAME OVER\n\n";
      break;
    } else if (x_ == -1 && y_ == -1) {
      SkillManager::SkillType type;
      try {
        type = skill_manager_->WhatSkillNow();
      } catch (NoSkillsException &e) {
        std::cout << e.what();
        continue;
      }
      bool f = true;
      switch (type) {
        case SkillManager::RANDOMSHOT: {
          std::cout << "Using random shot\n";
          x_ = 0;
          y_ = 0;
          break;
        }
        case SkillManager::DOUBLEDAMAGE:
          std::cout << "Using double damage\n";
          f = false;
        case SkillManager::SCANNER: {
          if (f) std::cout << "Using scanner\n";
          std::cout << "Enter x and y coordinates to use your skill: \n";
          std::cin >> x_ >> y_;
          while (x_ < 0) {
            std::cout << "X must be >= 0\n";
            std::cin >> x_;
          }
          while (y_ < 0) {
            std::cout << "Y mush be >= 0\n";
            std::cin >> y_;
          }
          break;
        }
      }
      try {
        ship_killed = skill_manager_->UseOwnedSkill(x_, y_, *field_);
      } catch (NoSkillsException &e) {
        RewriteFieldWithMessage_(std::string(e.what()));
        continue;
      } catch (OutOfFieldException &e) {
        RewriteFieldWithMessage_(std::string(e.what()));
        continue;
      } catch (ShipKilled &e) {
        RewriteFieldWithMessage_(std::string(e.what()));
        continue;
      }
    } else {
      try {
        ship_killed = field_->Attack(x_, y_, true);
      } catch (OutOfFieldException e) {
        RewriteFieldWithMessage_(std::string(e.what()));
        continue;
      } catch (ShipKilled &e) {
        RewriteFieldWithMessage_(std::string(e.what()));
        continue;
      }
      field_->PrintField(hstdout_);
    }
    if (ship_killed) {
      std::cout << "OH YOU DESTROYED A SHIP, HERE IS YOUR SKILL:\n";
      skill_manager_->GetRandomSkill();
    }
    if (ship_manager_->CheckForEnd()) {
      field_->DoVisible();
      field_->PrintField(hstdout_);
      std::cout << "\n\n\t\t\tGAME OVER\n\n";
      break;
    }
  }
  ship_manager_->Print();
  do {
    Sleep(100);
  } while (!_kbhit());
}

auto Game::RewriteFieldWithMessage_(std::string message) -> void {
  field_->PrintField(hstdout_);
  std::cout << message;
}