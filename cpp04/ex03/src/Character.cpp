#include "Character.hpp"

Character::Character() : _name("default") {
#ifdef DEBUG
  std::cout << "Character default constructor called." << std::endl;
#endif
  for (int i = 0; i < INVENTORY_SIZE; i++) {
    _inventory[i] = nullptr;
  }
}

Character::Character(std::string const &name) : _name(name) {
#ifdef DEBUG
  std::cout << "Character parameterized constructor called." << std::endl;
#endif
  for (int i = 0; i < INVENTORY_SIZE; i++) {
    _inventory[i] = nullptr;
  }
}

Character::~Character() {
#ifdef DEBUG
  std::cout << "Character destructor called." << std::endl;
#endif
  for (int i = 0; i < INVENTORY_SIZE; i++) {
    if (_inventory[i] != nullptr)
      delete _inventory[i];
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
    for (int i = 0; i < INVENTORY_SIZE; i++) {
      _inventory[i] = rhs._inventory[i];
    }
  }
  return *this;
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria *m) {
  if (m == nullptr) {
    std::cout << "Character: Cannot equip a void Materia." << std::endl;
    return;
  }
  for (int i = 0; i < INVENTORY_SIZE; i++) {
    if (i == INVENTORY_SIZE - 1 && _inventory[i] != nullptr) {
      std::cout << "Character: Inventory full!" << std::endl;
      delete m;
      break;
    } else if (_inventory[i] == nullptr) {
      _inventory[i] = m;
      std::cout << "Equipped Materia: " << m->getType() << std::endl;
      break;
    }
  }
}

AMateria *Character::getMateria(int idx) const {
  if (idx < 0 || idx >= INVENTORY_SIZE) {
    std::cout << "Character: Cannot get materia, invalid index!" << std::endl;
    return nullptr;
  }
  return _inventory[idx];
}

void Character::unequip(int idx) {
  if (idx < 0 || idx > INVENTORY_SIZE - 1) {
    std::cout << "Character: Cannot unequip, invalid index!" << std::endl;
    return;
  }
  _inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target) {
  if (idx < 0 || idx > INVENTORY_SIZE - 1) {
    std::cout << "Character: invalid index!" << std::endl;
    return;
  }
  if (_inventory[idx] != nullptr)
    _inventory[idx]->use(target);
  else
    std::cout << "Character: No materia equipped at index " << idx << "."
              << std::endl;
}
