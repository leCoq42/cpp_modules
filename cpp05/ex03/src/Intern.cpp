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

AForm *Intern::createShrubForm(std::string const &target) {
  return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomyForm(std::string const &target) {
  return (new RobotomyRequestForm(target));
}

AForm *Intern::createPardonForm(std::string const &target) {
  return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string const &formName,
                        std::string const &target) {
  std::string availableForms[3] = {"shrubbery creation", "robotomy request",
                                   "presidential pardon"};

  typedef AForm *(Intern::*FormCreator)(const std::string &target);
  FormCreator formCreators[3] = {&Intern::createShrubForm,
                                 &Intern::createRobotomyForm,
                                 &Intern::createPardonForm};

  for (int i = 0; i < 3; ++i) {
    if (availableForms[i] == formName)
      return (this->*formCreators[i])(target);
  }
  throw UnkownFormTypeException();
}
