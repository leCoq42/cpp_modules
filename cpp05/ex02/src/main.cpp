#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  Bureaucrat Joe("Sleepy Joe", 1);

  ShrubberyCreationForm f1;
  std::cout << f1 << std::endl;

  RobotomyRequestForm f2;
  std::cout << f2 << std::endl;

  PresidentialPardonForm f3;
  std::cout << f3 << std::endl;

  Joe.executeForm(f1);
  Joe.SignForm(f1);
  Joe.executeForm(f1);
}
