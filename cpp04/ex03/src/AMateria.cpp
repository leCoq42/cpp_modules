#include "AMateria.hpp"

AMateria::AMateria() : _type("undefined") {
#ifdef DEBUG
  std::cout << "AMateria default constructor called." << std::endl;
#endif
}

AMateria::AMateria(std::string const &type) : _type(type) {
#ifdef DEBUG
  std::cout << "AMateria parameterized constructor called." << std::endl;
#endif
}

AMateria::~AMateria() {
#ifdef DEBUG
  std::cout << "AMateria destructor called." << std::endl;
#endif
}

std::string const &AMateria::getType() const { return _type; }

void AMateria::use(ICharacter &target) {
  (void)target;
  std::cout << "* Undefined Materia *" << std::endl;
}
