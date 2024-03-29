#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &copy);
  ClapTrap &operator=(const ClapTrap &src);
  ~ClapTrap();

  virtual void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  std::string getName() const;
  int getHitPoints() const;
  int getEnergyPoints() const;
  int getDamage() const;

protected:
  std::string _Name;
  int _hitPoints;
  int _energyPoints;
  int _attackDamage;
};

#endif
