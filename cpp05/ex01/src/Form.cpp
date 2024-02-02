#include "Form.hpp"

Form::Form()
    : _name("default"), _grade(150), _signed(false), _gradeToSign(76),
      _gradeToExecute(76) {
#ifdef DEBUG
  std::cout << "Form default constructor called!" << std::endl;
#endif
}

Form::~Form() {
#ifdef DEBUG
  std::cout << "Form destructor called" << std::endl;
#endif
}
