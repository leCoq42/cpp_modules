#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45) {
  std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()) {
  std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
  }
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  std::cout << "test" << std::endl;
  (void)executor;
}
