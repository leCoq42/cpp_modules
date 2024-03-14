#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  Bureaucrat b1;
  Bureaucrat b2("Donald", 1);
  Form f1;
  Form f2("Legit License", 1, 1);
  Form f3("Legit License2", 1, 1);

  try {
    b1 = Bureaucrat("Sleepy Joe", 40);
    f1 = Form("Garbage License", 150, 150);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  Bureaucrat b3(b1);

  f2 = f1;

  std::cout << f1;
  std::cout << b2;
  b2.SignForm(f1);
  std::cout << f1;
  std::cout << b1;
  b1.SignForm(f1);
  std::cout << f1 << std::endl;

  std::cout << f2;
  std::cout << b1;
  b1.SignForm(f2);
  std::cout << f2 << std::endl;

  std::cout << f3;
  std::cout << b1;
  b1.SignForm(f3);
  std::cout << f3;
  std::cout << b3;
  b2.SignForm(f3);
  std::cout << f3;
  return 0;
}
