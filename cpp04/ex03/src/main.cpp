#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  src->learnMateria(nullptr);
  src->printMaterias();

  ICharacter *me = new Character("me");
  std::cout << "Character name = " << me->getName() << std::endl;

  AMateria *tmp;
  tmp = src->createMateria("ice");
  std::cout << "Created Materia: " << tmp->getType() << std::endl;
  me->equip(tmp);
  tmp = src->createMateria("cure");
  std::cout << "Created Materia: " << tmp->getType() << std::endl;
  me->equip(tmp);

  ICharacter *bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;
  return 0;
}
