#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137, "no target") {
#ifdef DEBUG
  std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {
#ifdef DEBUG
  std::cout << "ShrubberyCreationForm parameterized constructor called"
            << std::endl;
#endif
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
#ifdef DEBUG
  std::cout << "ShrubberyCreationForm destructor called" << std::endl;
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute(),
            src.getTarget()) {
#ifdef DEBUG
  std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
#endif
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
  }
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  AForm::execute(executor);

  std::fstream file;
  std::string filename = getTarget() + "_shrubbery";

  file.open(filename.c_str(), std::ios_base::out);
  if (!file.is_open())
    throw ShrubberyCreationForm::FileNotOpenException();

  file << _text_art;
  file.close();
}
