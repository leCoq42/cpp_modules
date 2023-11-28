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
    if (std::cin.eof()) {
      std::cin.clear();
      clearerr(stdin);
      std::cout << std::endl;
      std::cout << "EOF signal detected: Exiting Phonebook." << std::endl;
      exit(0);
    } else if (input.empty())
      std::cout << "Empty input not accepted! Try again." << std::endl;
    else
      return (input);
  }
}
