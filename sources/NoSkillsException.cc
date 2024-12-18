#include "../headers/NoSkillsException.h"

const char* NoSkillsException::what() const noexcept {
  return "No skills, try to kill ship to get one\n";
}