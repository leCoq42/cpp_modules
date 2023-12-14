#include "Fixed.hpp"

Fixed::Fixed() {
  std::cout << "Default constructor called!" << std::endl;
  this->_fpnValue = 0;
}

Fixed::~Fixed(){std::cout << "Destructor called!"}

Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called!" << std::endl;
  *this = fixed;
}

Fixed::Fixed &operator=(const Fixed &fixed) {
  std::cout << "Assignation operator called!" << std::endl;

  if (this != &fixed)
    _fpnValue = fixed.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const { return this->_fpnValue; }

const static int Fixed::setRawBits(int const raw) { this->_fpnValue = raw; }
