#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  Bureaucrat *b1;
  Bureaucrat *b2;
  Form *f1;

  try {
    b1 = new Bureaucrat("Joe", 40);
    b2 = new Bureaucrat("Kamala", 80);
    f1 = new Form("Garbage License", 75, 50);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << *b1 << std::endl;
  std::cout << *b2 << std::endl;
  std::cout << *f1 << std::endl;

  b2->SignForm(*f1);
  std::cout << "Form status: " << f1->getSigned() << std::endl;
  b1->SignForm(*f1);
  std::cout << "Form status: " << f1->getSigned() << std::endl;
}
