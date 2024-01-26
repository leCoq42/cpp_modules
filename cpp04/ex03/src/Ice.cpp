#include "Ice.hpp"
#include "Character.hpp"

Ice::Ice() : AMateria("ice") {
#ifdef DEBUG
  std::cout << "Ice default constructor called." << std::endl;
#endif
}

Ice::~Ice() {
#ifdef DEBUG
  std::cout << "Ice destructor called." << std::endl;
#endif
}

Ice::Ice(Ice const &src) : AMateria(src.getType()) {
#ifdef DEBUG
  std::cout << "Ice copy constructor called." << std::endl;
#endif
  *this = src;
}

Ice &Ice::operator=(Ice const &rhs) {
#ifdef DEBUG
  std::cout << "Ice assignment operator called." << std::endl;
#endif

  if (this != &rhs) {
    _type = rhs.getType();
  }
  return *this;
}

AMateria *Ice::clone() const { return new Ice(); }

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
