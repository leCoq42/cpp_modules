#include "PmergeMe.hpp"
#include <iostream>

std::vector<unsigned int>
PmergeMe::Ford_Johnson_Sort(std::vector<unsigned int> &input) {
	size_t n = input.size();

	if (n < 2)
		return input;

	if (n == 2) {
		if (input[0] > input[1])
			std::swap(input[0], input[1]);
		return input;
	}

	std::vector<std::pair<unsigned int, unsigned int>> pairs;
	std::vector<unsigned int> larger;

	for (size_t i = 0; i < (n / 2); ++i) {
		unsigned int min = std::min(input[2 * i], input[2 * i + 1]);
		unsigned int max = std::max(input[2 * i], input[2 * i + 1]);
		pairs.emplace_back(min, max);
		larger.emplace_back(max);
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
	std::cout << "Pending: ";
	for (auto p : pairs) {
		std::cout << p.first << " ";
	}
	std::cout << "\n";
	if (n % 2 != 0)
		std::cout << "Leftover: " << input.back() << "\n";
#endif

	if (!pairs.empty()) {
		auto pos = std::lower_bound(sortedLarger.begin(), sortedLarger.end(),
									pairs[0].first);
		sortedLarger.insert(pos, pairs[0].first);
	}

	std::vector<size_t> insertOrder = generateInsertionOrder(pairs.size());

	sortedLarger = InsertionSortJacobsthal(sortedLarger, pairs, insertOrder);

	if (n % 2 == 1) {
		auto pos = std::lower_bound(sortedLarger.begin(), sortedLarger.end(),
									input.back());
		sortedLarger.insert(pos, input.back());
	}

#ifdef DEBUG
	std::cout << "sorted: ";
	for (auto num : sortedLarger) {
		std::cout << num << " ";
	}
	std::cout << "\n" << BORDER << "\n";
#endif

	return sortedLarger;
}

std::vector<unsigned int> PmergeMe::InsertionSortJacobsthal(
	std::vector<unsigned int> &sorted,
	const std::vector<std::pair<unsigned int, unsigned int>> &pairs,
	const std::vector<size_t> &insertOrder) {
	for (const size_t &k : insertOrder) {
		if (k >= pairs.size())
			continue;
		auto pos =
			std::lower_bound(sorted.begin(), sorted.end(), pairs[k].first);
		sorted.insert(pos, pairs[k].first);
	}
	return sorted;
}

std::vector<size_t> PmergeMe::generateInsertionOrder(const size_t &size) {
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

std::vector<unsigned int> PmergeMe::generateJacobsthalNums(const size_t &size) {
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
