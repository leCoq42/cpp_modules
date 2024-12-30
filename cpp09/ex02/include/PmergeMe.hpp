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

	std::vector<unsigned int>
	Ford_Johnson_Sort(std::vector<unsigned int> &input);

	std::vector<unsigned int>
	InsertionSortJacobsthal(std::vector<unsigned int> sorted,
							std::vector<unsigned int> smaller,
							std::vector<size_t> insertOrder);

	std::vector<size_t> generateInsertionOrder(size_t size);
	size_t binarySearch(std::vector<unsigned int> &arr, unsigned int val);

	std::vector<unsigned int> generateJacobsthalNums(size_t size);
};
