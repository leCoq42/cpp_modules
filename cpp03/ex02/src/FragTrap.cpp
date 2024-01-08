#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap") {
  std::cout << "FragTrap default constructor called!" << std::endl;

  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  std::cout << "FragTrap constructor called!" << std::endl;

  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called!" << std::endl;
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap has requested a high five." << std::endl;
}
