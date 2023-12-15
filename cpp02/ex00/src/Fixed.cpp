#include "Fixed.hpp"

Fixed::Fixed() : _fpnValue(0) {
  std::cout << "Default constructor called!" << std::endl;
}

Fixed::~Fixed() { std::cout << "Destructor called!" << std::endl; }

Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called!" << std::endl;
  *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Copy assignment operator called!" << std::endl;

  if (this != &fixed)
    _fpnValue = fixed.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called!" << std::endl;
  return _fpnValue;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called!" << std::endl;
  _fpnValue = raw;
}
