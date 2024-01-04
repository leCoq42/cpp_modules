#include "Fixed.hpp"

Fixed::Fixed() : _fpnValue(0) {
#ifdef DEBUG
  std::cout << "Default constructor called!" << std::endl;
#endif
}

Fixed::~Fixed() {
#ifdef DEBUG
  std::cout << "Destructor called!" << std::endl;
#endif
}

Fixed::Fixed(const Fixed &fixed) {
#ifdef DEBUG
  std::cout << "Copy constructor called!" << std::endl;
#endif
  *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
#ifdef DEBUG
  std::cout << "Copy assignment operator called!" << std::endl;
#endif

  if (this != &fixed)
    _fpnValue = fixed.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const {
#ifdef DEBUG
  std::cout << "getRawBits member function called!" << std::endl;
#endif

  return _fpnValue;
}

void Fixed::setRawBits(int const raw) {
#ifdef DEBUG
  std::cout << "setRawBits member function called!" << std::endl;
#endif

  _fpnValue = raw;
}
