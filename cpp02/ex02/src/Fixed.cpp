#include "Fixed.hpp"

Fixed::Fixed() : _bitValue(0) {
  std::cout << "Default constructor called!" << std::endl;
}

Fixed::Fixed(const int ivalue) : _bitValue(ivalue << _fractionalBits) {
  std::cout << "Int constructor called!" << std::endl;
}

Fixed::Fixed(const float fvalue)
    : _bitValue(roundf(fvalue * (1 << _fractionalBits))) {
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
    _bitValue = fixed.getRawBits();
  return *this;
}

bool Fixed::operator>(const Fixed &fixed) {
  std::cout << "Greater than operator called!" << std::endl;
  return (_bitValue > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) {
  std::cout << "Less than operator called!" << std::endl;
  return (_bitValue < fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) {
  std::cout << "Less than or equal to operator called!" << std::endl;
  return (_bitValue <= fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) {
  std::cout << "Greater than or equal to operator called!" << std::endl;
  return (_bitValue >= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) {
  std::cout << "Equal to operator called!" << std::endl;
  return (_bitValue == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) {
  std::cout << "Not equal to operator called!" << std::endl;
  return (_bitValue != fixed.getRawBits());
}

Fixed Fixed::operator*(const Fixed &fixed) {
  std::cout << "Multiplication operator called!" << std::endl;

  int res =
      ((long long)_bitValue * (long long)fixed.getRawBits()) >> _fractionalBits;
  return (Fixed(res));
}

Fixed Fixed::operator/(const Fixed &fixed) {
  std::cout << "Division operator called!" << std::endl;

  int res =
      ((long long)_bitValue << _fractionalBits) / (long long)fixed.getRawBits();
  return (Fixed(res));
}

Fixed Fixed::operator+(const Fixed &fixed) {
  std::cout << "Addition operator called!" << std::endl;
  return (Fixed(_bitValue + fixed.getRawBits()));
}

Fixed Fixed::operator-(const Fixed &fixed) {
  std::cout << "Subtraction operator called!" << std::endl;
  return (Fixed(_bitValue - fixed.getRawBits()));
}

Fixed &Fixed::operator++() {
  std::cout << "Pre-increment operator called!" << std::endl;
  ++_bitValue;
  return (*this);
}

Fixed Fixed::operator++(int n) {
  std::cout << "Post-increment operator called!" << std::endl;

  (void)n;
  Fixed tmp(*this);
  _bitValue++;
  return (tmp);
}

Fixed &Fixed::operator--() {
  std::cout << "Pre-decrement operator called!" << std::endl;
  --_bitValue;
  return (*this);
}

Fixed Fixed::operator--(int n) {
  std::cout << "Post-decrement operator called!" << std::endl;

  (void)n;
  Fixed tmp(*this);
  _bitValue--;
  return (tmp);
}

int Fixed::getRawBits(void) const { return _bitValue; }

void Fixed::setRawBits(int const raw) { _bitValue = raw; }

float Fixed::toFloat(void) const {
  return ((float)_bitValue / (1 << _fractionalBits));
}

int Fixed::toInt(void) const {
  return ((int)roundf(_bitValue >> _fractionalBits));
}

int Fixed::getMax(const int &fpnValue1, const int &fpnValue2) { return (); }

int Fixed::getMin(const int &fpnValue1, const int &fpnValue2) { return (); }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}
