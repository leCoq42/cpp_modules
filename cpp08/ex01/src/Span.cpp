#include "Span.hpp"
/* #include <algorithm> */
/* #include <limits> */
/**/
/* template <typename T> Span<T>::Span() : _maxSize(0) { */
/* #ifdef DEBUG */
/*   std::cout << "Span default constructor called" << std::endl; */
/* #endif */
/* } */
/**/
/* template <typename T> Span<T>::Span(unsigned int N) : _maxSize(N) { */
/* #ifdef DEBUG */
/*   std::cout << "Span parameterized constructor called" << std::endl; */
/* #endif */
/*   try { */
/*     _Span.reserve(N); */
/*   } catch (std::exception &e) { */
/*     std::cerr << e.what() << std::endl; */
/*   } */
/* } */
/**/
/* template <typename T> Span<T>::~Span() { */
/* #ifdef DEBUG */
/*   std::cout << "Span destructor called" << std::endl; */
/* #endif */
/* } */
/**/
/* template <typename T> Span<T>::Span(const Span<T> &src) { */
/* #ifdef DEBUG */
/*   std::cout << "Span copy constructor called" << std::endl; */
/* #endif */
/*   _Span = src._Span; */
/*   _maxSize = src._maxSize; */
/* } */
/**/
/* template <typename T> Span<T> &Span<T>::operator=(const Span<T> &rhs) {
 */
/*   if (this != &rhs) { */
/*     _Span = rhs._Span; */
/*     _maxSize = rhs._maxSize; */
/*   } */
/*   return *this; */
/* } */
/**/
/* template <typename T> void Span<T>::addNumber(T n) { */
/*   if (_Span.size() < _maxSize) { */
/*     _Span.push_back(n); */
/*     std::sort(_Span.begin(), _Span.end()); */
/*   } else */
/*     throw SpanFullException(); */
/* } */
/**/
/* template <typename T> T Span<T>::shortestSpan() { */
/*   if (_Span.size() < 2) */
/*     throw NoSpanException(); */
/**/
/*   T min = std::numeric_limits<T>::max(); */
/*   for (unsigned int i = 1; i < _Span.size(); i++) { */
/*     T diff = _Span[i] - _Span[i - 1]; */
/*     if (diff < min) */
/*       min = diff; */
/*   } */
/*   return min; */
/* } */
/**/
/* template <typename T> T Span<T>::longestSpan() { */
/*   if (_Span.size() < 2) */
/*     throw NoSpanException(); */
/*   T max = _Span.back() - _Span.front(); */
/*   return max; */
/* } */
