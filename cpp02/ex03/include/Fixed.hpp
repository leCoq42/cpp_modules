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
  Fixed &operator=(const Fixed &fixed);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

  bool operator>(const Fixed &fixed);
  bool operator<(const Fixed &fixed);
  bool operator<=(const Fixed &fixed);
  bool operator>=(const Fixed &fixed);
  bool operator==(const Fixed &fixed);
  bool operator!=(const Fixed &fixed);

  Fixed operator*(const Fixed &fixed);
  Fixed operator+(const Fixed &fixed);
  Fixed operator-(const Fixed &fixed);
  Fixed operator/(const Fixed &fixed);

  Fixed &operator++();
  Fixed operator++(int n);
  Fixed &operator--();
  Fixed operator--(int n);

  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);
  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);

private:
  int _bitValue;
  const static int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
