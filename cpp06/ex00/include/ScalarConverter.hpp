#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iomanip>
#include <iostream>

enum e_type { CHAR, INT, FLOAT, DOUBLE, IMPOSSIBLE };

class ScalarConverter {
public:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &src);
  ~ScalarConverter();
  ScalarConverter &operator=(const ScalarConverter &src);

  static void convert(const std::string &src);
};

e_type detectType(const std::string &input);
int checkValidDigit(std::string input);
void printConversions(const std::string &src, e_type type);

void toChar(const std::string &src, e_type type);
void toInt(const std::string &src, e_type type);
void toFloat(const std::string &src, e_type type);
void toDouble(const std::string &src, e_type type);

void printImpossible(void);

#endif
