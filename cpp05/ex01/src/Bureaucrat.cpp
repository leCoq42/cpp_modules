#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150) {
#ifdef DEBUG
  std::cout << "Bureaucrat default constructor called!" << std::endl;
#endif
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
#ifdef DEBUG
  std::cout << "Bureaucrat parameterized constructor called" << std::endl;
#endif

  if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  else if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  _grade = grade;
}

Bureaucrat::~Bureaucrat() {
#ifdef DEBUG
  std::cout << "Bureaucrat destructor called" << std::endl;
#endif
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
    : _name(src.getName()), _grade(src.getGrade()) {
#ifdef DEBUG
  std::cout << "Bureaucrat copy constructor called" << std::endl;
#endif
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
#ifdef DEBUG
  std::cout << "Bureaucrat operator = overload called";
#endif
  if (this != &rhs) {
    _grade = rhs._grade;
  }
  return *this;
}

void Bureaucrat::SignForm(Form &form) {
  try {
    form.beSigned(*this);
    std::cout << _name << " signs " << form.getName() << std::endl;
  } catch (Form::GradeTooHighException &e) {
    std::cout << _name << " couldn’t sign " << form.getName()
              << " because: " << e.what() << std::endl;
  } catch (Form::AlreadySignedException &e) {
    std::cout << _name << " couldn’t sign " << form.getName()
              << " because: " << e.what() << std::endl;
  }
}

const std::string &Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() {
  if (_grade <= 1)
    throw Bureaucrat::GradeTooHighException();
  _grade--;
}

void Bureaucrat::decrementGrade() {
  if (_grade >= 150)
    throw Bureaucrat::GradeTooLowException();
  _grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bur) {
  out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << std::endl;
  return out;
}
