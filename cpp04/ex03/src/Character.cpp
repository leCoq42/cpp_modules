#include "Character.hpp"

Character::Character() : _name("default") {
#ifdef DEBUG
  std::cout << "Character default constructor called." << std::endl;
#endif
  for (int i = 0; i < 4; i++) {
    _inventory[i] = nullptr;
  }
}

Character::~Character() {
#ifdef DEBUG
  std::cout << "Character destructor called." << std::endl;
#endif
}

Character::Character(std::string const &name) : _name(name) {
#ifdef DEBUG
  std::cout << "Character parameterized constructor called." << std::endl;
#endif
  for (int i = 0; i < 4; i++) {
    _inventory[i] = nullptr;
  }
}

Character::Character(Character const &src) {
#ifdef DEBUG
  std::cout << "Character copy constructor called." << std::endl;
#endif

  *this = src;
};

Character &Character::operator=(const Character &rhs) {
#ifdef DEBUG
  std::cout << "Character assignment operator called." << std::endl;
#endif

  if (this != &rhs) {
    _name = rhs.getName();
    for (int i = 0; i < 4; i++) {
      _inventory[i] = rhs._inventory[i];
    }
  }
  return *this;
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria *m) {
  if (_freeSlots == 0 || m == nullptr) {
    return;
  }
  for (int i = 0; i < 4; i++) {
    if (_inventory[i] == nullptr) {
      _inventory[i] = m;
      break;
    }
  }
}

void Character::unequip(int idx) { _inventory[idx] = nullptr; }

void Character::use(int idx, ICharacter &target) {
  if (_inventory[idx] != nullptr) {
    _inventory[idx]->use(target);
  }
}
