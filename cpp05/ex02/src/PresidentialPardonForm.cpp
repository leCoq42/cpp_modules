#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5) {
  std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &src)
    : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()) {
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
  std::cout << "test" << std::endl;
  (void)executor;
}
