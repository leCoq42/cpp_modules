#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
#ifdef DEBUG
  std::cout << "Intern default constructor called!" << std::endl;
#endif
}

Intern::~Intern() {
#ifdef DEBUG
  std::cout << "Intern destructor called!" << std::endl;
#endif
}

Intern::Intern(Intern const &src) {
#ifdef DEBUG
  std::cout << "Intern copy constructor called!" << std::endl;
#endif

  *this = src;
}

Intern &Intern::operator=(Intern const &rhs) {
#ifdef DEBUG
  std::cout << "Intern assignment operator called!" << std::endl;
#endif

  if (this != &rhs) {
    *this = rhs;
  }
  return *this;
}

AForm *Intern::makeForm(std::string const &formName,
                        std::string const &target) {
  if (formName == "shrubbery creation")
    return new ShrubberyCreationForm(target);
  else if (formName == "robotomy request")
    return new RobotomyRequestForm(target);
  else if (formName == "presidential pardon")
    return new PresidentialPardonForm(target);
  else
    return NULL;
}
