#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define MSG_BORDER "*---------------------------------------------*"

int main() {
  Intern someRandomIntern;
  Bureaucrat President("Sleepy Joe", 1);
  AForm *rrf;

  std::cout << President << std::endl;

  try {
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *rrf;
    President.SignForm(*rrf);
    rrf->execute(President);
    delete rrf;
  } catch (std::exception &e) {
    std::cerr << "Intern was unable to make form: " << e.what() << std::endl;
  }
  std::cout << MSG_BORDER << std::endl;

  try {
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    std::cout << *rrf;
    President.SignForm(*rrf);
    rrf->execute(President);
    delete rrf;
  } catch (std::exception &e) {
    std::cerr << "Intern was unable to make form: " << e.what() << std::endl;
  }
  std::cout << MSG_BORDER << std::endl;

  try {
    rrf = someRandomIntern.makeForm("random non-existing form", "Bender");
    std::cout << *rrf;
    President.SignForm(*rrf);
    rrf->execute(President);
    delete rrf;
  } catch (std::exception &e) {
    std::cerr << "Intern was unable to make form: " << e.what() << std::endl;
  }
  std::cout << MSG_BORDER << std::endl;

  try {
    rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
    std::cout << *rrf;
    President.SignForm(*rrf);
    rrf->execute(President);
    delete rrf;
  } catch (std::exception &e) {
    std::cerr << "Intern was unable to make form: " << e.what() << std::endl;
  }
  std::cout << MSG_BORDER << std::endl;

  return (0);
}
