#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <ostream>

class Fixed {
public:
  Fixed();
  ~Fixed();

  Fixed(const Fixed &fixed);

  Fixed(const int value);
  Fixed(const float value);

  Fixed &operator=(const Fixed &fixed);

  Fixed &operator>(const Fixed &fixed);
  Fixed &operator<(const Fixed &fixed);
  Fixed &operator<=(const Fixed &fixed);
  Fixed &operator>=(const Fixed &fixed);
  Fixed &operator==(const Fixed &fixed);
  Fixed &operator!=(const Fixed &fixed);

  Fixed &operator*(const Fixed &fixed);
  Fixed &operator+(const Fixed &fixed);
  Fixed &operator-(const Fixed &fixed);
  Fixed &operator/(const Fixed &fixed);

  Fixed &operator++(const Fixed &fixed);
  Fixed &operator++(const Fixed &fixed);
  Fixed &operator--(const Fixed &fixed);
  Fixed &operator--(const Fixed &fixed);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

  int getMax(const int &_fpnValue1, const int &_fpnValue2);
  int getMin(const int &_fpnValue1, const int &_fpnValue2);

private:
  int _fpnValue;
  const static int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
