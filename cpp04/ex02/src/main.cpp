#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

#define MSG_BORDER "=------------------------------------------------------="

int main() {
  std::cout << std::endl << MSG_BORDER << std::endl << std::endl;

  const A_Animal *x = new Dog();
  const A_Animal *y = new Cat();
  /* const A_Animal *z = new A_Animal(); */
  delete x;
  delete y; // should not create a leak
  /* delete z; */

  std::cout << std::endl << MSG_BORDER << std::endl << std::endl;
  return 0;
}
