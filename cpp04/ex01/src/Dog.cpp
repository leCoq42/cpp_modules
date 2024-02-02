#include "Dog.hpp"

Dog::Dog() : _brain(new Brain()) {
  std::cout << "Dog default constructor called" << std::endl;

  _type = "Dog";
}

Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;

  if (_brain != nullptr)
    delete _brain;
}

Dog::Dog(const Dog &src) : Animal(), _brain(new Brain(*src._brain)) {
  std::cout << "Dog copy constructor called!" << std::endl;

  _type = src._type;
  *this = src;
}

Dog &Dog::operator=(const Dog &rhs) {
  std::cout << "Dog assignment operator called!" << std::endl;

  if (this != &rhs) {
    _type = rhs._type;
    delete _brain;
    _brain = new Brain(*rhs._brain);
  }
  return *this;
}

void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }

std::string Dog::getIdea(int i) const { return (_brain->getIdea(i)); }

void Dog::setIdea(const std::string idea) { _brain->setIdea(idea); }

int Dog::getIdeaCount() const { return (_brain->getIdeaCount()); }
