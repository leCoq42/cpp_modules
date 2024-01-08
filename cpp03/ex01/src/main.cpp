#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void test_default_constructor(void) {
  ClapTrap clap1;
  ScavTrap scav;

  clap1.attack("Martin");
  clap1.beRepaired(10);

  scav.guardGate();
  for (int i = 0; i < 60; i++) {
    scav.attack("Martin");
    scav.beRepaired(1);
    std::cout << "hp = " << scav.getHitpoints() << std::endl;
  }

  for (int i = 0; i < 10; i++)
    scav.takeDamage(10);

  scav.attack("Martin");
  clap1.beRepaired(10);
}

void test_constructors(void) {
  ClapTrap martin("Martin");
  ClapTrap martin_copy(martin);

  ScavTrap scav("Chav");
  ScavTrap scav_copy(scav);
}

int main(void) {
  std::cout << std::endl << "TEST default behaviour:" << std::endl;
  test_default_constructor();
  std::cout << std::endl << "TEST other constructors:" << std::endl;
  test_constructors();
  return (0);
}
