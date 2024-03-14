#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define MSG_BORDER "*---------------------------------------------*"

int main(void) {
  Bureaucrat Joe("Sleepy Joe", 150);
  Bureaucrat Brak("Barrack", 1);

  ShrubberyCreationForm f1("home1");
  RobotomyRequestForm f2("home2");
  PresidentialPardonForm f3("home3");

  std::cout << f1;
  std::cout << f2;
  std::cout << f3 << std::endl;

  std::cout << MSG_BORDER << std::endl;

  Joe.executeForm(f1);
  Joe.SignForm(f1);
  Joe.executeForm(f1);

  std::cout << MSG_BORDER << std::endl;

  Joe.executeForm(f2);
  Joe.SignForm(f2);
  Joe.executeForm(f2);

  std::cout << MSG_BORDER << std::endl;

  Joe.executeForm(f3);
  Joe.SignForm(f3);
  Joe.executeForm(f3);

  std::cout << MSG_BORDER << std::endl;

  Brak.executeForm(f1);
  Brak.SignForm(f1);
  Brak.executeForm(f1);

  std::cout << MSG_BORDER << std::endl;

  Brak.executeForm(f2);
  Brak.SignForm(f2);
  Brak.executeForm(f2);

  std::cout << MSG_BORDER << std::endl;

  Brak.executeForm(f3);
  Brak.SignForm(f3);
  Brak.executeForm(f3);

  std::cout << MSG_BORDER << std::endl;

  ShrubberyCreationForm shrub = f1;
  std::cout << shrub;
}
