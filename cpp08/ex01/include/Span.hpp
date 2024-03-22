#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <ctime>
#include <iostream>
#include <limits>
#include <vector>

template <typename T> class Span {
  static_assert(std::is_arithmetic_v<T>, "Span requires an arithmetic type.");

public:
  Span();
  Span(unsigned int N);
  Span(const Span<T> &src);
  Span<T> &operator=(const Span<T> &rhs);
  ~Span();

  void addNumber(T n);
  void addRange(const std::vector<T> &range);
  T shortestSpan();
  T longestSpan();

  class SpanFullException : public std::exception {
  public:
    virtual const char *what() const noexcept override;
  };

  class NoSpanException : public std::exception {
  public:
    virtual const char *what() const noexcept override;
  };

private:
  std::vector<T> _Span;
  unsigned int _maxSize;
};

template <typename T> Span<T>::Span() : _maxSize(0) {
#ifdef DEBUG
  std::cout << "Span default constructor called" << std::endl;
#endif
}

template <typename T> Span<T>::Span(unsigned int N) : _maxSize(N) {
#ifdef DEBUG
  std::cout << "Span parameterized constructor called" << std::endl;
#endif
  try {
    _Span.reserve(N);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "capacity: " << _Span.capacity() << std::endl;
}

template <typename T> Span<T>::~Span() {
#ifdef DEBUG
  std::cout << "Span destructor called" << std::endl;
#endif
}

template <typename T> Span<T>::Span(const Span<T> &src) {
#ifdef DEBUG
  std::cout << "Span copy constructor called" << std::endl;
#endif

  _Span = src._Span;
  _maxSize = src._maxSize;
}

template <typename T> Span<T> &Span<T>::operator=(const Span<T> &rhs) {
#ifdef DEBUG
  std:: : cout << "Span assignment operator called" << std::endl;
#endif

  if (this != &rhs) {
    _Span = rhs._Span;
    _maxSize = rhs._maxSize;
  }
  return *this;
}

template <typename T> void Span<T>::addNumber(T n) {
  if (_Span.size() >= _maxSize)
    throw SpanFullException();
  try {
    _Span.push_back(n);
    std::sort(_Span.begin(), _Span.end());
  } catch (std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
  }
}

template <typename T> void Span<T>::addRange(const std::vector<T> &range) {
  for (const auto &i : range) {
    addNumber(i);
  }
}

template <typename T> T Span<T>::shortestSpan() {
  if (_Span.size() < 2)
    throw NoSpanException();

  T min = std::numeric_limits<T>::max();
  for (size_t i = 1; i < _Span.size(); i++) {
    T diff = _Span[i] - _Span[i - 1];
    if (diff < min)
      min = diff;
  }
  return min;
}

template <typename T> T Span<T>::longestSpan() {
  if (_Span.size() < 2)
    throw NoSpanException();
  T max = _Span.back() - _Span.front();
  return max;
}

template <typename T>
const char *Span<T>::SpanFullException::what() const noexcept {
  return "Span container is full";
}

template <typename T>
const char *Span<T>::NoSpanException::what() const noexcept {
  return "No span available, span needs at least two numbers.";
}

#endif
