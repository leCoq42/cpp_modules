#include "ScalarConverter.hpp"
#include <iomanip>

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

// std::setprecision can be edited to customize the decimal precision.
void ScalarConverter::convert(const std::string &src) {
  // std::cout << std::fixed << std::setprecision(1);
  e_type type = detectType(src);
  if (type != CHAR && type != IMPOSSIBLE && type != PSEUDOFLOAT &&
      type != PSEUDODOUBLE)
    try {
      stoi(src);
    } catch (std::out_of_range &e) {
      std::cout << "Input value out of range!" << std::endl;
      return;
    } catch (std::invalid_argument &e) {
      printImpossible();
      return;
    }
	ScalarConverter::printConversions(src, type);
}

e_type ScalarConverter::detectType(const std::string &input) {
  if (input == "nanf" || input == "inff" || input == "+inff" ||
      input == "-inff")
    return (PSEUDOFLOAT);
  else if (input == "nan" || input == "inf" || input == "+inf" ||
           input == "-inf")
    return (PSEUDODOUBLE);

  if (input.length() == 1 && !isdigit(input[0]))
    return (CHAR);
  if (ScalarConverter::checkValidDigit(input)) {
    if (input.find('.') != std::string::npos)
      return ((input.back() == 'f') ? FLOAT : DOUBLE);
    return (INT);
  }
  return (IMPOSSIBLE);
}

bool ScalarConverter::checkValidDigit(std::string input) {
  bool isNeg = false;
  int dec = 0;
  size_t i;

  if (input[0] == '-' && input.length() > 1)
    isNeg = true;
  i = isNeg ? 1 : 0;
  for (; i < input.length(); i++) {
    if (input[i] == '.') {
      dec++;
      if (dec > 1)
        return (false);
      continue;
    }
    if (i == input.length() - 1 && input[i] == 'f')
      return (true);
    if (!isdigit(input[i]))
      return (false);
  }
  return (true);
}

void ScalarConverter::printConversions(const std::string &src, e_type type) {
  if (type == IMPOSSIBLE)
    ScalarConverter::printImpossible();
  else {
    std::cout << "char: ";
	ScalarConverter::toChar(src, type);

    std::cout << "int: ";
	ScalarConverter::toInt(src, type);

    std::cout << "float: ";
	ScalarConverter::toFloat(src, type);

    std::cout << "double: ";
	ScalarConverter::toDouble(src, type);
  }
}

void ScalarConverter::toChar(const std::string &src, e_type type) {
  if (type == CHAR) {
    std::cout << src << std::endl;
    return;
  } else if (type == PSEUDOFLOAT || type == PSEUDODOUBLE)
    std::cout << "impossible" << std::endl;
  else if (isprint(static_cast<char>(std::stoi(src))))
    std::cout << static_cast<char>(std::stoi(src)) << std::endl;
  else
    std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::toInt(const std::string &src, e_type type) {
  if (type == CHAR)
    std::cout << static_cast<int>(src[0]) << std::endl;
  else if (type == PSEUDOFLOAT || type == PSEUDODOUBLE)
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(std::stoi(src)) << std::endl;
}

void ScalarConverter::toFloat(const std::string &src, e_type type) {
  if (type == CHAR)
    std::cout << static_cast<float>(src[0]) << "f" << std::endl;
  else if (type == PSEUDOFLOAT)
    std::cout << src << std::endl;
  else if (type == PSEUDODOUBLE)
    std::cout << src << "f" << std::endl;
  else
    std::cout << static_cast<float>(std::stof(src)) << "f" << std::endl;
}

void ScalarConverter::toDouble(const std::string &src, e_type type) {
  if (type == CHAR)
    std::cout << static_cast<double>(src[0]) << std::endl;
  else if (type == PSEUDOFLOAT)
    std::cout << src.substr(0, src.size() - 1) << std::endl;
  else if (type == PSEUDODOUBLE)
    std::cout << src << std::endl;
  else
    std::cout << static_cast<double>(std::stod(src)) << std::endl;
}

void ScalarConverter::printImpossible(void) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
}
