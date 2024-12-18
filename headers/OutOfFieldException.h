#ifndef OUT_OF_FIELD_EXCEPTION_H
#define OUT_OF_FIELD_EXCEPTION_H

#include <exception>

class OutOfFieldException : public std::exception {
 public:
  const char* what() const noexcept override;
};

#endif