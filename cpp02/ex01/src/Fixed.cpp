#include "Fixed.hpp"

Fixed::Fixed() : _fpnValue(0) {
#ifdef DEBUG
  std::cout << "Default constructor called!" << std::endl;
#endif
}

Fixed::Fixed(const int ivalue) : _fpnValue(ivalue << _fractionalBits) {
#ifdef DEBUG
  std::cout << "Int constructor called!" << std::endl;
#endif
}

Fixed::Fixed(const float fvalue)
    : _fpnValue(roundf(fvalue * (1 << _fractionalBits))) {
#ifdef DEBUG
  std::cout << "Float constructor called!" << std::endl;
#endif
}

Fixed::Fixed(const Fixed &fixed) {
#ifdef DEBUG
  std::cout << "Copy constructor called!" << std::endl;
#endif
  *this = fixed;
}

Fixed::~Fixed() {
#ifdef DEBUG
  std::cout << "Destructor called!" << std::endl;
#endif
}

Fixed &Fixed::operator=(const Fixed &fixed) {
#ifdef DEBUG
  std::cout << "Copy assignment operator called!" << std::endl;
#endif

  if (this != &fixed)
    _fpnValue = fixed.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const { return _fpnValue; }

void Fixed::setRawBits(int const raw) { _fpnValue = raw; }

float Fixed::toFloat(void) const {
  return ((float)_fpnValue / (1 << _fractionalBits));
}

int Fixed::toInt(void) const {
  return ((int)roundf(_fpnValue >> _fractionalBits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}
