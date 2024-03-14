#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
  Intern();
  ~Intern();

  Intern(Intern const &src);
  Intern &operator=(Intern const &rhs);

  AForm *makeForm(std::string const &formName, std::string const &target);

  AForm *createShrubForm(std::string const &target);
  AForm *createRobotomyForm(std::string const &target);
  AForm *createPardonForm(std::string const &target);

  class UnkownFormTypeException : public std::exception {
  public:
    const char *what() const throw() { return ("Unkown Form Type!"); };
  };
};

#endif
