#include <exception>

class NoSkillsException : public std::exception {
 public:
  const char* what() const noexcept;
};