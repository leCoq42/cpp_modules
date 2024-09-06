#pragma once

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
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
