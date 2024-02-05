#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
  MateriaSource src;
  src.learnMateria(new Ice());
  src.learnMateria(new Cure());
  src.learnMateria(new Ice());
  src.learnMateria(new Cure());
  src.learnMateria(new Ice());
  src.learnMateria(nullptr);
  src.printMaterias();

  Character me;
  std::cout << "Character name = " << me.getName() << std::endl;

  AMateria *tmp;
  tmp = src.createMateria("ice");
  std::cout << "Created Materia: " << tmp->getType() << std::endl;
  me.equip(tmp);
  tmp = src.createMateria("cure");
  std::cout << "Created Materia: " << tmp->getType() << std::endl;
  me.equip(tmp);
  tmp = src.createMateria("ice");
  std::cout << "Created Materia: " << tmp->getType() << std::endl;
  me.equip(tmp);
  tmp = src.createMateria("cure");
  std::cout << "Created Materia: " << tmp->getType() << std::endl;
  me.equip(tmp);
  tmp = src.createMateria("ice");
  std::cout << "Created Materia: " << tmp->getType() << std::endl;
  me.equip(tmp);

  AMateria *tmp2 = me.getMateria(1);
  me.unequip(1);

  Character bob;

  me.use(0, bob);
  me.use(3, bob);
  me.use(1, bob);

  delete tmp2;
  return 0;
}
