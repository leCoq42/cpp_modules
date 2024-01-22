#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
public:
  Character();
  ~Character();
  Character(std::string const &name);

  std::string const &getName() const;
  Character(Character const &src);
  Character &operator=(const Character &rhs);

  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

private:
  AMateria *_inventory[4];
  std::string _name;
  int _freeSlots;
};

#endif
