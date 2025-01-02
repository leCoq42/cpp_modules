#include "PmergeMe.hpp"
#include <iostream>

std::vector<unsigned int>
PmergeMe::Ford_Johnson_Sort(std::vector<unsigned int> &input) {
	size_t n = input.size();

	if (n < 2)
		return input;

	if (n == 2)
	{
		if (input[0] > input[1])
			std::iter_swap(input.begin(), input.begin() + 1);
		return input;
	}

	std::vector<std::pair<unsigned int, unsigned int>> pairs;
	std::vector<unsigned int> larger;
	std::vector<unsigned int> smaller;
	for (size_t i = 0; i < (n / 2); ++i) {
		unsigned int num1 = input[2 * i];
		unsigned int num2 = input[2 * i + 1];
		unsigned int min = std::min(num1, num2);
		unsigned int max = std::max(num1, num2);
		pairs.emplace_back(min, max);
		larger.emplace_back(max);
		smaller.emplace_back(min);
	}

	#ifdef DEBUG
	std::cout << "Num pairs: " << pairs.size() << "\n";
	for (auto it : pairs) {
		std::cout << "Smaller: " << it.first << " " << "Larger: " << it.second
				  << "\n";
	}
	if (n % 2 != 0)
		std::cout << "Leftover: " << input.back() << "\n";
	std::cout << BORDER << "\n";
	#endif

	std::vector<unsigned int> sortedLarger = Ford_Johnson_Sort(larger);
	
	#ifdef DEBUG
	std::cout << "Sorted larger: ";
	for (auto num : sortedLarger) {
		std::cout << num << " ";
	}
	std::cout << "\n";
	#endif

	std::vector<unsigned int> &sortedFinal = sortedLarger;
	if (!smaller.empty()) {
		size_t pos = binarySearch(sortedFinal, smaller[0]);
		sortedFinal.insert(sortedFinal.begin() + pos, smaller[0]);
	}

	#ifdef DEBUG
	std::cout << "Pending: ";
	for (auto num : smaller) {
		std::cout << num << " ";
	}
	std::cout << "\n";
	if (n % 2 != 0)
		std::cout << "Leftover: "<< input.back() << "\n";
	#endif

	std::vector<size_t> insertOrder = generateInsertionOrder(smaller.size());

	sortedFinal = InsertionSortJacobsthal(sortedFinal, smaller, insertOrder);

	if (n % 2 == 1) {
		size_t pos = binarySearch(sortedFinal, input.back());
		sortedFinal.insert(sortedFinal.begin() + pos, input.back());
	}

	#ifdef DEBUG
	std::cout << "sortedFinal: ";
	for (auto num : sortedFinal) {
		std::cout << num << " ";
	}
	std::cout << "\n" << BORDER << "\n";
	#endif

	return sortedFinal;
}

std::vector<unsigned int>
PmergeMe::InsertionSortJacobsthal(std::vector<unsigned int> sorted,
								  std::vector<unsigned int> smaller,
								  std::vector<size_t> insertOrder) {
	for (size_t k : insertOrder) {
		if (k >= smaller.size()) continue;
		unsigned int elementToInsert = smaller[k];
		size_t pos = binarySearch(sorted, elementToInsert);
		sorted.insert(sorted.begin() + pos, elementToInsert);
	}
	return sorted;
}

std::vector<size_t> PmergeMe::generateInsertionOrder(size_t size) {
	std::vector<unsigned int> jacobsthalNums = generateJacobsthalNums(size);

	#ifdef DEBUG
	std::cout << "Jacobsthal Numbers: ";
	for (const auto &it : jacobsthalNums) {
		std::cout << it << " ";
	}
	std::cout << "\n";
	#endif

	std::vector<size_t> insertOrder;
	for (size_t i = 2; i < jacobsthalNums.size(); ++i) {
		for (size_t j = jacobsthalNums[i]; j > jacobsthalNums[i - 1]; --j) {
			if (j - 1 < size && j > 1)
				insertOrder.emplace_back(j - 1);
		}
	}

	#ifdef DEBUG
	std::cout << "Insertion order: ";
	for (const auto &it : insertOrder) {
		std::cout << it << " ";
	}
	std::cout << "\n";
	#endif

	return insertOrder;
}

std::vector<unsigned int> PmergeMe::generateJacobsthalNums(size_t size) {
	std::vector<unsigned int> jacobsthal_nums = {0, 1};

	unsigned int a = 0;
	unsigned int b = 1;
	unsigned int next;

	while (b < size) {
		next = a * 2 + b;
		jacobsthal_nums.emplace_back(next);
		a = b;
		b = next;
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