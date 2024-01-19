#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
  std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal::Animal(const Animal &src) {
  std::cout << "Animal copy constructor called!";

  *this = src;
}

Animal &Animal::operator=(const Animal &src) {
  std::cout << "Animal assignment operator called!";

  if (this != &src) {
    this->_type = src._type;
  }
  return *this;
}

std::string Animal::getType() const { return _type; }

void Animal::makeSound() const {
  std::cout << "An unidentifiable Animal sound!" << std::endl;
}
