#include <exception>
class CollisionException : public std::exception{
public:
  const char *what() const noexcept override;
};