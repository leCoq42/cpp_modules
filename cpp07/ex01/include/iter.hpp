#pragma once

#include <iostream>
#include <functional>

template <typename T, typename Func>
void iter(T *array, size_t length, const  Func f) {
  for (size_t i = 0; i < length; i++) {
    f(array[i]);
  }
}

template <typename T>
void power(T &x) { x *= x; };

template <typename T>
void print(T &x) { std::cout << x << std::endl; }
