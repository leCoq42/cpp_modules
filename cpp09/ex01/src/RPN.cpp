#include "RPN.hpp"

#include <algorithm>
#include <sstream>
#include <stack>
#include <string>

RPN::~RPN() {}

RPN::RPN(const std::string &input) : _inputStr(input) {
  if (_inputStr.empty())
    throw std::invalid_argument("Empty input string");
  if (_inputStr.find_first_not_of(RPN::NUMBERS + RPN::OPERATORS + RPN::SPACE) != 
      std::string::npos)
    throw std::invalid_argument("Invalid input string");
  calculate();
}

void RPN::calculate() {
  std::stringstream ss(_inputStr);
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
    } else if (std::all_of(token.begin(), token.end(), ::isdigit)) {
      _stack.push(std::stoi(token));
    } else
      throw std::invalid_argument("Invalid expression");
  }
  if (_stack.size() != 1)
    throw std::invalid_argument("Invalid expression");
  _result = _stack.top();
}


int RPN::getResult() const { return _result; }
