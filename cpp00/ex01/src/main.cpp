#include "PhoneBook.hpp"
#include "general.hpp"

int main(void) {
  std::cout << "Welcome to the PhoneBook!" << std::endl;
  std::string input;
  PhoneBook phoneBook;

  while (1) {
    std::cout << "Enter command: ";
    std::getline(std::cin, input);

    if (input == "EXIT")
      return (0);
    else if (input == "ADD")
      phoneBook.add();
    else if (input == "SEARCH")
      phoneBook.search();
    else
      continue;
  }
}
