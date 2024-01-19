#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
public:
  WrongAnimal();
  WrongAnimal(std::string type);
  virtual ~WrongAnimal();

  WrongAnimal(WrongAnimal const &src);
  WrongAnimal &operator=(WrongAnimal const &src);

  std::string getType() const;
  void makeSound() const;

protected:
  std::string _type;

private:
};

#endif
