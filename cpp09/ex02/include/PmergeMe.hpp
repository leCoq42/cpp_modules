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

	void sortPairs(std::vector<std::pair<unsigned int, unsigned int>> &pairs,
				   const unsigned int begin, const unsigned int end);
	void sortPairs(std::list<std::pair<unsigned int, unsigned int>> &pairs,
				   const unsigned int begin, const unsigned int end);
	void mergePairs(std::vector<std::pair<unsigned int, unsigned int>> &pairs,
					const unsigned int begin, const unsigned int mid,
					const unsigned int end);
	void mergePairs(std::list<std::pair<unsigned int, unsigned int>> &pairs,
					const unsigned int left, const unsigned int mid,
					const unsigned int right);

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

	// size_t binarySearch(const std::list<unsigned int> &arr,
	// 					const unsigned int &val);

	size_t binarySearchVec(std::vector<unsigned int> &res, unsigned int item,
						   size_t low, size_t high);

	std::list<unsigned int>::iterator
	binarySearchList(std::list<unsigned int> &arr, unsigned int item,
					 std::list<unsigned int>::iterator low,
					 std::list<unsigned int>::iterator high);

	std::vector<unsigned int> generateJacobsthalNums(const size_t &size);
	std::list<unsigned int> generateJacobsthalNumsList(const size_t &size);

	bool checkDuplicatesVec(std::vector<unsigned int> &arr);
	bool checkDuplicatesList(std::list<unsigned int> &arr);
};
