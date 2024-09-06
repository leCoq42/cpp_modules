#pragma once

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 public:
  Cat();
  ~Cat();

  Cat(Cat const &src);
  Cat &operator=(Cat const &src);

  void makeSound() const;

  std::string getIdea(const int i) const;
  void setIdea(const std::string idea);
  int getIdeaCount() const;

 private:
  Brain *_brain;
};
