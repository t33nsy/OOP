#ifndef SHIP_KILLED_H
#define SHIP_KILLED_H

#include <exception>

class ShipKilled : public std::exception {
 public:
  const char* what() const noexcept override;
};

#endif