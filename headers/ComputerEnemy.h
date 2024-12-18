#ifndef _t33nsy_COMPUTERENEMY
#define _t33nsy_COMPUTERENEMY

#include <algorithm>
#include <map>
#include <queue>

#include "GameField.h"

class ComputerEnemy {
 public:
  ComputerEnemy() {};
  ComputerEnemy(int sleep_time);
  auto DoAttack(GameField &field, int &xcoord, int &ycoord) -> Result;
  auto clear() -> void;  // clear the queue to next game
  auto queue_clear() -> void;

 private:
  std::queue<std::pair<int, int>> attack_queue_;
  int sleep_time_ = 100;  // queue of attack points
  std::pair<int, int> prev_destroy_ = {-2, -2};
  std::map<std::pair<int, int>, int> done_;
};

#endif /* _t33nsy_COMPUTERENEMY */
