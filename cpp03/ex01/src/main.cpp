#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  // Test ClapTrap default constructor
  ClapTrap clap1;
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

  // Test ClapTrap constructor
  ClapTrap clap2("Clap2");
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

  // Test ScavTrap default constructor
  ScavTrap scav1;
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

  // Test ScavTrap constructor
  ScavTrap scav2("Scav2");
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
}
