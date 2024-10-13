#include <exception>
class OutOfFieldException : public std::exception {
 public:
  const char* what() const noexcept override;
};