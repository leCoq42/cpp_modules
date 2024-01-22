#include "Cat.hpp"

Cat::Cat() : A_Animal("Cat"), _brain(new Brain()) {
  std::cout << "Cat default constructor called" << std::endl;

  _type = "Cat";
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;

  if (_brain != nullptr)
    delete _brain;
}

Cat::Cat(const Cat &src) : A_Animal("Cat"), _brain(new Brain(*src._brain)) {
  std::cout << "Cat copy constructor called!" << std::endl;

  _type = src._type;
  *this = src;
}

Cat &Cat::operator=(const Cat &src) {
  std::cout << "Cat assignment operator called!" << std::endl;

  if (this != &src) {
    _type = src._type;
    delete _brain;
    _brain = new Brain(*src._brain);
  }
  return *this;
}

void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }

std::string Cat::getIdea(int i) const { return (_brain->getIdea(i)); }

void Cat::setIdea(const std::string idea) { _brain->setIdea(idea); }

int Cat::getIdeaCount() const { return (_brain->getIdeaCount()); }
