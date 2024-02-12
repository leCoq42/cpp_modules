#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  Bureaucrat Joe("Sleepy Joe", 150);
  Bureaucrat Brak("Barrack", 1);

  ShrubberyCreationForm f1("home");
  std::cout << f1 << std::endl;

  RobotomyRequestForm f2("home");
  std::cout << f2 << std::endl;

  PresidentialPardonForm f3("home");
  std::cout << f3 << std::endl;

  Joe.executeForm(f1);
  Joe.SignForm(f1);
  Joe.executeForm(f1);

  /* Brak.executeForm(f1); */
  /* Brak.SignForm(f1); */
  /* Brak.executeForm(f1); */
}
