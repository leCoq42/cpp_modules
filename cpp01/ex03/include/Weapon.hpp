#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
public:
  Weapon(const std::string &type);
  ~Weapon();

  const std::string &getType();
  void setType(const std::string &type);

private:
  std::string _type;
};

#endif
