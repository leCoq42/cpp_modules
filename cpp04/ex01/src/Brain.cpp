#include "Brain.hpp"

Brain::Brain() : _ideaCount(0) {
  std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

Brain::Brain(const Brain &src) {
  std::cout << "Brain copy constructor called!" << std::endl;

  std::copy(src._ideas, src._ideas + src._max_ideas, _ideas);
  _ideaCount = src._ideaCount;
  *this = src;
}

Brain &Brain::operator=(const Brain &rhs) {
  std::cout << "Brain assignment operator called!" << std::endl;

  if (this != &rhs) {
    _ideaCount = rhs._ideaCount;
    std::copy(rhs._ideas, rhs._ideas + rhs._max_ideas, _ideas);
  }
  return *this;
}

const std::string Brain::getIdea(int i) const {
  if (i < 0 || i >= _max_ideas)
    return ("This idea are not within the brain's capacity!\n");
  if (_ideas[i].empty())
    return ("**Void**\n");
  return (_ideas[i]);
}

void Brain::setIdea(std::string idea) {
  if (_ideaCount >= _max_ideas)
    std::cout << "This Brain is full with ideas already.." << std::endl;
  else {
    _ideas[_ideaCount] = idea;
    _ideaCount++;
  }
}

int Brain::getIdeaCount() const { return (_ideaCount); }
