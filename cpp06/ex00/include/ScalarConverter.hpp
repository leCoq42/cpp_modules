#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>

enum e_type { CHAR, INT, FLOAT, DOUBLE, IMPOSSIBLE, PSEUDOFLOAT, PSEUDODOUBLE };

class ScalarConverter {
	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);

		static void convert(const std::string &src);

	private:
		static e_type detectType(const std::string &input);
		static bool checkValidDigit(std::string input);
		static void printConversions(const std::string &src, e_type type);

		static void toChar(const std::string &src, e_type type);
		static void toInt(const std::string &src, e_type type);
		static void toFloat(const std::string &src, e_type type);
		static void toDouble(const std::string &src, e_type type);

		static void printImpossible(void);
};

#endif
