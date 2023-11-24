#include "PhoneBook.hpp"
#include "general.hpp"

PhoneBook::PhoneBook() { cur = 0; }

PhoneBook::~PhoneBook() {}

void PhoneBook::add() {
  std::cout << "Adding Contact:" << std::endl;

  if (this->cur >= MAX_CONTACTS)
    this->cur = 0;

  Contact new_contact;
  new_contact.set_first();
  new_contact.set_last();
  new_contact.set_nick();
  new_contact.set_phone();
  new_contact.set_secret();

  contacts[this->cur++] = new_contact;
}

void PhoneBook::search() {
  this->print_overview();

  std::string input;
  input = get_valid_input("Enter Index: ");
  int index;
  try {
    index = std::stoi(input);
  } catch (const std::invalid_argument &) {
    std::cout << "Invalid input/index!" << std::endl;
    return;
  }
  if (index < 0 || index > MAX_CONTACTS - 1) {
    std::cout << "Invalid input/index!" << std::endl;
    return;
  }
  this->print_contact(index);
  return;
}

void PhoneBook::print_overview() {
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "|" << std::setw(10) << "index";
  std::cout << "|" << std::setw(10) << "first name";
  std::cout << "|" << std::setw(10) << "last name";
  std::cout << "|" << std::setw(11) << "nickname|" << std::endl;
  std::cout << "---------------------------------------------" << std::endl;

  for (int i = 0; i < MAX_CONTACTS; i++) {
    std::cout << "|" << std::setw(10) << i;
    std::cout << "|" << std::setw(10)
              << format_string(this->contacts[i].get_first());
    std::cout << "|" << std::setw(10)
              << format_string(this->contacts[i].get_last());
    std::cout << "|" << std::setw(10)
              << format_string(this->contacts[i].get_nick());
    std::cout << "|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
  }
}

void PhoneBook::print_contact(int i) {
  std::cout << std::endl << "Contact (" << i << ") Details:" << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << "First Name: " << this->contacts[i].get_first() << std::endl;
  std::cout << "Last Name: " << this->contacts[i].get_last() << std::endl;
  std::cout << "Nickname: " << this->contacts[i].get_nick() << std::endl;
  std::cout << "Phone Number: " << this->contacts[i].get_phone() << std::endl;
  std::cout << "Dark Secret: " << this->contacts[i].get_secret() << std::endl
            << std::endl;
}
