#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string &name, int gradeToSign,
                         int gradeToExecute);
  ~PresidentialPardonForm();

  PresidentialPardonForm(const PresidentialPardonForm &src);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

  void execute(Bureaucrat const &executor) const;
};

#endif
