#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5, "no target") {
  std::cout << "PresidentialPardonForm default constructor called!"
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : AForm("PresidentialPardonForm", 25, 5, target) {
  std::cout << "PresidentialPardonForm parameterized constructor called!"
            << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &src)
    : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute(),
            src.getTarget()) {
  std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
  }
  return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  AForm::execute(executor);

  std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
