#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type) {
  std::cout << "Weapon constructor called" << std::endl;
}

Weapon::~Weapon() { std::cout << "Weapon destructor called!" << std::endl; }

const std::string &Weapon::getType() { return (_type); }

void Weapon::setType(const std::string &type) { _type = type; }
