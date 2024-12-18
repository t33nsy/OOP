#include "../headers/OutOfFieldException.h"

const char* OutOfFieldException::what() const noexcept {
  return "Out of field\n";
}