#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
  std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
  std::cout << "WrongAnimal copy constructor called!";
  *this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {
  std::cout << "WrongAnimal assignment operator called!";
  if (this != &src) {
    this->_type = src._type;
  }
  return *this;
}

std::string WrongAnimal::getType() const { return _type; }

void WrongAnimal::makeSound() const {
  std::cout << "This " << getType() << " sounds wrong!" << std::endl;
}
