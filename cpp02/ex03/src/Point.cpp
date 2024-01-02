#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
#ifdef DEBUG
  std::cout << "Default constructor called!" << std::endl;
#endif
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
#ifdef DEBUG
  std::cout << "Custom constructor called!" << std::endl;
#endif
}

Point::Point(const Point &point) {
#ifdef DEBUG
  std::cout << "Copy constructor called!" << std::endl;
#endif
  *this = point;
}

Point &Point::operator=(const Point &point) {
#ifdef DEBUG
  std::cout << "Copy assignment operator called!" << std::endl;
#endif
  if (this != &point) {
    _x = point._x;
    _y = point._y;
  }
  return (*this);
}

Point::~Point() {
#ifdef DEBUG
  std::cout << "Destructor called!" << std::endl;
#endif
}
