#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public A_Animal {
public:
  Dog();
  ~Dog();

  Dog(Dog const &src);
  Dog &operator=(Dog const &src);

  void makeSound() const;

  std::string getIdea(const int i) const;
  void setIdea(const std::string idea);
  int getIdeaCount() const;

private:
  Brain *_brain;
};

#endif
