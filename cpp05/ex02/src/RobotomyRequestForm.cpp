#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45, "no target") {
#ifdef DEBUG
  std::cout << "RobotomyRequestForm default constructor called" << std::endl;
#endif
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm("RobotomyRequestForm", 72, 45, target) {
#ifdef DEBUG
  std::cout << "RobotomyRequestForm default constructor called" << std::endl;
#endif
}

RobotomyRequestForm::~RobotomyRequestForm() {
#ifdef DEBUG
  std::cout << "RobotomyRequestForm destructor called" << std::endl;
#endif
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute(),
            src.getTarget()) {
#ifdef DEBUG
  std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
#endif
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
  }
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  AForm::execute(executor);

  srand(time(NULL));
  if (rand() % 2)
    std::cout << getTarget() << " has been robotomized!" << std::endl;
  else
    std::cout << "The robotomy failed.." << std::endl;
}
