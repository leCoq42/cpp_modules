#include "Brain.hpp"

Brain::Brain() : _ideaCount(0) {
  std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

Brain::Brain(const Brain &src) {
  std::cout << "Brain copy constructor called!" << std::endl;

  std::copy(src._ideas, src._ideas + 100, _ideas);
  _ideaCount = src._ideaCount;
  *this = src;
}

Brain &Brain::operator=(const Brain &src) {
  std::cout << "Brain assignment operator called!" << std::endl;

  if (this != &src) {
    std::copy(src._ideas, src._ideas + 100, _ideas);
    _ideaCount = src._ideaCount;
  }
  return *this;
}

const std::string Brain::getIdea(int i) const {
  if (i < 0 || i >= _max_ideas)
    return ("This idea are not within the brain's capacity!\n");
  if (_ideas[i].empty())
    return ("Whut!?\n");
  return (_ideas[i]);
}

void Brain::setIdea(std::string idea) {
  if (_ideaCount >= _max_ideas)
    std::cout << "The Brain is full with ideas!" << std::endl;
  else {
    _ideas[_ideaCount] = idea;
    _ideaCount++;
  }
}

int Brain::getIdeaCount() const { return (_ideaCount); }
