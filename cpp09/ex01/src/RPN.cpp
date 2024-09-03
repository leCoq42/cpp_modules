#include "RPN.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

RPN::RPN() :
	_inputStr("")
{}

RPN::~RPN()
{}

RPN::RPN(const std::string &input) :
	_inputStr(input)
{
	std::string reversed(_inputStr.rbegin(), _inputStr.rend());
	std::stringstream ss(reversed);
	std::string token;

	while (std::getline(ss, token, ' '))
		_tokens.push(token);

	#ifdef DEBUG
	print_stack(_tokens);
	#endif
}

// RPN::RPN(const RPN &src) :
//_inputStr(src._inputStr)
// {}
// RPN &RPN::operator=(const RPN &rhs) {}

void RPN::print_stack(const std::stack<std::string> toPrint)
{
	std::stack<std::string> tmp = toPrint;
	while (!tmp.empty())
	{
		std::cout << "token = " << tmp.top() << std::endl;
		tmp.pop();
	}
}
