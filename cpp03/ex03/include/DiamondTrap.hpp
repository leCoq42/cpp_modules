#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
  DiamondTrap();
  DiamondTrap(std::string name);
  ~DiamondTrap();

  using ScavTrap::attack;

  void whoAmI();

private:
  std::string _name;
};

#endif
