#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

#define MSG_BORDER "=------------------------------------------------------="

int main() {
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  delete j; // should not create a leak
  delete i;

  std::cout << std::endl << MSG_BORDER << std::endl << std::endl;

  Animal *animals[10];
  for (int i = 0; i < 4; i++) {
    if (i < 5) {
      animals[i] = new Dog();
    } else {
      animals[i] = new Cat();
    }
  }

  std::cout << std::endl << MSG_BORDER << std::endl << std::endl;

  for (int i = 0; i < 4; i++) {
    delete animals[i];
  }

  std::cout << std::endl << MSG_BORDER << std::endl << std::endl;

  Cat *cat = new Cat();
  cat->setIdea("I am a cat!");
  Cat *clone = new Cat(*cat);
  std::cout << "My idea was: " << clone->getIdea(0) << std::endl;
  std::cout << "Cat idea count = " << cat->getIdeaCount() << std::endl;
  std::cout << "Clone idea count = " << clone->getIdeaCount() << std::endl;
  cat->setIdea("I love fish!");
  std::cout << "Cat idea count = " << cat->getIdeaCount() << std::endl;
  std::cout << "Clone idea count = " << clone->getIdeaCount() << std::endl;
  std::cout << "My idea new idea is: " << clone->getIdea(1) << std::endl;

  delete cat;
  delete clone;

  std::cout << std::endl << MSG_BORDER << std::endl << std::endl;
  return 0;
}
