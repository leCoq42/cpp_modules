#include "ScalarConverter.hpp"
#include <iomanip>
#include <stdexcept>

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

void ScalarConverter::convert(const std::string &src) {
  e_type type = detectType(src);
  if (type != CHAR && type != IMPOSSIBLE) {
    try {
      stoi(src);
    } catch (std::out_of_range &e) {
      std::cout << "Input value out of range!" << std::endl;
      return;
    }
  }
  printConversions(src, type);
}

e_type detectType(const std::string &input) {
  if (input == "nanf" || input == "inff" || input == "+inff" ||
      input == "-inff")
    return (FLOAT);
  else if (input == "nan" || input == "inf" || input == "+inf" ||
           input == "-inf")
    return (DOUBLE);

  if (input.length() == 1 && !isdigit(input[0]))
    return (CHAR);
  if (checkValidDigit(input)) {
    if (input.find('.') != std::string::npos)
      return ((input.back() == 'f') ? FLOAT : DOUBLE);
    return (INT);
  }
  return (IMPOSSIBLE);
}

int checkValidDigit(std::string input) {
  int neg = 0;
  int dec = 0;
  size_t i;

  if (input[0] == '-' && input.length() > 1)
    neg = 1;
  i = neg;
  for (; i < input.length(); i++) {
    if (input[i] == '.') {
      dec++;
      if (dec > 1)
        return (0);
      continue;
    }
    if (i == input.length() - 1 && input[i] == 'f')
      return (1);
    if (!isdigit(input[i]))
      return (0);
  }
  return (1);
}

void printConversions(const std::string &src, e_type type) {
  if (type == IMPOSSIBLE)
    printImpossible();
  else {
    std::cout << "char: ";
    toChar(src, type);

    std::cout << "int: ";
    toInt(src, type);

    std::cout << "float: ";
    toFloat(src, type);

    std::cout << "double: ";
    toDouble(src, type);
  }
}

void toChar(const std::string &src, e_type type) {
  if (type == CHAR) {
    std::cout << src << std::endl;
    return;
  }
  if (isprint(static_cast<char>(std::stoi(src))))
    std::cout << static_cast<char>(std::stoi(src)) << std::endl;
  else
    std::cout << "Non displayable" << std::endl;
}

void toInt(const std::string &src, e_type type) {
  if (type == CHAR)
    std::cout << static_cast<int>(src[0]) << std::endl;
  else
    std::cout << static_cast<int>(std::stoi(src)) << std::endl;
}

void toFloat(const std::string &src, e_type type) {
  std::cout << std::fixed << std::showpoint << std::setprecision(1);

  if (type == CHAR)
    std::cout << static_cast<float>(src[0]) << "f" << std::endl;
  else
    std::cout << static_cast<float>(std::stof(src)) << "f" << std::endl;
}

void toDouble(const std::string &src, e_type type) {
  std::cout << std::fixed << std::showpoint << std::setprecision(1);

  if (type == CHAR)
    std::cout << static_cast<double>(src[0]) << std::endl;
  else
    std::cout << static_cast<double>(std::stod(src)) << std::endl;
}

void printImpossible(void) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
}
