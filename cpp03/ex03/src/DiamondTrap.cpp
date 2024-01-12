#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("Diamond_clap_name"), ScavTrap("Diamond"), FragTrap("Diamond") {
  std::cout << "DiamondTrap default constructor called!" << std::endl;

  _name = "Diamond";
  FragTrap::_hitPoints = 100;
  ScavTrap::_energyPoints = 50;
  FragTrap::_attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
  std::cout << "DiamondTrap constructor called!" << std::endl;

  _name = name;
  FragTrap::_hitPoints = 100;
  ScavTrap::_energyPoints = 50;
  FragTrap::_attackDamage = 30;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap destructor called!" << std::endl;
}

void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap name: " << _name << std::endl;
  std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
