#pragma once

#include <stack>
#include <string>

class RPN {
  public:
	RPN(const std::string &input);
	~RPN();
	int getResult() const;

	const std::string NUMBERS = "0123456789";
	const std::string OPERATORS = "+-*/";
	const std::string SPACE = " ";

  private:
	std::string _inputStr;
	std::stack<int> _stack;
	int _result;

	RPN();
	RPN(const RPN &src);
	RPN &operator=(const RPN &rhs);

	void calculate();
	void performOperation(char token, int left, int right);
};
