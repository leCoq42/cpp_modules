#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form {
public:
  Form();
  ~Form();

  Form(const Form &src);
  Form &operator=(const Form &rhs);

private:
  const std::string _name;
  bool _signed;
  int _gradeToSign;
  int _gradeToExecute;
};

#endif
