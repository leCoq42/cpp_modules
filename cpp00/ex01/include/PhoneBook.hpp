#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
public:
  PhoneBook();
  ~PhoneBook();

  void add();
  void search();

private:
  Contact contacts[MAX_CONTACTS];
  int cur;

  void print_overview();
  void print_contact(int index);
};

#endif
