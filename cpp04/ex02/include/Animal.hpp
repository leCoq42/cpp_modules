#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class A_Animal {
public:
  A_Animal();
  A_Animal(std::string type);
  virtual ~A_Animal() = 0;

  A_Animal(A_Animal const &src);
  A_Animal &operator=(A_Animal const &src);

  std::string getType() const;
  virtual void makeSound() const;

protected:
  std::string _type;

private:
};

#endif
