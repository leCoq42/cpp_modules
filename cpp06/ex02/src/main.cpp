#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main(void) {
  A a;
  B b;
  C c;

  (void)a;
  (void)b;
  (void)c;
  return 0;
}

Base *generate(void) {}

void identify(Base *p) {}

void identify(Base &p) {}
