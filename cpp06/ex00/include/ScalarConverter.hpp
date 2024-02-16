#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>

class ScalarConverter {
public:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &src);
  ~ScalarConverter();
  ScalarConverter &operator=(const ScalarConverter &src);

  std::string detectType(std::string &input);
  void convertChar(std::string src);
};

#endif
