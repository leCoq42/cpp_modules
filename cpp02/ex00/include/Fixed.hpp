#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
  Fixed();
  ~Fixed();
  Fixed(const Fixed &fixed);
  Fixed &operator=(const Fixed &fixed);

  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
  int _fpnValue;
  const static int _fractionalBits = 8;
};

#endif
