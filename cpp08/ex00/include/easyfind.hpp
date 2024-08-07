#pragma once

#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
  return std::find(container.begin(), container.end(), value);
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
  return std::find(container.begin(), container.end(), value);
}
