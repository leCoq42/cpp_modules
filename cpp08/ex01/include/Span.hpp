#pragma once

#include <iostream>
#include <vector>

class Span {
public:
  Span();
  Span(unsigned int N);
  Span(const Span &src);
  Span &operator=(const Span &rhs);
  ~Span();

  void addNumber(int n);
  void addRange(const std::vector<int> &range);
  size_t shortestSpan();
  size_t longestSpan();

  class SpanFullException : public std::exception {
  public:
    virtual const char *what() const noexcept override;
  };

  class NoSpanException : public std::exception {
  public:
    virtual const char *what() const noexcept override;
  };

private:
  std::vector<int> _span;
  unsigned int _maxSize;
};
