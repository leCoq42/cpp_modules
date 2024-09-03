#pragma once

#include <stack>
#include <string>

class RPN {
public:
	RPN();
	RPN(const std::string &input);
	~RPN();
	RPN(const RPN &src);
	RPN &operator=(const RPN &rhs);

	void print_stack(const std::stack<std::string> toPrint);

private:
	std::string _inputStr;
	const std::string _token = "+-/*";
	std::stack<std::string> _tokens;
};
