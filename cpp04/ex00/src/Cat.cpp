#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat default constructor called" << std::endl;
  _type = "Cat";
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

Cat::Cat(const Cat &src) : Animal("Cat") {
  std::cout << "Cat copy constructor called!";
  *this = src;
}

Cat &Cat::operator=(const Cat &src) {
  std::cout << "Animal assignment operator called!";
  if (this != &src) {
    _type = src._type;
  }
  return *this;
}

void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }
