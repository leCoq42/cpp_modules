#include "Span.hpp"
#include <algorithm>
#include <cstddef>
#include <limits>

Span::Span() : _maxSize(0) {
#ifdef DEBUG
  std::cout << "Span default constructor called" << std::endl;
#endif
}

Span::Span(unsigned int N) : _maxSize(N) {
#ifdef DEBUG
  std::cout << "Span parameterized constructor called" << std::endl;
#endif
  try {
    _span.reserve(N);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "capacity: " << _span.capacity() << std::endl;
}

Span::~Span() {
#ifdef DEBUG
  std::cout << "Span destructor called" << std::endl;
#endif
}

Span::Span(const Span &src) {
#ifdef DEBUG
  std::cout << "Span copy constructor called" << std::endl;
#endif

  _span = src._span;
  _maxSize = src._maxSize;
}

Span &Span::operator=(const Span &rhs) {
#ifdef DEBUG
  std:: : cout << "Span assignment operator called" << std::endl;
#endif

  if (this != &rhs) {
    _span = rhs._span;
    _maxSize = rhs._maxSize;
  }
  return *this;
}

void Span::addNumber(int n) {
  if (_span.size() >= _maxSize)
    throw SpanFullException();
  try {
    _span.push_back(n);
    std::sort(_span.begin(), _span.end());
  } catch (std::invalid_argument &e) {
    std::cerr << e.what() << std::endl;
  }
}

void Span::addRange(const std::vector<int> &range) {
  for (const auto &i : range) {
    addNumber(i);
  }
}

size_t Span::shortestSpan() {
  if (_span.size() < 2)
    throw NoSpanException();

  std::sort(_span.begin(), _span.end());
  size_t min = std::numeric_limits<int>::max();
  for (size_t i = 1; i < _span.size(); i++) {
    size_t diff = _span[i] - _span[i - 1];
    if (diff < min)
      min = diff;
  }
  return min;
}

size_t Span::longestSpan() {
  if (_span.size() < 2)
    throw NoSpanException();

  std::sort(_span.begin(), _span.end());
  size_t max = _span.back() - _span.front();
  return max;
}

const char *Span::SpanFullException::what() const noexcept {
  return "Span container is full";
}

const char *Span::NoSpanException::what() const noexcept {
  return "No span available, span needs at least two numbers.";
}
