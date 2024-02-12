#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string const &target);
  PresidentialPardonForm(const std::string &name, int gradeToSign,
                         int gradeToExecute, const std::string &target);
  ~PresidentialPardonForm();

  PresidentialPardonForm(const PresidentialPardonForm &src);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

  void execute(Bureaucrat const &executor) const;
};

#endif
