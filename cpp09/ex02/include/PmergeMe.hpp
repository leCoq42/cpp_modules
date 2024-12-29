#pragma once

#include <cstddef>
#include <list>
#include <vector>

class PmergeMe {
public:
  PmergeMe(char **argv);
  ~PmergeMe();
  static size_t timeToProcess(size_t range);

  std::list<unsigned int> _inputList;
  std::vector<unsigned int> _inputVector;

private:
  PmergeMe();
  std::vector<unsigned int> Ford_Johnson_Sort(std::vector<unsigned int> input);
  std::list<unsigned int> Ford_Johnson_Sort(std::list<unsigned int> input);

  std::vector<unsigned int> Merge_Insert_Jacobsthal(std::vector<unsigned int> sorted_large,
                                           std::vector<unsigned int> smaller);
  std::list<unsigned int> Merge_Insert_Jacobsthal(std::list<unsigned int> sorted_large,
                                         std::list<unsigned int> smaller);

  std::vector<size_t> generate_jacobsthal_numbers(size_t size);
};
