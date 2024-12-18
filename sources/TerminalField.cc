#include "../headers/TerminalField.h"

TerminalField::TerminalField(int x, int y) : x_(x), y_(y) {
  player_cells_ =
      std::vector<std::vector<char>>(x_ + 1, std::vector<char>(y_ + 1, ' '));
  enemy_cells_ =
      std::vector<std::vector<char>>(x_ + 1, std::vector<char>(y_ + 1, '#'));
}

TerminalField::TerminalField(int x, int y, std::vector<std::vector<char>> field,
                             std::vector<std::vector<char>> opponent_field)
    : x_(x), y_(y) {
  player_cells_ = field;
  enemy_cells_ = opponent_field;
}

auto TerminalField::PrintOnlyPlayer() -> void {
  system("cls");
  SetConsoleCursorPosition(hstdout_, {0, 0});
  std::cout << "+";
  for (int i = 0; i <= x_; ++i) {
    std::cout << "-";
  }
  std::cout << "+";
  for (int j = 1; j <= y_ + 1; ++j) {
    SetConsoleCursorPosition(
        hstdout_, {static_cast<short>(x_ + 2), static_cast<short>(j)});
    std::cout << "|";
  }
  SetConsoleCursorPosition(
      hstdout_, {static_cast<short>(x_ + 2), static_cast<short>(y_ + 2)});
  std::cout << "+";
  SetConsoleCursorPosition(hstdout_, {0, 0});
  for (int j = 1; j <= y_ + 1; ++j) {
    SetConsoleCursorPosition(hstdout_, {0, static_cast<short>(j)});
    std::cout << "|";
  }
  SetConsoleCursorPosition(hstdout_, {0, static_cast<short>(y_ + 2)});
  std::cout << "+";
  for (int i = 0; i <= x_; ++i) {
    std::cout << "-";
  }
  std::cout << "+";
  for (int i = 0; i <= x_; ++i) {
    for (int j = 0; j <= y_; ++j) {
      SetConsoleCursorPosition(
          hstdout_, {static_cast<short>(i + 1), static_cast<short>(j + 1)});
      switch (player_cells_[i][j]) {
        case 'M': {
          SetConsoleTextAttribute(
              hstdout_, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
          std::cout << " ";
          SetConsoleTextAttribute(
              hstdout_, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
          break;
        }
        case ' ': {
          std::cout << " ";
          break;
        }
        case 'O': {
          SetConsoleTextAttribute(hstdout_, BACKGROUND_BLUE | FOREGROUND_GREEN);
          std::cout << "O";
          SetConsoleTextAttribute(
              hstdout_, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
          break;
        }
        case 'X': {
          SetConsoleTextAttribute(
              hstdout_, BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_BLUE);
          std::cout << "X";
          SetConsoleTextAttribute(
              hstdout_, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
          break;
        }
        case 'K': {
          SetConsoleTextAttribute(hstdout_, BACKGROUND_RED | FOREGROUND_BLUE);
          std::cout << "X";
          SetConsoleTextAttribute(
              hstdout_, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
          break;
        }
        case '#': {
          std::cout << "O";
        }
        default: {
          std::cout << ' ';
        }
      }
    }
  }
  COORD coord = {static_cast<short>(x_ + 2), static_cast<short>(y_ + 2)};
  SetConsoleCursorPosition(hstdout_, coord);
}

auto TerminalField::PrintOnlyComp() -> void {
  COORD prevcoord = {getXcoord(), getYcoord()};
  COORD coord = {static_cast<short>(x_ + 4), static_cast<short>(0)};
  SetConsoleCursorPosition(hstdout_, coord);
  std::cout << "+";
  for (int i = 0; i <= x_; ++i) {
    std::cout << "-";
  }
  std::cout << "+";
  for (int j = 1; j <= y_ + 1; ++j) {
    SetConsoleCursorPosition(hstdout_, {static_cast<short>(coord.X + x_ + 2),
                                        static_cast<short>(j)});
    std::cout << "|";
  }
  SetConsoleCursorPosition(
      hstdout_, {static_cast<short>(coord.X + 2), static_cast<short>(y_ + 2)});
  std::cout << "+";
  SetConsoleCursorPosition(hstdout_, coord);
  for (int j = 1; j <= y_ + 1; ++j) {
    SetConsoleCursorPosition(hstdout_, {coord.X, static_cast<short>(j)});
    std::cout << "|";
  }
  SetConsoleCursorPosition(hstdout_, {coord.X, static_cast<short>(y_ + 2)});
  std::cout << "+";
  for (int i = 0; i <= x_; ++i) {
    std::cout << "-";
  }
  std::cout << "+";
  for (int i = 0; i <= x_; ++i) {
    for (int j = 0; j <= y_; ++j) {
      SetConsoleCursorPosition(hstdout_, {static_cast<short>(coord.X + i + 1),
                                          static_cast<short>(j + 1)});
      switch (enemy_cells_[i][j]) {
        case 'M': {
          SetConsoleTextAttribute(
              hstdout_, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
          std::cout << " ";
          SetConsoleTextAttribute(
              hstdout_, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
          break;
        }
        case 'O': {
          SetConsoleTextAttribute(hstdout_, BACKGROUND_BLUE | FOREGROUND_GREEN);
          std::cout << "O";
          SetConsoleTextAttribute(
              hstdout_, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
          break;
        }
        case 'X': {
          SetConsoleTextAttribute(hstdout_, BACKGROUND_RED | FOREGROUND_BLUE);
          std::cout << "X";
          SetConsoleTextAttribute(
              hstdout_, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
          break;
        }
        case 'K': {
          SetConsoleTextAttribute(hstdout_, BACKGROUND_RED | FOREGROUND_BLUE);
          std::cout << "X";
          SetConsoleTextAttribute(
              hstdout_, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
          break;
        }
        default: {
          std::cout << '#';
        }
      }
    }
  }
  SetConsoleCursorPosition(hstdout_, prevcoord);
  coord.X++;
  coord.Y++;
  previous_position_ = coord;
}

auto TerminalField::ResetOpponentField() -> void {
  enemy_cells_ =
      std::vector<std::vector<char>>(x_ + 1, std::vector<char>(y_ + 1, '#'));
  PrintOnlyComp();
}

auto TerminalField::Reset() -> void {
  player_cells_ =
      std::vector<std::vector<char>>(x_ + 1, std::vector<char>(y_ + 1, ' '));
  enemy_cells_ =
      std::vector<std::vector<char>>(x_ + 1, std::vector<char>(y_ + 1, '#'));
  PrintOnlyPlayer();
}

auto TerminalField::Print() -> void {
  COORD prevcoord = {getXcoord(), getYcoord()};
  PrintOnlyPlayer();
  COORD coord = {static_cast<short>(x_ + 4), static_cast<short>(0)};
  SetConsoleCursorPosition(hstdout_, coord);
  std::cout << "+";
  for (int i = 0; i <= x_; ++i) {
    std::cout << "-";
  }
  std::cout << "+";
  for (int j = 1; j <= y_ + 1; ++j) {
    SetConsoleCursorPosition(hstdout_, {static_cast<short>(coord.X + x_ + 2),
                                        static_cast<short>(j)});
    std::cout << "|";
  }
  SetConsoleCursorPosition(
      hstdout_, {static_cast<short>(coord.X + 2), static_cast<short>(y_ + 2)});
  std::cout << "+";
  SetConsoleCursorPosition(hstdout_, coord);
  for (int j = 1; j <= y_ + 1; ++j) {
    SetConsoleCursorPosition(hstdout_, {coord.X, static_cast<short>(j)});
    std::cout << "|";
  }
  SetConsoleCursorPosition(hstdout_, {coord.X, static_cast<short>(y_ + 2)});
  std::cout << "+";
  for (int i = 0; i <= x_; ++i) {
    std::cout << "-";
  }
  std::cout << "+";
  PrintOnlyComp();
  SetConsoleCursorPosition(hstdout_, prevcoord);
  coord.X++;
  coord.Y++;
  previous_position_ = coord;
}

auto TerminalField::ChangeState(int x, int y, Result result) -> void {
  COORD coord = {getXcoord(), getYcoord()};
  SetConsoleCursorPosition(hstdout_, previous_position_);
  switch (result) {
    case Result::MISS: {
      enemy_cells_[x][y] = 'M';
      SetConsoleTextAttribute(
          hstdout_, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
      std::cout << " ";
      SetConsoleTextAttribute(
          hstdout_, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
      break;
    }
    case Result::HALF_HP: {
      enemy_cells_[x][y] = 'O';
      SetConsoleTextAttribute(hstdout_, BACKGROUND_BLUE | FOREGROUND_GREEN);
      std::cout << "O";
      SetConsoleTextAttribute(
          hstdout_, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
      break;
    }
    case Result::DESTROYED: {
      enemy_cells_[x][y] = 'X';
      SetConsoleTextAttribute(hstdout_, BACKGROUND_RED | FOREGROUND_BLUE);
      std::cout << "X";
      SetConsoleTextAttribute(
          hstdout_, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
      break;
    }
    case Result::WIN: {
    }
    case Result::FULL_DESTROYED: {
      enemy_cells_[x][y] = 'K';
      SetConsoleTextAttribute(hstdout_, BACKGROUND_RED | FOREGROUND_BLUE);
      std::cout << "X";
      SetConsoleTextAttribute(
          hstdout_, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
      break;
    }
    default: {
      break;
    }
  }
  SetConsoleCursorPosition(hstdout_, previous_position_);
}

auto TerminalField::ChangeCompState(int x, int y, Result result) -> void {
  COORD coord = {static_cast<short>(x + 1), static_cast<short>(y + 1)};
  COORD prev_coord = {getXcoord(), getYcoord()};
  SetConsoleCursorPosition(hstdout_, coord);
  switch (result) {
    case Result::MISS: {
      SetConsoleTextAttribute(
          hstdout_, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
      std::cout << " ";
      SetConsoleTextAttribute(
          hstdout_, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
      break;
    }
    case Result::HALF_HP: {
      SetConsoleTextAttribute(hstdout_, BACKGROUND_BLUE | FOREGROUND_GREEN);
      std::cout << "O";
      SetConsoleTextAttribute(
          hstdout_, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
      break;
    }
    case Result::DESTROYED: {
      SetConsoleTextAttribute(hstdout_, BACKGROUND_RED | FOREGROUND_BLUE);
      std::cout << "X";
      SetConsoleTextAttribute(
          hstdout_, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
      break;
    }
    case Result::FULL_DESTROYED: {
      SetConsoleTextAttribute(hstdout_, BACKGROUND_RED | FOREGROUND_BLUE);
      std::cout << "X";
      SetConsoleTextAttribute(
          hstdout_, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
      break;
    }
    default: {
      break;
    }
  }
  SetConsoleCursorPosition(hstdout_, prev_coord);
}

auto TerminalField::PrintShip(int x, int y, int size,
                              Orientation orient) -> void {
  SetConsoleCursorPosition(
      hstdout_, {static_cast<short>(x + 1), static_cast<short>(y + 1)});
  if (orient == Orientation::HORIZONTAL)
    for (int i = 0; i < size; ++i) {
      std::cout << "O";
    }
  else {
    for (int i = 0; i < size; ++i) {
      SetConsoleCursorPosition(
          hstdout_, {static_cast<short>(x + 1), static_cast<short>(y + i + 1)});
      std::cout << "O";
    }
  }
  SetConsoleCursorPosition(hstdout_, {0, 0});
}

auto TerminalField::DeleteShip(int x, int y, int size,
                               Orientation orient) -> void {
  SetConsoleCursorPosition(
      hstdout_, {static_cast<short>(x + 1), static_cast<short>(y + 1)});
  if (orient == Orientation::HORIZONTAL)
    for (int i = 0; i < size; ++i) {
      std::cout << " ";
    }
  else {
    for (int i = 0; i < size; ++i) {
      SetConsoleCursorPosition(
          hstdout_, {static_cast<short>(x + 1), static_cast<short>(y + i + 1)});
      std::cout << " ";
    }
  }
  SetConsoleCursorPosition(hstdout_, {0, 0});
}

auto TerminalField::PrintInfo(std::string info) -> void {
  std::pair<short, short> coord = {getXcoord(), getYcoord()};
  SetConsoleCursorPosition(hstdout_, {0, static_cast<short>(y_ + 3)});
  std::cout << info;
  SetConsoleCursorPosition(hstdout_, {coord.first, coord.second});
}

auto TerminalField::DeleteInfo() -> void {
  std::pair<short, short> coord = {getXcoord(), getYcoord()};
  SetConsoleCursorPosition(hstdout_, {0, static_cast<short>(y_ + 3)});
  for (int i = 0; i < 80; ++i) std::cout << " ";
  SetConsoleCursorPosition(hstdout_, {coord.first, coord.second});
}

auto TerminalField::FixShip(int x, int y, int size,
                            Orientation orient) -> void {
  for (int j = 0; j < size; ++j) {
    if (orient == Orientation::HORIZONTAL) {
      player_cells_[x + j][y] = 'O';
    } else {
      player_cells_[x][y + j] = 'O';
    }
  }
}

auto TerminalField::DisplayPlayerPosition(int x, int y) -> void {
  SetConsoleCursorPosition(hstdout_, previous_position_);
  std::cout << " ";
  previous_position_ = {static_cast<short>(x + x_ + 5),
                        static_cast<short>(y + 1)};
  SetConsoleCursorPosition(hstdout_, previous_position_);
  SetConsoleTextAttribute(hstdout_, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
  std::cout << "o";
  SetConsoleTextAttribute(hstdout_,
                          FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
  SetConsoleCursorPosition(hstdout_, previous_position_);
}

auto TerminalField::getXcoord() -> short {
  CONSOLE_SCREEN_BUFFER_INFO info_x;
  GetConsoleScreenBufferInfo(hstdout_, &info_x);
  return info_x.dwCursorPosition.X;
}

auto TerminalField::getYcoord() -> short {
  CONSOLE_SCREEN_BUFFER_INFO info_y;
  GetConsoleScreenBufferInfo(hstdout_, &info_y);
  return info_y.dwCursorPosition.Y;
}