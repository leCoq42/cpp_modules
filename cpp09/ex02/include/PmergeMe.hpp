#pragma once

#include <cstddef>
#include <list>
#include <vector>

#define BORDER "----------------------------------------"

class PmergeMe {
  public:
	PmergeMe(char **argv);
	~PmergeMe();


  private:
	PmergeMe();
	std::list<unsigned int> _inputList;
	std::vector<unsigned int> _inputVector;

	std::vector<unsigned int>
	Ford_Johnson_Sort(std::vector<unsigned int> &input);
	std::list<unsigned int>
	Ford_Johnson_Sort(std::list<unsigned int> &input);

	std::vector<unsigned int>
	InsertionSortJacobsthal(std::vector<unsigned int> sorted,
							std::vector<unsigned int> smaller,
							std::vector<size_t> insertOrder);
	std::list<unsigned int>
	InsertionSortJacobsthal(std::list<unsigned int> &sorted,
									std::list<std::pair<unsigned int, unsigned int>> &pairs,
									std::list<size_t> &insertOrder);
							

	std::vector<size_t> generateInsertionOrder(size_t size);
	std::list<size_t> generateInsertionOrderList(size_t size);

	size_t binarySearch(std::vector<unsigned int> &arr, unsigned int val);
	size_t binarySearch(std::list<unsigned int> &arr, unsigned int val);

	std::vector<unsigned int> generateJacobsthalNums(size_t size);
	std::list<unsigned int> generateJacobsthalNumsList(size_t size);

	bool checkDuplicatesVec(std::vector<unsigned int> &arr);
	bool checkDuplicatesList(std::list<unsigned int> &arr);
};
