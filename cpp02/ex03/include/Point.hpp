#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
  Point();
  Point(const float x, const float y);
  Point(const Point &point);
  Point &operator=(const Point &point);
  ~Point();

private:
  Fixed const _x;
  Fixed const _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
