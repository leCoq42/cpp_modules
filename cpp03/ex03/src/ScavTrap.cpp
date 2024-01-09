#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Scav") {
  std::cout << "ScavTrap default constructor called!" << std::endl;

  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "ScavTrap constructor called!" << std::endl;

  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap destructor called!" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (_hitPoints <= 0) {
    std::cout << "ScavTrap " << _name << " is dead!" << std::endl;
  } else if (_energyPoints <= 0) {
    std::cout << "ScavTrap" << _name << " has no energy to attack!"
              << std::endl;
  } else {
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
              << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
  }
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode"
            << std::endl;
}
