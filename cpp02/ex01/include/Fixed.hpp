#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <ostream>

class Fixed {
public:
  Fixed();
  Fixed(const int value);
  Fixed(const float value);

  Fixed(const Fixed &fixed);

  ~Fixed();

  Fixed &operator=(const Fixed &fixed);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

private:
  int _fpnValue;
  const static int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
