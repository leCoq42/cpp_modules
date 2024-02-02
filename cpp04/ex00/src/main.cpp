#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define MSG_BORDER "=------------------------------------------------------="

int main(void) {
  const Animal *meta = new Animal();
  const Animal *i = new Cat();
  const Animal *j = new Dog();
  std::cout << meta->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  std::cout << j->getType() << " " << std::endl;
  meta->makeSound();
  i->makeSound(); // will output the cat sound!
  j->makeSound();

  std::cout << MSG_BORDER << std::endl;

  // test wrong anial/cat classes
  const WrongAnimal *wa = new WrongAnimal();
  const WrongAnimal *wc = new WrongCat();
  std::cout << "wa type: " << wa->getType() << std::endl;
  std::cout << "wc type: " << wc->getType() << std::endl;
  wa->makeSound();
  wc->makeSound(); // will output the wrongAnimal sound!

  std::cout << MSG_BORDER << std::endl;

  delete wc;
  delete wa;
  delete i;
  delete j;
  delete meta;

  return 0;
}
