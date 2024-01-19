#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << "WrongCat default constructor called" << std::endl;
  _type = "WrongCat";
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal("WrongCat") {
  std::cout << "WrongCat copy constructor called!";
  *this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src) {
  std::cout << "WrongAnimal assignment operator called!";
  if (this != &src) {
    _type = src._type;
  }
  return *this;
}

void WrongCat::makeSound() const { std::cout << "Meow!" << std::endl; }
