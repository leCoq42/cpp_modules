#include "PmergeMe.hpp"
#include <cmath>
#include <iostream>
#include <vector>

PmergeMe::PmergeMe(char **argv) {
  size_t i = 0;

  std::cout << "Before: ";
  while (argv[++i] != NULL) {
    std::cout << argv[i] << " ";
    _inputList.push_back(atoi(argv[i]));
    _inputVector.push_back(atoi(argv[i]));
  }
  std::cout << "\n";

  std::vector<unsigned int> sorted = Ford_Johnson_Sort(_inputVector);

  std::cout << "After: ";
  for (auto it : sorted) {
    std::cout << it << " ";
  }
  std::cout << "\n";
}

PmergeMe::~PmergeMe() {}

std::vector<unsigned int>
PmergeMe::Ford_Johnson_Sort(std::vector<unsigned int> input) {
  size_t n = input.size();

  if (n < 2)
    return input;

  std::vector<std::pair<unsigned int, unsigned int>> pairs;
  for (unsigned int i = 1; i < std::floor(n / 2); i++) {
    if (input[2 * i - 1] <= input[2 * i])
      pairs.emplace_back(input[2 * i - 1], input[2 * i]);
    else
      pairs.emplace_back(input[2 * i], input[2 * i - 1]);
  }

  std::cout << "Num pairs: " << pairs.size() << "\n";
  for (auto it : pairs) {
    std::cout << "First: " << it.first << " " << "Second: " << it.second
              << "\n";
  }

  std::vector<unsigned int> larger;
  for (std::pair<unsigned int, unsigned int> it : pairs) {
    larger.emplace_back(it.second);
  }
  std::vector<unsigned int> sorted_large = Ford_Johnson_Sort(larger);

  unsigned int *leftover = NULL;
  if (n % 2 == 1) {
    leftover = &input[n - 1];
    std::cout << "Leftover: " << *leftover << "\n";
  }

  std::vector<unsigned int> smaller;
  for (std::pair<unsigned int, unsigned int> it : pairs) {
    smaller.emplace_back(it.first);
  }
  std::vector<unsigned int> sorted =
      Merge_Insert_Jacobsthal(sorted_large, smaller);

  // if (leftover) {
  //   sorted.emplace_back(*leftover);
  // }

  return sorted;
}

std::vector<unsigned int>
PmergeMe::Merge_Insert_Jacobsthal(std::vector<unsigned int> sorted_large,
                                  std::vector<unsigned int> smaller) {
  std::vector<unsigned int> res(sorted_large);
  size_t size = smaller.size();

  std::vector<size_t> jacobsthal_nums = generate_jacobsthal_numbers(size);

  for (size_t i = 0; i < size; i++) {
    size_t pos = jacobsthal_nums[i];
    res.emplace(res.begin() + pos, smaller[i]);
  }
  return res;
}

std::vector<size_t> PmergeMe::generate_jacobsthal_numbers(size_t size) {
  std::vector<size_t> res;
  res.emplace_back(0);
  res.emplace_back(1);

  for (size_t i = 2; i < size; i++) {
    res.emplace_back(res[i - 1] + 2 * res[i - 2]);
  }
  return res;
}

size_t PmergeMe::timeToProcess(size_t range) { return range; }
