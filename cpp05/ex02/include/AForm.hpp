#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
public:
  AForm();
  AForm(const std::string &name, int gradeToSign, int gradeToExecute);
  virtual ~AForm();

  AForm(const AForm &src);
  AForm &operator=(const AForm &rhs);

  void beSigned(const Bureaucrat &bur);

  const std::string &getName() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  bool getSigned() const;

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw() { return ("Grade is too high!"); };
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw() { return ("Grade is too low!"); };
  };

  class AlreadySignedException : public std::exception {
  public:
    const char *what() const throw() { return ("Form is already signed!"); };
  };

  class FormNotSignedException : public std::exception {
  public:
    const char *what() const throw() { return ("Form needs to be signed!"); };
  };

  virtual void execute(Bureaucrat const &executor) const = 0;

private:
  const std::string _name;
  bool _signed;
  int _gradeToSign;
  int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
