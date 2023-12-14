#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL) {
  std::cout << "HumanB constructor called" << std::endl;
}

HumanB::~HumanB() { std::cout << "HumanB destructor called" << std::endl; }

void HumanB::attack() {
  if (!_weapon)
    std::cout << _name << " attacks with his bare hands!" << std::endl;
  else
    std::cout << _name << " attacks with his " << _weapon->getType()
              << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) { _weapon = &weapon; }
