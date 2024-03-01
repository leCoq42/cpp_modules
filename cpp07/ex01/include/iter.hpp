#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void iter(T *array, T length, void (*f)(T &)) {
  for (T i = 0; i < length; ++i) {
    f(array[i]);
  }
};

#endif
