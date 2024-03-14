#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5, "no target") {
#ifdef DEBUG
  std::cout << "PresidentialPardonForm default constructor called!"
            << std::endl;
#endif
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : AForm("PresidentialPardonForm", 25, 5, target) {
#ifdef DEBUG
  std::cout << "PresidentialPardonForm parameterized constructor called!"
            << std::endl;
#endif
}

PresidentialPardonForm::~PresidentialPardonForm() {
#ifdef DEBUG
  std::cout << "PresidentialPardonForm destructor called" << std::endl;
#endif
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &src)
    : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute(),
            src.getTarget()) {
#ifdef DEBUG
  std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
#endif
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
