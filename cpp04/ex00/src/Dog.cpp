#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog default constructor called" << std::endl;

  _type = "Dog";
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog::Dog(const Dog &src) : Animal("Dog") {
  std::cout << "Dog copy constructor called!";

  *this = src;
}

Dog &Dog::operator=(const Dog &src) {
  std::cout << "Animal assignment operator called!";

  if (this != &src) {
    _type = src._type;
  }
  return *this;
}

void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }
