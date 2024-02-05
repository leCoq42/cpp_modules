#include "Animal.hpp"

A_Animal::A_Animal() : _type("Animal") {
  std::cout << "Animal default constructor called" << std::endl;
}

A_Animal::A_Animal(std::string type) : _type(type) {
  std::cout << "Animal constructor called" << std::endl;
}

A_Animal::~A_Animal() { std::cout << "Animal destructor called" << std::endl; }

A_Animal::A_Animal(const A_Animal &src) {
  std::cout << "Animal copy constructor called!";
  *this = src;
}

A_Animal &A_Animal::operator=(const A_Animal &src) {
  std::cout << "Animal assignment operator called!";
  if (this != &src) {
    this->_type = src._type;
  }
  return *this;
}

std::string A_Animal::getType() const { return _type; }
