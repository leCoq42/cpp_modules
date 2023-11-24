#include "general.hpp"

std::string format_string(std::string str) {
  if (str.length() > 10)
    return (str.substr(0, 9) + ".");
  return (str);
}

std::string get_valid_input(std::string prompt) {
  std::string input;

  while (1) {
    std::cout << prompt;
    std::getline(std::cin, input);
    if (input.empty())
      std::cout << "Invalid input!" << std::endl;
    else
      return (input);
  }
}
