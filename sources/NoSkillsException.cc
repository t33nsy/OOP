#include "../headers/NoSkillsException.h"

const char* NoSkillsException::what() const noexcept { return "No skills"; }