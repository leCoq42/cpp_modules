#include "Cat.hpp"

#include <iostream>

Cat::Cat() : _brain(new Brain()) {
  std::cout << "Cat default constructor called" << std::endl;

  _type = "Cat";
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;

  if (_brain != nullptr)
    delete _brain;
}

Cat::Cat(const Cat &src) : Animal(), _brain(new Brain(*src._brain)) {
  std::cout << "Cat copy constructor called!" << std::endl;

  _type = src._type;
  *this = src;
}

Cat &Cat::operator=(const Cat &rhs) {
  std::cout << "Cat assignment operator called!" << std::endl;

  if (this != &rhs) {
    _type = rhs._type;
    delete _brain;
    _brain = new Brain(*rhs._brain);
  }
  return *this;
}

void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }

std::string Cat::getIdea(int i) const { return (_brain->getIdea(i)); }

void Cat::setIdea(const std::string idea) { _brain->setIdea(idea); }

int Cat::getIdeaCount() const { return (_brain->getIdeaCount()); }
