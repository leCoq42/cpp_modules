#include "Contact.hpp"
#include "general.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::get_first() { return (this->first); }

void Contact::set_first() {
  this->first = get_valid_input("Enter first name: ");
}

std::string Contact::get_last() { return (this->last); }

void Contact::set_last() { this->last = get_valid_input("Enter last name: "); }

std::string Contact::get_nick() { return (this->nick); }

void Contact::set_nick() { this->nick = get_valid_input("Enter nickname: "); }

std::string Contact::get_phone() { return (this->phone); }

void Contact::set_phone() {
  this->phone = get_valid_input("Enter phone number: ");
}

std::string Contact::get_secret() { return (this->secret); }

void Contact::set_secret() {
  this->secret = get_valid_input("Enter darkest secret: ");
}
