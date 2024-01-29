#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(std::string const &name, int const &grade);
  ~Bureaucrat();

  Bureaucrat(Bureaucrat const &src);
  Bureaucrat &operator=(Bureaucrat const &rhs);

  const std::string getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw() {
      return ("Exception: Grade is too high!");
    };
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw() {
      return ("Exception: Grade is too low!");
    };
  };

private:
  std::string _name;
  int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bur);

#endif
