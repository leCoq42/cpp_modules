#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array<T> {
public:
  Array() : _array(new T[0]){};
  Array(unsigned int n) : _array(new T[n]){};
  ~Array() { delete[] _array; }

  size_t size() const { return sizeof(_array); };

private:
  int *_array;
};

#endif
