#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap") {
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

void ScavTrap::guardGate() {
  std::cout << "ScavTrap has entered in Gate keeper mode" << std::endl;
}

int ScavTrap::getHitpoints() { return _hitPoints; }
