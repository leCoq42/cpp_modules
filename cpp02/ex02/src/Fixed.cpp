#include "Fixed.hpp"

Fixed::Fixed() : _bitValue(0) {
#ifdef DEBUG
  std::cout << "Default constructor called!" << std::endl;
#endif
}

Fixed::Fixed(const int ivalue) : _bitValue(ivalue << _fractionalBits) {
#ifdef DEBUG
  std::cout << "Int constructor called!" << std::endl;
#endif
}

Fixed::Fixed(const float fvalue)
    : _bitValue(roundf(fvalue * (1 << _fractionalBits))) {
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

int Fixed::getRawBits(void) const { return _bitValue; }

void Fixed::setRawBits(int const raw) { _bitValue = raw; }

float Fixed::toFloat(void) const {
  return ((float)_bitValue / (1 << _fractionalBits));
}

int Fixed::toInt(void) const {
  return ((int)roundf(_bitValue >> _fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &fixed) {
#ifdef DEBUG
  std::cout << "Copy assignment operator called!" << std::endl;
#endif

  if (this != &fixed)
    _bitValue = fixed.getRawBits();
  return (*this);
}

bool Fixed::operator>(const Fixed &fixed) {
#ifdef DEBUG
  std::cout << "Greater than operator called!" << std::endl;
#endif

  return (_bitValue > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) {
#ifdef DEBUG
  std::cout << "Less than operator called!" << std::endl;
#endif

  return (_bitValue < fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) {
#ifdef DEBUG
  std::cout << "Less than or equal to operator called!" << std::endl;
#endif

  return (_bitValue <= fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) {
#ifdef DEBUG
  std::cout << "Greater than or equal to operator called!" << std::endl;
#endif

  return (_bitValue >= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) {
#ifdef DEBUG
  std::cout << "Equal to operator called!" << std::endl;
#endif

  return (_bitValue == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) {
#ifdef DEBUG
  std::cout << "Not equal to operator called!" << std::endl;
#endif

  return (_bitValue != fixed.getRawBits());
}

Fixed Fixed::operator*(const Fixed &fixed) {
#ifdef DEBUG
  std::cout << "Multiplication operator called!" << std::endl;
#endif

  return (Fixed(toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) {
#ifdef DEBUG
  std::cout << "Division operator called!" << std::endl;
#endif

  return (Fixed(toFloat() / fixed.toFloat()));
}

Fixed Fixed::operator+(const Fixed &fixed) {
#ifdef DEBUG
  std::cout << "Addition operator called!" << std::endl;
#endif

  return (Fixed(toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) {
#ifdef DEBUG
  std::cout << "Subtraction operator called!" << std::endl;
#endif

  return (Fixed(toFloat() - fixed.toFloat()));
}

Fixed &Fixed::operator++() {
#ifdef DEBUG
  std::cout << "Pre-increment operator called!" << std::endl;
#endif

  ++_bitValue;
  return (*this);
}

Fixed Fixed::operator++(int n) {
#ifdef DEBUG
  std::cout << "Post-increment operator called!" << std::endl;
#endif

  (void)n;
  Fixed tmp(*this);
  _bitValue++;
  return (tmp);
}

Fixed &Fixed::operator--() {
#ifdef DEBUG
  std::cout << "Pre-decrement operator called!" << std::endl;
#endif

  --_bitValue;
  return (*this);
}

Fixed Fixed::operator--(int n) {
#ifdef DEBUG
  std::cout << "Post-decrement operator called!" << std::endl;
#endif

  (void)n;
  Fixed tmp(*this);
  _bitValue--;
  return (tmp);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b ? a : b); }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return (a._bitValue > b._bitValue ? a : b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b ? a : b); }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return (a._bitValue < b._bitValue ? a : b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}
