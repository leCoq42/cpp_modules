#pragma once

#include <iostream>
#include <functional>

// void iter(T *array, size_t length, void(*f)(T&)) {
template <typename T>
void iter(T *array, size_t length, const  std::function<void(T&)>&f) {
  for (size_t i = 0; i < length; i++) {
    f(array[i]);
  }
}

template <typename T>
void power(T &x) { x *= x; };

template <typename T>
void print(T &x) { std::cout << x << std::endl; }
