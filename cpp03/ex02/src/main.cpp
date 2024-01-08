#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  ClapTrap clapTrap("Clap");
  std::cout << std::endl;

  ScavTrap scavTrap("Scav");
  std::cout << std::endl;

  FragTrap fragTrap("Frag");
  std::cout << std::endl;

  ClapTrap ct;
  std::cout << std::endl;

  ScavTrap st;
  std::cout << std::endl;

  FragTrap ft;
  std::cout << std::endl;

  return (0);
}
