#include "../headers/CollisionException.h"

const char *CollisionException::what() const noexcept {
  return "Collision found, please rewrite coordinates\n";
}