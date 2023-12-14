#include "Zombie.hpp"

Zombie::Zombie() { std::cout << "Default constructor called!" << std::endl; }

Zombie::Zombie(std::string name) : name(name) {
  std::cout << this->name << " constructor called!" << std::endl;
}

Zombie::~Zombie() {
  std::cout << this->name << " destructor called!" << std::endl;
}

void Zombie::announce(void) {
  std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
  this->name = name;
  std::cout << "Name set to: " << this->name << std::endl;
}
