#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  // Test default constructors
  ClapTrap clap1;
  ScavTrap scav1;
  FragTrap frag1;
  DiamondTrap diamond1;

  // Test named constructors
  ClapTrap clap2("Clap2");
  ScavTrap scav2("Scav2");
  FragTrap frag2("Frag2");
  DiamondTrap diamond2("Diamond2");
  std::cout << std::endl;

  // Test ClapTrap member functions
  std::cout << "Name: " << clap1.getName() << std::endl;
  std::cout << "HP: " << clap1.getHitPoints() << std::endl;
  std::cout << "EP: " << clap1.getEnergyPoints() << std::endl;
  std::cout << "DMG: " << clap1.getDamage() << std::endl;
  clap1.attack("enemy");
  clap1.beRepaired(20);
  clap1.takeDamage(10);
  std::cout << "HP: " << clap1.getHitPoints() << std::endl;
  std::cout << "EP: " << clap1.getEnergyPoints() << std::endl;
  std::cout << "DMG: " << clap1.getDamage() << std::endl << std::endl;

  // Test ClapTrap member functions
  std::cout << "Name: " << clap2.getName() << std::endl;
  std::cout << "HP: " << clap2.getHitPoints() << std::endl;
  std::cout << "EP: " << clap2.getEnergyPoints() << std::endl;
  std::cout << "DMG: " << clap2.getDamage() << std::endl;
  clap2.attack("enemy");
  clap2.beRepaired(20);
  clap2.takeDamage(10);
  std::cout << "HP: " << clap2.getHitPoints() << std::endl;
  std::cout << "EP: " << clap2.getEnergyPoints() << std::endl;
  std::cout << "DMG: " << clap2.getDamage() << std::endl << std::endl;

  // Test ScavTrap member functions
  std::cout << "Name: " << scav1.getName() << std::endl;
  std::cout << "HP: " << scav1.getHitPoints() << std::endl;
  std::cout << "EP: " << scav1.getEnergyPoints() << std::endl;
  std::cout << "DMG: " << scav1.getDamage() << std::endl;
  scav1.attack("enemy");
  scav1.beRepaired(20);
  scav1.takeDamage(10);
  scav1.guardGate();
  std::cout << "HP: " << scav1.getHitPoints() << std::endl;
  std::cout << "EP: " << scav1.getEnergyPoints() << std::endl;
  std::cout << "DMG: " << scav1.getDamage() << std::endl << std::endl;

  // Test ScavTrap member functions
  std::cout << "Name: " << scav2.getName() << std::endl;
  std::cout << "HP: " << scav2.getHitPoints() << std::endl;
  std::cout << "EP: " << scav2.getEnergyPoints() << std::endl;
  std::cout << "DMG: " << scav2.getDamage() << std::endl;
  scav2.attack("enemy");
  scav2.beRepaired(20);
  scav2.takeDamage(10);
  scav2.guardGate();
  std::cout << "HP: " << scav2.getHitPoints() << std::endl;
  std::cout << "EP: " << scav2.getEnergyPoints() << std::endl;
  std::cout << "DMG: " << scav2.getDamage() << std::endl << std::endl;

  // Test FragTrap member functions
  std::cout << "Name: " << frag1.getName() << std::endl;
  std::cout << "HP: " << frag1.getHitPoints() << std::endl;
  std::cout << "EP: " << frag1.getEnergyPoints() << std::endl;
  std::cout << "DMG: " << frag1.getDamage() << std::endl;
  frag1.attack("enemy");
  frag1.beRepaired(20);
  frag1.takeDamage(10);
  frag1.highFivesGuys();
  std::cout << "HP: " << frag1.getHitPoints() << std::endl;
  std::cout << "EP: " << frag1.getEnergyPoints() << std::endl;
  std::cout << "DMG: " << frag1.getDamage() << std::endl << std::endl;

  // Test FragTrap member functions
  std::cout << "Name: " << frag2.getName() << std::endl;
  std::cout << "HP: " << frag2.getHitPoints() << std::endl;
  std::cout << "EP: " << frag2.getEnergyPoints() << std::endl;
  std::cout << "DMG: " << frag2.getDamage() << std::endl;
  frag2.attack("enemy");
  frag2.beRepaired(20);
  frag2.takeDamage(10);
  frag2.highFivesGuys();
  std::cout << "HP: " << frag2.getHitPoints() << std::endl;
  std::cout << "EP: " << frag2.getEnergyPoints() << std::endl;
  std::cout << "DMG: " << frag2.getDamage() << std::endl << std::endl;

  // Test DiamondTrap member functions
  std::cout << "Name: " << diamond1.getName() << std::endl;
  std::cout << "HP: " << diamond1.getHitPoints() << std::endl;
  std::cout << "EP: " << diamond1.getEnergyPoints() << std::endl;
  std::cout << "DMG: " << diamond1.getDamage() << std::endl;
  diamond1.attack("enemy");
  diamond1.beRepaired(20);
  diamond1.takeDamage(10);
  diamond1.whoAmI();
  std::cout << "HP: " << diamond1.getHitPoints() << std::endl;
  std::cout << "EP: " << diamond1.getEnergyPoints() << std::endl;
  std::cout << "DMG: " << diamond1.getDamage() << std::endl << std::endl;

  // Test DiamondTrap member functions
  std::cout << "Name: " << diamond2.getName() << std::endl;
  std::cout << "HP: " << diamond2.getHitPoints() << std::endl;
  std::cout << "EP: " << diamond2.getEnergyPoints() << std::endl;
  std::cout << "DMG: " << diamond2.getDamage() << std::endl;
  diamond2.attack("enemy");
  diamond2.beRepaired(20);
  diamond2.takeDamage(10);
  diamond2.whoAmI();
  std::cout << "HP: " << diamond2.getHitPoints() << std::endl;
  std::cout << "EP: " << diamond2.getEnergyPoints() << std::endl;
  std::cout << "DMG: " << diamond2.getDamage() << std::endl << std::endl;
}
