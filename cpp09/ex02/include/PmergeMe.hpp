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
	std::vector<size_t> _insertionOrder;

	void generateInsertionOrder(const size_t &size);

	// Vector functions
	std::vector<unsigned int>
	Ford_Johnson_Sort(std::vector<unsigned int> &input);
	void sortPairs(std::vector<std::pair<unsigned int, unsigned int>> &pairs,
				   const unsigned int begin, const unsigned int end);
	void mergePairs(std::vector<std::pair<unsigned int, unsigned int>> &pairs,
					const unsigned int begin, const unsigned int mid,
					const unsigned int end);
	void InsertionSortJacobsthal(
		std::vector<unsigned int> &sorted,
		const std::vector<std::pair<unsigned int, unsigned int>> &pairs);
	size_t binarySearchVec(const std::vector<unsigned int> &arr, unsigned int item,
						   size_t low, size_t high);
	std::vector<unsigned int> generateJacobsthalNums(const size_t &size);
	bool checkDuplicatesVec(std::vector<unsigned int> arr);

	// List functions
	std::list<unsigned int> Ford_Johnson_Sort(std::list<unsigned int> &input);
	void sortPairs(std::list<std::pair<unsigned int, unsigned int>> &pairs,
				   const unsigned int begin, const unsigned int end);
	void mergePairs(std::list<std::pair<unsigned int, unsigned int>> &pairs,
					const unsigned int left, const unsigned int mid,
					const unsigned int right);
	std::list<unsigned int> InsertionSortJacobsthal(
		std::list<unsigned int> &sorted,
		const std::list<std::pair<unsigned int, unsigned int>> &pairs);
	std::list<unsigned int>::iterator
	// binarySearchList(const std::list<unsigned int> &arr, unsigned int item,
	// 				 std::list<unsigned int>::iterator low,
	// 				 std::list<unsigned int>::iterator high);
		binarySearchList(unsigned int item,
					 std::list<unsigned int>::iterator low,
					 std::list<unsigned int>::iterator high);
	bool checkDuplicatesList(std::list<unsigned int> arr);
};
