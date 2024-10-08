#pragma once

#include <string>

class Brain {
 public:
  Brain();
  ~Brain();
  Brain(const Brain &brain);
  Brain &operator=(const Brain &brain);

  const std::string getIdea(int i) const;
  void setIdea(std::string idea);
  int getIdeaCount() const;

 private:
  static const int _max_ideas = 2;
  int _ideaCount;
  std::string _ideas[_max_ideas];
};
