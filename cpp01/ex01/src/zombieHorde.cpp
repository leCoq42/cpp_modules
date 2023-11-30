#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
  Zombie *zombieHorde = new Zombie[N];
  Zombie tmpZombie = Zombie(name);

  for (int i = 0; i < N; i++) {
    zombieHorde[i] = tmpZombie;
  }
  return zombieHorde;
}
