#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "general.hpp"

class Contact {
public:
  Contact();
  ~Contact();

  void set_first();
  void set_last();
  void set_nick();
  void set_phone();
  void set_secret();

  std::string get_first();
  std::string get_last();
  std::string get_nick();
  std::string get_phone();
  std::string get_secret();

private:
  std::string first;
  std::string last;
  std::string nick;
  std::string phone;
  std::string secret;
};

#endif
