#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(const std::string &name, int grade);
  ~Bureaucrat();

  Bureaucrat(Bureaucrat const &src);
  Bureaucrat &operator=(Bureaucrat const &rhs);

  const std::string &getName() const;
  int getGrade() const;

  void SignForm(AForm &form);
  void executeForm(AForm const &form);

  void incrementGrade();
  void decrementGrade();

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
  int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bur);

#endif
