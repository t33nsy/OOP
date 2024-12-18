#include "../headers/ComputerEnemy.h"

ComputerEnemy::ComputerEnemy(int sleep_time) { sleep_time_ = sleep_time; }

auto ComputerEnemy::DoAttack(GameField &field, int &xcoord,
                             int &ycoord) -> Result {
  int x, y;
  Result result = Result::MISS;
  // Sleep(sleep_time_);  // fake delay
  for (int i = 0; i < 4 * field.GetWidth() * field.GetHeight(); ++i) {
    if (attack_queue_.empty()) {
      x = rand() % field.GetWidth();
      y = rand() % field.GetHeight();
    } else {
      x = attack_queue_.front().first;
      y = attack_queue_.front().second;
      attack_queue_.pop();
    }
    if (done_[{x, y}] == 2) continue;
    try {
      result = field.Attack(x, y, 1);
    } catch (...) {
      continue;
    }
    ++done_[{x, y}];
    xcoord = x;
    ycoord = y;
    break;
  }
  if (result == Result::HALF_HP) {
    int prevx = prev_destroy_.first - x, prevy = prev_destroy_.second - y;
    if (0 <= prevx <= 1 && 0 <= prevy <= 1 ||
        -1 <= prevx <= 0 && -1 <= prevy <= 0) {
      attack_queue_.push({x + prevx, y + prevy});
    }
    attack_queue_.push({x, y});
  } else if (result == Result::DESTROYED) {
    prev_destroy_ = {x, y};
    if (x + 1 >= 0 && y >= 0 && x + 1 < field.GetWidth() &&
        y < field.GetHeight())
      attack_queue_.push({x + 1, y});
    if (x >= 0 && y + 1 >= 0 && x < field.GetWidth() &&
        y + 1 < field.GetHeight())
      attack_queue_.push({x, y + 1});
    if (x - 1 >= 0 && y >= 0 && x - 1 < field.GetWidth() &&
        y < field.GetHeight())
      attack_queue_.push({x - 1, y});
    if (x >= 0 && y - 1 >= 0 && x < field.GetWidth() &&
        y - 1 < field.GetHeight())
      attack_queue_.push({x, y - 1});
  } else if (result == Result::FULL_DESTROYED) {
    queue_clear();
  }
  return result;
}

auto ComputerEnemy::clear() -> void { queue_clear(); }

auto ComputerEnemy::queue_clear() -> void {
  std::queue<std::pair<int, int>> empty;
  std::swap(attack_queue_, empty);
}