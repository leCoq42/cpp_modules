#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Frag") {
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

void FragTrap::attack(const std::string &target) {
  if (_hitPoints <= 0) {
    std::cout << "FragTrap " << _name << " is dead!" << std::endl;
  } else if (_energyPoints <= 0) {
    std::cout << "FragTrap" << _name << " has no energy to attack!"
              << std::endl;
  } else {
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
              << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
  }
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap has requested a high five." << std::endl;
}
