#ifndef NOSKILLSEXCEPTION_H
#define NOSKILLSEXCEPTION_H
#include <exception>

class NoSkillsException : public std::exception {
 public:
  const char* what() const noexcept override;
};

#endif