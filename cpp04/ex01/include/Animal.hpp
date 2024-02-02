#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
  Animal();
  virtual ~Animal();

  Animal(Animal const &src);
  Animal &operator=(Animal const &src);

  std::string getType() const;
  virtual void makeSound() const;

protected:
  std::string _type;
};

#endif
