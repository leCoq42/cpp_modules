#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void iter(T *array, size_t length, T (*func)(T)) {
  for (size_t i = 0; i < length; i++) {
    array[i] = func(array[i]);
  }
};

template <typename T> T power(T a) { return a * a; };

#endif
