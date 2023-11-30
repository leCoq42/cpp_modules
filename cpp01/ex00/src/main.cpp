#include "Zombie.hpp"

int main(void) {
  Zombie *zombie = newZombie("Zombie");
  randomChump("Chumpy");
  zombie->announce();
  delete zombie;
  return 0;
}
