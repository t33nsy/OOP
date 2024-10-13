#include "../headers/GameField.h"

GameField::GameField(size_t size_x, size_t size_y)
    : size_x_(size_x), size_y_(size_y) {
  field_ = std::vector<std::vector<CellState>>(
      size_x_, std::vector<CellState>(size_y_, EMPTY));
  ship_indices_ = std::vector<std::vector<std::pair<Ship*, size_t>>>(
      size_x_, std::vector<std::pair<Ship*, size_t>>(
                   size_y_, std::make_pair(nullptr, -1)));
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

auto GameField::AddShip(Ship* ship, const size_t& x, const size_t& y,
                        const bool& vertical) -> void {
  bool is_x = false, is_y = false;
  if (vertical) {
    if (y + ship->GetLength() > size_y_) throw "Out of field";
    is_y = true;
  } else {
    if (x + ship->GetLength() > size_x_) throw "Out of field";
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
    field_[x + i * is_x][y + i * is_y] = SHIP;
    ship_indices_[x + i * is_x][y + i * is_y] = std::make_pair(ship, i);
  }
  ship->SetVertical(is_y);
}

auto GameField::PrintField() -> void {
  if (size_x_ < 1 || size_y_ < 1) throw "Field is empty";
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
  if (size_x_ < 1 || size_y_ < 1) throw "Field is empty";
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
          case Ship::State::INTACT: {
            SetConsoleTextAttribute(hStdOut, 2);
            std::cout << "O";
            break;
          }
          case Ship::State::DAMAGED: {
            SetConsoleTextAttribute(hStdOut, 12);
            std::cout << "O";
            break;
          }
          case Ship::State::KILLED: {
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

auto GameField::Attack(const size_t& x, const size_t& y) -> void {
  if (x >= size_x_ || y >= size_y_) throw "Out of field\n";
  if (ship_indices_[x][y].first != nullptr) {
    field_[x][y] = SHIP;
    ship_indices_[x][y].first->Hit(ship_indices_[x][y].second);
  } else {
    field_[x][y] = EMPTY;
  }
}

auto GameField::CheckForCollision(const size_t& x, const size_t& y) -> void {
  if (field_[x][y] == SHIP) throw CollisionException();
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