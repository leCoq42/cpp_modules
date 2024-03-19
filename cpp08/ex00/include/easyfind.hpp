#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>

class NotFoundException : public std::exception {
public:
  virtual const char *what() const throw() { return ("Value not found."); }
};

template <typename T> int easyfind(T &container, int value) {
  typename T::iterator ret;
  ret = std::find(container.begin(), container.end(), value);
  if (ret == container.end())
    throw NotFoundException();
  return std::distance(container.begin(), ret);
}

#endif
