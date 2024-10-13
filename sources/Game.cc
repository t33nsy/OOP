#include "../headers/Game.h"

Game::Game() {}

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
  ShipManager ship_manager_(n_, ship_lens_);
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
  GameField field_(field_size_x_, field_size_y_);
  ship_manager_.InitGameField(field_);
  field_.PrintField(hstdout_);
  std::cout
      << "Do you want to do field look like opponent's? Y - yes, N - no\n";
  std::cin >> flag_;
  if (flag_ == 'Y' || flag_ == 'y') {
    field_.DoLikeItOpponents();
    field_.PrintField(hstdout_);
  } else
    field_.PrintField(hstdout_);
  while (true) {
    std::cout << "Enter x and y coordinates of ship to fire: (enter <0 <0 to "
                 "end attack)\n";
    std::cin >> x_ >> y_;
    if (x_ <= -1 && y_ <= -1) {
      field_.DoVisible();
      field_.PrintField(hstdout_);
      std::cout << "\n\n\t\t\tGAME OVER\n\n";
      break;
    }
    try {
      field_.Attack(x_, y_);
    } catch (const char* error) {
      std::cout << error << '\n';
      continue;
    }
    if (ship_manager_.CheckForEnd()) {
      field_.DoVisible();
      field_.PrintField(hstdout_);
      std::cout << "\n\n\t\t\tGAME OVER\n\n";
      break;
    }
    field_.PrintField(hstdout_);
  }
  ship_manager_.Print();
  do {
    Sleep(100);
  } while (!_kbhit());
}