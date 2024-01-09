#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  ScavTrap();
  ScavTrap(std::string name);
  ~ScavTrap();

  virtual void attack(const std::string &target) override;
  void guardGate();
};

#endif
