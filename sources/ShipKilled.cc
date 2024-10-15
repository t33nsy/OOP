#include "../headers/ShipKilled.h"

const char * ShipKilled::what() const noexcept{
  return "Ship segment was killed previously\n";
}