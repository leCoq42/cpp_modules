#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
public:
  Form();
  Form(const std::string &name, int gradeToSign, int gradeToExecute);
  ~Form();

  Form(const Form &src);
  Form &operator=(const Form &rhs);

  void beSigned(const Bureaucrat &bur);

  const std::string &getName() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  const std::string getSigned() const;

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw() { return ("Grade is too high!"); };
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw() { return ("Grade is too low!"); };
  };

private:
  const std::string _name;
  bool _signed;
  int _gradeToSign;
  int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
