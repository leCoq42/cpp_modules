#pragma once

#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  typedef typename std::deque<T>::iterator iterator;
  iterator begin();
  iterator end();
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
  return this->c.begin();
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end() {
  return this->c.end();
}
