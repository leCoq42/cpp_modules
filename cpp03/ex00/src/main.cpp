#include "ClapTrap.hpp"

void test_default_constructor(void) {
  ClapTrap clap_trap;

  clap_trap.attack("Martin");
  clap_trap.attack("Chav");
  clap_trap.attack("Lucien");
  clap_trap.takeDamage(5);
  clap_trap.beRepaired(1);
  clap_trap.beRepaired(10);
  clap_trap.attack("Victor");
  clap_trap.attack("Victor");
  clap_trap.attack("Victor");
  clap_trap.attack("Victor");
  clap_trap.attack("Victor");
  clap_trap.beRepaired(2); // Can be switched out for attack
  clap_trap.takeDamage(5);
  clap_trap.takeDamage(10);

  // show that it is dead
  clap_trap.takeDamage(10);
  clap_trap.attack("Show that it is dead");
  clap_trap.beRepaired(10);
}

void test_constructors(void) {
  ClapTrap martin("Martin");
  ClapTrap martin_copy(martin);
  ClapTrap default_claptrap;
  default_claptrap = martin;
}

int main(void) {
  std::cout << std::endl << "TEST default behaviour:" << std::endl;
  test_default_constructor();
  std::cout << std::endl << "TEST other constructors:" << std::endl;
  test_constructors();
  return (0);
}
