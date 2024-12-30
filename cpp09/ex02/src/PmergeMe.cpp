#include "PmergeMe.hpp"
#include <cmath>
#include <cstddef>
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

	std::vector<unsigned int> sortedVec = Ford_Johnson_Sort(_inputVector);

	std::cout << "Sorted array size = " << sortedVec.size() << "\n";
	std::cout << "Sorted: ";
	for (const auto &it : sortedVec) {
		std::cout << it << " ";
	}
	std::cout << "\n";
}

PmergeMe::~PmergeMe() {}

std::vector<unsigned int>
PmergeMe::Ford_Johnson_Sort(std::vector<unsigned int> &input) {
	size_t n = input.size();

	if (n < 2)
		return input;

	std::vector<std::pair<unsigned int, unsigned int>> pairs;
	for (size_t i = 0; i < (n / 2); ++i) {
		if (input[2 * i] <= input[2 * i + 1])
			pairs.emplace_back(input[2 * i], input[2 * i + 1]);
		else
			pairs.emplace_back(input[2 * i + 1], input[2 * i]);
	}

	std::cout << "Num pairs: " << pairs.size() << "\n";
	for (auto it : pairs) {
		std::cout << "First: " << it.first << " " << "Second: " << it.second
				  << "\n";
	}

	std::vector<unsigned int> larger;
	std::vector<unsigned int> smaller;
	for (const std::pair<unsigned int, unsigned int> &pair : pairs) {
		larger.emplace_back(pair.second);
		smaller.emplace_back(pair.first);
	}

	std::vector<unsigned int> sortedLarger = Ford_Johnson_Sort(larger);
	std::vector<unsigned int> final = sortedLarger;

	if (!smaller.empty())
		final.insert(final.begin(), smaller[0]);

	std::vector<size_t> insertOrder = generateInsertionOrder(smaller.size());

	std::vector<unsigned int> sorted =
		InsertionSortJacobsthal(final, smaller, insertOrder);

	if (n % 2 == 1) {
		size_t pos = binarySearch(sorted, input.back());
		sorted.insert(sorted.begin() + pos, input.back());
	}

	return sorted;
}

std::vector<unsigned int>
PmergeMe::InsertionSortJacobsthal(std::vector<unsigned int> sorted,
								  std::vector<unsigned int> smaller,
								  std::vector<size_t> insertOrder) {
	for (size_t k : insertOrder) {
			unsigned int elementToInsert = smaller[k];
			size_t pos = binarySearch(sorted, elementToInsert);
			sorted.insert(sorted.begin() + pos, elementToInsert);
	}
	return sorted;
}

std::vector<size_t> PmergeMe::generateInsertionOrder(size_t size) {
	std::vector<unsigned int> jacobsthalNums = generateJacobsthalNums(size);

	std::cout << "Jacobsthal Numbers: ";
	for (const auto &it : jacobsthalNums) {
		std::cout << it << " ";
	}
	std::cout << "\n";

	std::vector<size_t> insertOrder;
	for (size_t i = 2; i < jacobsthalNums.size(); ++i) {
		for (size_t j = jacobsthalNums[i]; j > jacobsthalNums[i - 1] + 1; --j) {
			if (j <= size && j > 1)
				insertOrder.emplace_back(j - 1);
		}
	}

	std::cout << "Insertion order: ";
	for (const auto &it : insertOrder) {
		std::cout << it << " ";
	}
	std::cout << "\n";

	return insertOrder;
}

std::vector<unsigned int> PmergeMe::generateJacobsthalNums(size_t size) {
	std::vector<unsigned int> jacobsthal_nums = {0, 1};

	while (jacobsthal_nums.back() < size) {
		jacobsthal_nums.emplace_back(
			jacobsthal_nums.back() +
			2 * jacobsthal_nums[jacobsthal_nums.size() - 2]);
	}
	return jacobsthal_nums;
}

size_t PmergeMe::binarySearch(std::vector<unsigned int> &arr,
							  unsigned int val) {
	if (arr.empty())
		return 0;

	size_t low = 0;
	size_t high = arr.size();

	while (low < high) {
		size_t mid = low + (high - low) / 2;
		if (arr[mid] < val)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

size_t PmergeMe::timeToProcess(size_t range) { return range; }
