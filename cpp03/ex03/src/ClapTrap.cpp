#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("Clap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
  std::cout << "ClapTrap copy constructor called!" << std::endl;
  *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
  std::cout << "ClapTrap assignment operator called!" << std::endl;

  if (this != &src) {
    _name = src._name;
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
    std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
  } else if (_energyPoints <= 0) {
    std::cout << "ClapTrap " << _name << " has no energy to attack!"
              << std::endl;
  } else {
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
              << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  _hitPoints -= amount;
  std::cout << "ClapTrap " << _name << " takes " << amount
            << " points of damage!" << std::endl;

  if (_hitPoints <= 0)
    std::cout << "ClapTrap " << _name << " has died!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hitPoints <= 0) {
    std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
  } else if (_energyPoints <= 0) {
    std::cout << "ClapTrap " << _name << " has no energy to repair itself!"
              << std::endl;
  } else {
    std::cout << "ClapTrap repairs itself, it recovered " << amount
              << " hitpoints!" << std::endl;
    _energyPoints--;
    _hitPoints += amount;
  }
}

std::string ClapTrap::getName() const { return _name; }
int ClapTrap::getHitPoints() const { return _hitPoints; }
int ClapTrap::getEnergyPoints() const { return _energyPoints; }
int ClapTrap::getDamage() const { return _attackDamage; }
