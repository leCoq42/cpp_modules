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
	std::list<unsigned int> Ford_Johnson_Sort(std::list<unsigned int> &input);

	std::vector<unsigned int> InsertionSortJacobsthal(
		std::vector<unsigned int> &sorted,
		const std::vector<std::pair<unsigned int, unsigned int>> &pairs,
		const std::vector<size_t> &insertOrder);
	std::list<unsigned int> InsertionSortJacobsthal(
		std::list<unsigned int> &sorted,
		const std::list<std::pair<unsigned int, unsigned int>> &pairs,
		const std::list<size_t> &insertOrder);

	std::vector<size_t> generateInsertionOrder(const size_t &size);
	std::list<size_t> generateInsertionOrderList(const size_t &size);

	size_t binarySearch(const std::list<unsigned int> &arr,
						const unsigned int &val);

	std::vector<unsigned int> generateJacobsthalNums(const size_t &size);
	std::list<unsigned int> generateJacobsthalNumsList(const size_t &size);

	bool checkDuplicatesVec(std::vector<unsigned int> &arr);
	bool checkDuplicatesList(std::list<unsigned int> &arr);
};
