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
}

Form::~Form() {
#ifdef DEBUG
  std::cout << "Form destructor called" << std::endl;
#endif
}

void Form::beSigned(const Bureaucrat &bur) {
  if (_signed == true)
    throw Form::AlreadySignedException();
  if (bur.getGrade() > _gradeToSign)
    throw Form::GradeTooLowException();
  _signed = true;
}

const std::string &Form::getName() const { return _name; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }
const std::string Form::getSigned() const {
  if (_signed)
    return "signed";
  return "unsigned";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
  std::cout << form.getName()
            << ", form. Grade to sign: " << form.getGradeToSign()
            << ". Grade to execute: " << form.getGradeToExecute()
            << ". Status: " << form.getSigned() << std::endl;

  return out;
}
