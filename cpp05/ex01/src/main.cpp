#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  Bureaucrat b1("Sleepy Joe", 76);
  Bureaucrat b2("Kamala", 76);
  Form f1;
  Form f2("Legit License", 1, 1);

  try {
    b1 = Bureaucrat("Hunter", 40);
    b2 = Bureaucrat("Barack", 80);
    f1 = Form("Garbage License", 150, 150);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  Bureaucrat b3(b1);

  f2 = f1;

  std::cout << b1;
  std::cout << b2;
  std::cout << b3;
  std::cout << f1;
  std::cout << f2 << std::endl;

  b2.SignForm(f1);
  std::cout << "Form1 status: " << f1.getSigned() << std::endl;
  b1.SignForm(f1);
  std::cout << "Form1 status: " << f1.getSigned() << std::endl;
  b1.SignForm(f1);
  std::cout << "Form2 status: " << f2.getSigned() << std::endl;
}
