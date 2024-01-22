#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type) {
#ifdef DEBUG
  std::cout << "AMateria parameterized constructor called." << std::endl;
#endif
}

std::string const &AMateria::getType() const { return _type; }

void AMateria::use(ICharacter &target) {
  (void)target;
  std::cout << "* Undefined Materia *" << std::endl;
}
