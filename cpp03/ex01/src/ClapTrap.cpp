#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _Name("ClapTrap"), _Hitpoints(10), _EnergyPoints(10), _AttackDamage(0) {
  std::cout << "ClapTrap default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _Name(name), _Hitpoints(10), _EnergyPoints(10), _AttackDamage(0) {
  std::cout << "ClapTrap constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
  std::cout << "ClapTrap copy constructor called!" << std::endl;
  *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
  std::cout << "ClapTrap assignment operator called!" << std::endl;

  if (this != &src) {
    _Name = src._Name;
    _Hitpoints = src._Hitpoints;
    _EnergyPoints = src._EnergyPoints;
    _AttackDamage = src._AttackDamage;
  }
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor called!" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
  if (_Hitpoints <= 0) {
    std::cout << "ClapTrap " << _Name << " is dead!" << std::endl;
  } else if (_EnergyPoints <= 0) {
    std::cout << "ClapTrap " << _Name << " has no energy to attack!"
              << std::endl;
  } else {
    std::cout << "ClapTrap " << _Name << " attacks " << target << ", causing "
              << _AttackDamage << " points of damage!" << std::endl;
    _EnergyPoints--;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  _Hitpoints -= amount;
  std::cout << "ClapTrap " << _Name << " takes " << amount
            << " points of damage!" << std::endl;

  if (_Hitpoints <= 0)
    std::cout << "ClapTrap " << _Name << " has died!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_Hitpoints <= 0) {
    std::cout << "ClapTrap " << _Name << " is dead!" << std::endl;
  } else if (_EnergyPoints <= 0) {
    std::cout << "ClapTrap " << _Name << " has no energy to repair itself!"
              << std::endl;
  } else {
    std::cout << "ClapTrap repairs itself, it recovered " << amount
              << " hitpoints!" << std::endl;
    _EnergyPoints--;
    _Hitpoints += amount;
  }
}
