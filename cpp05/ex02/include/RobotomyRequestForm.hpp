#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &name, int gradeToSign,
                      int gradeToExecute);
  ~RobotomyRequestForm();

  RobotomyRequestForm(const RobotomyRequestForm &src);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

  void execute(Bureaucrat const &executor) const;
};

#endif
