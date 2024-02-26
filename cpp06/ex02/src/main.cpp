#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

#include <unistd.h>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main(void) {
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
    std::cout << std::endl;
  }
}

Base *generate(void) {
  switch (rand() % 3) {
  case (0):
    std::cout << "A generated!" << std::endl;
    return new A();
  case (1):
    std::cout << "B generated!" << std::endl;
    return new B();
  case (2):
    std::cout << "C generated!" << std::endl;
    return new C();
  default:
    std::cout << "NULL generated" << std::endl;
  }
  return NULL;
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p)) {
    std::cout << "Input identified as A." << std::endl;
  } else if (dynamic_cast<B *>(p)) {
    std::cout << "Input identified as B." << std::endl;
  } else if (dynamic_cast<C *>(p)) {
    std::cout << "Input identified as C." << std::endl;
  } else {
    std::cout << "Unknown input type." << std::endl;
  }
}

void identify(Base &p) {
  if (dynamic_cast<A *>(&p)) {
    std::cout << "Input identified as A." << std::endl;
  } else if (dynamic_cast<B *>(&p)) {
    std::cout << "Input identified as B." << std::endl;
  } else if (dynamic_cast<C *>(&p)) {
    std::cout << "Input identified as C." << std::endl;
  } else {
    std::cout << "Unknown input type." << std::endl;
  }
}
