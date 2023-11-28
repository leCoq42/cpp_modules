#include "PhoneBook.hpp"
#include "general.hpp"
#include <ostream>

int main(void) {
  std::cout << "Welcome to the PhoneBook!" << std::endl;
  std::string input;
  PhoneBook phoneBook;

  while (1) {
    std::cout << "Enter command: ";
    std::getline(std::cin, input);

    if (std::cin.eof()) {
      std::cin.clear();
      clearerr(stdin);
      std::cout << std::endl;
      std::cout << "EOF signal detected: Exiting Phonebook." << std::endl;
      return (0);
    } else if (input == "EXIT")
      return (0);
    else if (input == "ADD")
      phoneBook.add();
    else if (input == "SEARCH")
      phoneBook.search();
    else {
      std::cout << "Invalid Command!" << std::endl;
      continue;
    }
  }
}
