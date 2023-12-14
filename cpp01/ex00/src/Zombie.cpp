#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
  std::cout << this->name << " created." << std::endl;
}

Zombie::~Zombie() { std::cout << this->name << " destroyed." << std::endl; }

void Zombie::announce(void) {
  std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
