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

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

private:
  std::string _Name;
  int _Hitpoints;
  int _EnergyPoints;
  int _AttackDamage;
};

#endif
