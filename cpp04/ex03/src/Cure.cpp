#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
#ifdef DEBUG
  std::cout << "Cure default constructor called." << std::endl;
#endif
}

Cure::~Cure() {
#ifdef DEBUG
  std::cout << "Cure destructor called." << std::endl;
#endif
}

Cure::Cure(Cure const &src) : AMateria(src.getType()) {
#ifdef DEBUG
  std::cout << "Cure copy constructor called." << std::endl;
#endif

  *this = src;
}

Cure &Cure::operator=(Cure const &rhs) {
#ifdef DEBUG
  std::cout << "Cure assignment operator called." << std::endl;
#endif
  if (this != &rhs) {
    _type = rhs.getType();
  }
  return *this;
}

AMateria *Cure::clone() const { return new Cure(); }

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
