#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _Name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _Name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
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
    _hitPoints = src._hitPoints;
    _energyPoints = src._energyPoints;
    _attackDamage = src._attackDamage;
  }
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor called!" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
  if (_hitPoints <= 0) {
    std::cout << "ClapTrap " << _Name << " is dead!" << std::endl;
  } else if (_energyPoints <= 0) {
    std::cout << "ClapTrap " << _Name << " has no energy to attack!"
              << std::endl;
  } else {
    std::cout << "ClapTrap " << _Name << " attacks " << target << ", causing "
              << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  _hitPoints -= amount;
  std::cout << "ClapTrap " << _Name << " takes " << amount
            << " points of damage!" << std::endl;

  if (_hitPoints <= 0)
    std::cout << "ClapTrap " << _Name << " has died!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hitPoints <= 0) {
    std::cout << "ClapTrap " << _Name << " is dead!" << std::endl;
  } else if (_energyPoints <= 0) {
    std::cout << "ClapTrap " << _Name << " has no energy to repair itself!"
              << std::endl;
  } else {
    std::cout << "ClapTrap repairs itself, it recovered " << amount
              << " hitpoints!" << std::endl;
    _energyPoints--;
    _hitPoints += amount;
  }
}
