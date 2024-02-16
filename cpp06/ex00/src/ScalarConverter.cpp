#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
#ifdef DEBUG
  std::cout << "ScalarConverter default constructor called" << std::endl;
#endif
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
#ifdef DEBUG
  std::cout << "ScalarConverter copy constructor called" << std::endl;
#endif
  *this = src;
}

ScalarConverter::~ScalarConverter() {
#ifdef DEBUG
  std::cout << "ScalarConverter destructor called" << std::endl;
#endif
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
#ifdef DEBUG
  std::cout << "ScalarConverter assignation operator called" << std::endl;
#endif
  if (this != &src) {
    *this = src;
  }
  return *this;
}

std::string ScalarConverter::detectType(std::string &input) {
  std::string input_str = input;

  if (input_str == "nanf" || input_str == "inff" || input_str == "+inff" ||
      input_str == "-inff")
    return "float";
  if (input_str == "nan" || input_str == "inf" || input_str == "+inf" ||
      input_str == "-inf")
    return "double";
  if (input_str.length() == 1 && !isdigit(input_str[0]))
    return "char";
  if (input_str.find('.') != std::string::npos) {
    return (input.find('f') != std::string::npos) ? "float" : "double";
  }
  return "impossible";
}

void ScalarConverter::convertChar(std::string src) {
  std::cout << "src type: " << ScalarConverter::detectType(src) << std::endl;

  try {
    std::cout << "char: " << src << std::endl;
  } catch (std::exception &e) {
    std::cout << "Non displayable" << std::endl;
  }
  try {
    std::cout << "int: " << stoi(src) << std::endl;
  } catch (std::exception &e) {
    std::cout << "impossible" << std::endl;
  }
  try {
    std::cout << "float: " << stof(src) << std::endl;
  } catch (std::exception &e) {
    std::cout << "nanf" << std::endl;
  }
  try {
    std::cout << "double: " << stod(src) << std::endl;
  } catch (std::exception &e) {
    std::cout << "nan" << std::endl;
  }
}
