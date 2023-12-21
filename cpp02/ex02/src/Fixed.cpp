#include "Fixed.hpp"

Fixed::Fixed() : _fpnValue(0) {
  std::cout << "Default constructor called!" << std::endl;
}

Fixed::Fixed(const int ivalue) : _fpnValue(ivalue << _fractionalBits) {
  std::cout << "Int constructor called!" << std::endl;
}

Fixed::Fixed(const float fvalue)
    : _fpnValue(roundf(fvalue * (1 << _fractionalBits))) {
  std::cout << "Float constructor called!" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called!" << std::endl;
  *this = fixed;
}

Fixed::~Fixed() { std::cout << "Destructor called!" << std::endl; }

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Copy assignment operator called!" << std::endl;

  if (this != &fixed)
    _fpnValue = fixed.getRawBits();
  return *this;
}

bool Fixed::operator>(const Fixed &fixed) {
  std::cout << "Greater than operator called!" << std::endl;
  return (_fpnValue > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) {
  std::cout << "Less than operator called!" << std::endl;
  return (_fpnValue < fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) {
  std::cout << "Less than or equal to operator called!" << std::endl;
  return (_fpnValue <= fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) {
  std::cout << "Greater than or equal to operator called!" << std::endl;
  return (_fpnValue >= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) {
  std::cout << "Equal to operator called!" << std::endl;
  return (_fpnValue == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) {
  std::cout << "Not equal to operator called!" << std::endl;
  return (_fpnValue != fixed.getRawBits());
}

Fixed Fixed::operator*(const Fixed &fixed) {
  std::cout << "Multiplication operator called!" << std::endl;
  return (Fixed(_fpnValue * fixed.getRawBits() >> _fractionalBits));
}

Fixed Fixed::operator/(const Fixed &fixed) {
  std::cout << "Division operator called!" << std::endl;
  return (Fixed(_fpnValue / fixed.getRawBits() >> _fractionalBits));
}

Fixed Fixed::operator+(const Fixed &fixed) {
  std::cout << "Addition operator called!" << std::endl;
  return (Fixed(_fpnValue + fixed.getRawBits()));
}

Fixed Fixed::operator-(const Fixed &fixed) {
  std::cout << "Subtraction operator called!" << std::endl;
  return (Fixed(_fpnValue - fixed.getRawBits()));
}

Fixed &Fixed::operator++() {
  std::cout << "Pre-increment operator called!" << std::endl;
  _fpnValue++;
  return *this;
}

Fixed Fixed::operator++(int n) {
  std::cout << "Post-increment operator called!" << std::endl;
}

Fixed &Fixed::operator--() {
  std::cout << "Pre-decrement operator called!" << std::endl;
  _fpnValue--;
  return *this;
}

Fixed Fixed::operator--(int n) {
  std::cout << "Post-decrement operator called!" << std::endl;
}

int Fixed::getRawBits(void) const { return _fpnValue; }

void Fixed::setRawBits(int const raw) { _fpnValue = raw; }

float Fixed::toFloat(void) const {
  return ((float)_fpnValue / (1 << _fractionalBits));
}

int Fixed::toInt(void) const {
  return ((int)roundf(_fpnValue >> _fractionalBits));
}

int Fixed::getMax(const int &fpnValue1, const int &fpnValue2) { return (); }

int Fixed::getMin(const int &fpnValue1, const int &fpnValue2) { return (); }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}
