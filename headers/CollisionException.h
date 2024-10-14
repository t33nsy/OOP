#ifndef COLLISION_EXCEPTION_H
#define COLLISION_EXCEPTION_H

#include <exception>
class CollisionException : public std::exception{
public:
  const char *what() const noexcept override;
};

#endif