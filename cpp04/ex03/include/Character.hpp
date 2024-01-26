#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define INVENTORY_SIZE 4

class Character : public ICharacter {
public:
  Character();
  ~Character();
  Character(std::string const &name);

  std::string const &getName() const;
  AMateria *getMateria(int idx) const;
  Character(Character const &src);
  Character &operator=(const Character &rhs);

  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

private:
  AMateria *_inventory[INVENTORY_SIZE];
  std::string _name;
};

#endif
