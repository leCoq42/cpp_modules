#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("default"), _signed(false), _gradeToSign(76), _gradeToExecute(76) {
#ifdef DEBUG
  std::cout << "Form default constructor called!" << std::endl;
#endif
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
#ifdef DEBUG
  std::cout << "Form parameterized constructor called" << std::endl;
#endif
}

AForm::~AForm() {
#ifdef DEBUG
  std::cout << "Form destructor called" << std::endl;
#endif
}

AForm::AForm(const AForm &src) : _name(src.getName()) {
#ifdef DEBUG
  std::cout << "Form copy constructor called" << std::endl;
#endif

  *this = src;
}

AForm &AForm::operator=(const AForm &rhs) {
  if (this != &rhs) {
    _signed = rhs.getSigned();
    _gradeToSign = rhs.getGradeToSign();
    _gradeToExecute = rhs.getGradeToExecute();
  }
  return *this;
}

void AForm::beSigned(const Bureaucrat &bur) {
  if (_signed == true)
    throw AForm::AlreadySignedException();
  if (bur.getGrade() > _gradeToSign)
    throw AForm::GradeTooLowException();
  _signed = true;
}

const std::string &AForm::getName() const { return _name; }

int AForm::getGradeToSign() const { return _gradeToSign; }

int AForm::getGradeToExecute() const { return _gradeToExecute; }

bool AForm::getSigned() const { return _signed; }

std::ostream &operator<<(std::ostream &out, const AForm &form) {
  std::cout << form.getName()
            << ", form. Grade to sign: " << form.getGradeToSign()
            << ". Grade to execute: " << form.getGradeToExecute()
            << ". Status: " << form.getSigned() << std::endl;

  return out;
}
