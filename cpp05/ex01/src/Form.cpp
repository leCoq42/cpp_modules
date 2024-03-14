#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : _name("default"), _signed(false), _gradeToSign(76), _gradeToExecute(76) {
#ifdef DEBUG
  std::cout << "Form default constructor called!" << std::endl;
#endif
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
#ifdef DEBUG
  std::cout << "Form parameterized constructor called" << std::endl;
#endif
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw Form::GradeTooHighException();
  if (gradeToSign > 150 || gradeToExecute > 150)
    throw Form::GradeTooLowException();
}

Form::~Form() {
#ifdef DEBUG
  std::cout << "Form destructor called" << std::endl;
#endif
}

Form::Form(const Form &src) : _name(src.getName()) {
#ifdef DEBUG
  std::cout << "Form copy constructor called" << std::endl;
#endif

  *this = src;
}

Form &Form::operator=(const Form &rhs) {
  if (this != &rhs) {
    _signed = rhs.getSigned();
    _gradeToSign = rhs.getGradeToSign();
    _gradeToExecute = rhs.getGradeToExecute();
  }
  return *this;
}

void Form::beSigned(const Bureaucrat &bur) {
  if (_signed == true)
    throw Form::AlreadySignedException();
  if (bur.getGrade() > _gradeToSign)
    throw Form::GradeTooHighException();
  _signed = true;
}

const std::string &Form::getName() const { return _name; }

int Form::getGradeToSign() const { return _gradeToSign; }

int Form::getGradeToExecute() const { return _gradeToExecute; }

bool Form::getSigned() const { return _signed; }

std::ostream &operator<<(std::ostream &out, const Form &form) {
  out << form.getName() << ", form. Grade to sign: " << form.getGradeToSign()
      << ". Grade to execute: " << form.getGradeToExecute()
      << ". Status: " << form.getSigned() << std::endl;
  return out;
}
