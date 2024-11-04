#include "RPN.hpp"

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

inline const std::string numbers = "0123456789";
inline const std::string operators = "+-*/";
inline const std::string space = " ";

RPN::~RPN() {}

RPN::RPN(const std::string &input) : _inputStr(input) {
  if (input.empty())
    throw std::invalid_argument("Empty input string");
  if (input.find_first_not_of(numbers + operators + space) != std::string::npos)
    throw std::invalid_argument("Invalid input string");

  std::stringstream ss(input);
  for (std::string token; ss >> token;) {
    if (token == "+" || token == "-" || token == "*" || token == "/") {
      if (_stack.size() < 2)
        throw std::invalid_argument("Invalid expression");

      int right = _stack.top();
      _stack.pop();
      int left = _stack.top();
      _stack.pop();

      if (token == "+")
        _stack.push(left + right);
      else if (token == "-")
        _stack.push(left - right);
      else if (token == "*")
        _stack.push(left * right);
      else if (token == "/") {
        if (right == 0)
          throw std::invalid_argument("Division by zero");
        _stack.push(left / right);
      }
    } else if (std::isdigit(token[0]) && token.length() == 1) {
      _stack.push(std::stoi(token));
    } else
      throw std::invalid_argument("Invalid expression");
  }
  if (_stack.size() != 1)
    throw std::invalid_argument("Invalid expression");
  std::cout << "Result = " << _stack.top() << std::endl;
}
