#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array {
public:
  Array<T>();
  Array<T>(size_t n);
  Array<T>(const Array<T> &src);

  ~Array<T>();

  Array<T> &operator=(const Array<T> &rhs);
  T &operator[](size_t i);

  size_t size() const;

  class OutOfRangeException : public std::exception {
  public:
    const char *what() const throw();
  };

private:
  T *_array;
  size_t _size;
};

template <typename T> Array<T>::Array() : _array(new T[0]), _size(0) {
  std::cout << "Array default constructor" << std::endl;
}

template <typename T>
Array<T>::Array(size_t size) : _array(new T[size]), _size(size) {
  std::cout << "Array parameterized constructor" << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T> &src) : _array(nullptr), _size(0) {
  std::cout << "Array copy constructor" << std::endl;
  *this = src;
}

template <typename T> Array<T>::~Array() { delete[] _array; }

template <typename T> Array<T> &Array<T>::operator=(Array<T> const &rhs) {
  if (this != &rhs) {
    delete[] _array;
    _array = new T[rhs.size()];
    _size = rhs.size();
    for (size_t i = 0; i < _size; i++) {
      _array[i] = rhs._array[i];
    }
  }
  return *this;
}

template <typename T> T &Array<T>::operator[](size_t i) {
  if (i >= _size) {
    throw Array::OutOfRangeException();
  }
  return _array[i];
}

template <typename T> size_t Array<T>::size() const { return (_size); }

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw() {
  return ("Index out of range");
}

#endif
