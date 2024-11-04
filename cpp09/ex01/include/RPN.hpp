#pragma once

#include <stack>
#include <string>

class RPN {
public:
  RPN(const std::string &input);
  ~RPN();

private:
  std::string _inputStr;
  std::stack<int> _stack;

  RPN &operator=(const RPN &rhs);
  RPN(const RPN &src);
  RPN();
};
