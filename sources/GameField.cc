#include "../headers/GameField.h"

GameField::GameField(size_t size_x, size_t size_y)
    : size_x_(size_x), size_y_(size_y) {
  field_ = std::vector<std::vector<CellState>>(
      size_x_, std::vector<CellState>(size_y_, EMPTY));
  ship_indices_ = std::vector<std::vector<std::pair<Ship*, int>>>(
      size_x_,
      std::vector<std::pair<Ship*, int>>(size_y_, std::make_pair(nullptr, -1)));
}

GameField::GameField(std::string serialized) {
  size_x_ = std::stoi(serialized.substr(0, serialized.find('-')));
  serialized = serialized.substr(serialized.find('-') + 1);
  size_y_ = std::stoi(serialized.substr(0, serialized.find('-')));
  serialized = serialized.substr(serialized.find('-') + 1);
  field_ = std::vector<std::vector<CellState>>(
      size_x_, std::vector<CellState>(size_y_, EMPTY));
  for (int i = 0; i < size_x_; ++i) {
    std::string temp = serialized.substr(0, serialized.find('-'));
    for (int j = 0; j < size_y_; ++j) {
      field_[i][j] = static_cast<CellState>(std::stoi(temp.substr(j, 1)));
    }
    serialized = serialized.substr(serialized.find('-') + 1);
  }
  ship_indices_ = std::vector<std::vector<std::pair<Ship*, int>>>(
      size_x_,
      std::vector<std::pair<Ship*, int>>(size_y_, std::make_pair(nullptr, -1)));
}

GameField::GameField(const GameField& other)
    : size_x_(other.size_x_), size_y_(other.size_y_) {
  field_ = other.field_;
  ship_indices_ = other.ship_indices_;
}

auto GameField::operator=(const GameField& other) -> GameField& {
  GameField temp(other);
  std::swap(size_x_, temp.size_x_);
  std::swap(size_y_, temp.size_y_);
  std::swap(field_, temp.field_);
  std::swap(ship_indices_, temp.ship_indices_);
  return *this;
}

GameField::GameField(GameField&& other) : size_x_(0), size_y_(0) {
  std::swap(size_x_, other.size_x_);
  std::swap(size_y_, other.size_y_);
  std::swap(field_, other.field_);
  std::swap(ship_indices_, other.ship_indices_);
}

auto GameField::operator=(GameField&& other) -> GameField& {
  if (this != &other) {
    size_x_ = 0;
    size_y_ = 0;
    std::swap(size_x_, other.size_x_);
    std::swap(size_y_, other.size_y_);
    std::swap(field_, other.field_);
    std::swap(ship_indices_, other.ship_indices_);
  }
  return *this;
}

GameField::~GameField() {
  for (int i = 0; i < size_x_; ++i) {
    field_[i].clear();
    ship_indices_[i].clear();
  }
  field_.clear();
  ship_indices_.clear();
}

auto GameField::AddShip(Ship* ship, const int& x, const int& y,
                        const bool& vertical) -> void {
  bool is_x = false, is_y = false;
  if (vertical) {
    if (y + ship->GetLength() > size_y_ || y < 0) throw OutOfFieldException();
    is_y = true;
  } else {
    if (x + ship->GetLength() > size_x_ || x < 0) throw OutOfFieldException();
    is_x = true;
  }
  for (size_t i = 0; i < ship->GetLength(); ++i) {
    try {
      CheckForCollision(x + i * is_x, y + i * is_y);
    } catch (CollisionException e()) {
      throw e;
    }
  }
  for (size_t i = 0; i < ship->GetLength(); ++i) {
    if (field_[x + i * is_x][y + i * is_y] != UNKNOWN)
      field_[x + i * is_x][y + i * is_y] = SHIP;
    ship_indices_[x + i * is_x][y + i * is_y] = std::make_pair(ship, i);
  }
  ship->SetVertical(static_cast<Orientation>(is_y));
}

auto GameField::AddShip(Ship* ship, const int& x, const int& y,
                        Orientation vertical) -> void {
  bool is_x = false, is_y = false;
  if (vertical == Orientation::VERTICAL) {
    if (y + ship->GetLength() > size_y_ || y < 0) throw OutOfFieldException();
    is_y = true;
  } else {
    if (x + ship->GetLength() > size_x_ || x < 0) throw OutOfFieldException();
    is_x = true;
  }
  for (size_t i = 0; i < ship->GetLength(); ++i) {
    try {
      CheckForCollision(x + i * is_x, y + i * is_y);
    } catch (CollisionException e()) {
      throw e;
    }
  }
  for (size_t i = 0; i < ship->GetLength(); ++i) {
    if (field_[x + i * is_x][y + i * is_y] != UNKNOWN)
      field_[x + i * is_x][y + i * is_y] = SHIP;
    ship_indices_[x + i * is_x][y + i * is_y] = std::make_pair(ship, i);
  }
  ship->SetVertical(vertical);
}

auto GameField::PrintField() -> void {
  if (size_x_ < 1 || size_y_ < 1) return;
  std::cout << "  | ";
  for (size_t i = 0; i < size_x_; ++i) {
    std::cout << char(65 + i) << " | ";
  }
  std::cout << '\n';
  for (size_t i = 0; i <= size_x_; ++i) {
    std::cout << "----";
  }
  std::cout << '\n';
  for (size_t i = 0; i < size_y_; ++i) {
    std::cout << i << " | ";
    for (size_t j = 0; j < size_x_; ++j) {
      if (field_[j][i] == UNKNOWN) {
        std::cout << "? | ";
      } else if (field_[j][i] == SHIP) {
        std::cout << "O | ";
      } else {
        std::cout << "  | ";
      }
    }
    std::cout << '\n';
    for (size_t j = 0; j <= size_x_; ++j) {
      std::cout << "----";
    }
    std::cout << '\n';
  }
}

auto GameField::PrintField(HANDLE& hStdOut) -> void {
  system("cls");
  if (size_x_ < 1 || size_y_ < 1) return;
  std::cout << "  | ";
  for (size_t i = 0; i < size_x_; ++i) {
    std::cout << char(65 + i) << " | ";
  }
  std::cout << '\n';
  for (size_t i = 0; i <= size_x_; ++i) {
    std::cout << "----";
  }
  std::cout << '\n';
  for (size_t i = 0; i < size_y_; ++i) {
    std::cout << i << " | ";
    for (size_t j = 0; j < size_x_; ++j) {
      if (field_[j][i] == UNKNOWN) {
        std::cout << "? | ";
      } else if (field_[j][i] == SHIP || ship_indices_[j][i].first != nullptr) {
        switch (ship_indices_[j][i].first->GetSegmentState(
            ship_indices_[j][i].second)) {
          case State::INTACT: {
            SetConsoleTextAttribute(hStdOut, 2);
            std::cout << "O";
            break;
          }
          case State::DAMAGED: {
            SetConsoleTextAttribute(hStdOut, 12);
            std::cout << "O";
            break;
          }
          case State::KILLED: {
            SetConsoleTextAttribute(hStdOut, 4);
            std::cout << "X";
            break;
          }
        }
        SetConsoleTextAttribute(hStdOut, 7);
        std::cout << " | ";
      } else
        std::cout << "  | ";
    }
    std::cout << '\n';
    for (size_t j = 0; j <= size_x_; ++j) {
      std::cout << "----";
    }
    std::cout << '\n';
  }
}

auto GameField::Attack(const size_t& x, const size_t& y,
                       bool change_state) -> Result {
  Result attack_result = Result::MISS;
  if (x >= size_x_ || y >= size_y_) throw OutOfFieldException();
  if (ship_indices_[x][y].first != nullptr) {
    change_state ? field_[x][y] = SHIP : field_[x][y];
    try {
      attack_result =
          ship_indices_[x][y].first->Hit(ship_indices_[x][y].second);
    } catch (ShipKilled& e) {
      throw e;
    }
  } else {
    change_state ? field_[x][y] = EMPTY : field_[x][y];
  }
  return attack_result;
}

auto GameField::DealDoubleDamage(const size_t& x, const size_t& y) -> Result {
  Result attack_result = Result::MISS;
  if (x >= size_x_ || y >= size_y_) throw OutOfFieldException();
  if (ship_indices_[x][y].first != nullptr) {
    field_[x][y] = SHIP;
    try {
      attack_result = ship_indices_[x][y].first->HitWithDoubleDamage(
          ship_indices_[x][y].second);
    } catch (ShipKilled& e) {
      throw e;
    }
  } else {
    field_[x][y] = EMPTY;
  }
  return attack_result;
}

auto GameField::CheckForCollision(const size_t& x, const size_t& y) -> void {
  if (field_[x][y] == SHIP && ship_indices_[x][y].first != nullptr)
    throw CollisionException();
  for (auto i : {-1, 0, 1}) {
    for (auto j : {-1, 0, 1}) {
      if (x + i >= 0 && y + j >= 0 && x + i < size_x_ && y + j < size_y_ &&
          ship_indices_[x + i][y + j].first != nullptr &&
          ship_indices_[x + i][y + j].first != ship_indices_[x][y].first) {
        throw CollisionException();
      }
    }
  }
}

auto GameField::GetWidth() -> size_t { return size_x_; }

auto GameField::GetHeight() -> size_t { return size_y_; }

auto GameField::DoLikeItOpponents() -> void {
  for (size_t i = 0; i < size_x_; ++i) {
    for (size_t j = 0; j < size_y_; ++j) {
      field_[i][j] = UNKNOWN;
    }
  }
}

auto GameField::DoVisible() -> void {
  for (size_t i = 0; i < size_x_; ++i) {
    for (size_t j = 0; j < size_y_; ++j) {
      if (ship_indices_[i][j].first != nullptr) {
        field_[i][j] = SHIP;
      } else
        field_[i][j] = EMPTY;
    }
  }
}

auto GameField::CheckCell(size_t x, size_t y) -> bool {
  if (x >= size_x_ || y >= size_y_) throw OutOfFieldException();
  if (ship_indices_[x][y].first != nullptr &&
      ship_indices_[x][y].first->GetSegmentState(ship_indices_[x][y].second) !=
          KILLED)
    return true;
  return false;
}

auto GameField::ToCharArray(bool isShown) -> std::vector<std::vector<char>> {
  std::vector<std::vector<char>> result(size_x_, std::vector<char>(size_y_));
  for (size_t i = 0; i < size_x_; ++i) {
    for (size_t j = 0; j < size_y_; ++j) {
      if (field_[i][j] == SHIP) {
        switch (ship_indices_[i][j].first->GetSegmentState(
            ship_indices_[i][j].second)) {
          case State::KILLED:
            result[i][j] = 'K';
            break;
          case State::DAMAGED:
            if (isShown)
              result[i][j] = 'X';
            else
              result[i][j] = 'O';
            break;
          case State::INTACT:
            if (isShown)
              result[i][j] = 'O';
            else
              result[i][j] = '#';
            break;
        }
      } else if (field_[i][j] == EMPTY) {
        if (isShown)
          result[i][j] = ' ';
        else
          result[i][j] = 'M';
      } else {
        result[i][j] = '#';
      }
    }
  }
  return result;
}  // for drawing

auto GameField::Serialize() -> std::string {
  std::string result;
  result += std::to_string(size_x_);
  result += "-";
  result += std::to_string(size_y_);
  result += "-";
  for (size_t i = 0; i < size_x_; ++i) {
    for (size_t j = 0; j < size_y_; ++j) {
      result += std::to_string(field_[i][j]);
    }
    result += "-";
  }
  return result;
}
