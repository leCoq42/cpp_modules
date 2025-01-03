#include "PmergeMe.hpp"
#include <iostream>

std::list<unsigned int>
PmergeMe::Ford_Johnson_Sort(std::list<unsigned int> &input) {
	size_t n = input.size();

	if (n < 2)
		return input;

	if (n == 2) {
		auto first = input.begin();
		auto second = std::next(first);
		if (*first > *second)
			std::iter_swap(first, second);
		return input;
	}

	auto end = input.end();
	std::list<std::pair<unsigned int, unsigned int>> pairs;
	auto it = input.begin();
	while (it != end && std::next(it) != end) {
		unsigned int first = *it;
		unsigned int second = *std::next(it);
		pairs.emplace_back(std::min(first, second), std::max(first, second));
		std::advance(it, 2);
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

	std::list<unsigned int> larger;
	for (const auto &p : pairs) {
		larger.emplace_back(p.second);
	}

	std::list<unsigned int> sorted = Ford_Johnson_Sort(larger);

#ifdef DEBUG
	std::cout << "Sorted: ";
	for (auto num : sorted) {
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

	std::list<size_t> insertOrder = generateInsertionOrderList(pairs.size());

	sorted = InsertionSortJacobsthal(sorted, pairs, insertOrder);

	if (n % 2 == 1) {
		size_t pos = binarySearch(sorted, input.back());
		auto insertIt = sorted.begin();
		std::advance(insertIt, pos);
		sorted.insert(insertIt, input.back());
	}

#ifdef DEBUG
	std::cout << "Sorted: ";
	for (auto num : sorted) {
		std::cout << num << " ";
	}
	std::cout << "\n" << BORDER << "\n";
#endif

	return sorted;
}

std::list<unsigned int> PmergeMe::InsertionSortJacobsthal(
	std::list<unsigned int> &sorted,
	const std::list<std::pair<unsigned int, unsigned int>> &pairs,
	const std::list<size_t> &insertOrder) {
	for (size_t k : insertOrder) {
		if (k >= pairs.size())
			continue;
		auto it = pairs.begin();
		std::advance(it, k);
		unsigned int elementToInsert = it->first;
		size_t pos = binarySearch(sorted, elementToInsert);
		auto insertIt = sorted.begin();
		std::advance(insertIt, pos);
		sorted.insert(insertIt, elementToInsert);
	}
	return sorted;
}

std::list<size_t> PmergeMe::generateInsertionOrderList(const size_t &size) {
	std::list<unsigned int> jacobsthalNums = generateJacobsthalNumsList(size);

#ifdef DEBUG
	std::cout << "Jacobsthal Numbers: ";
	for (const auto &it : jacobsthalNums) {
		std::cout << it << " ";
	}
	std::cout << "\n";
#endif

	std::list<size_t> insertOrder;
	if (size < 1)
		return insertOrder;

	insertOrder.push_back(0);

	auto it = jacobsthalNums.begin();
	std::advance(it, 2);

	auto prev_it = jacobsthalNums.begin();
	std::advance(prev_it, 1);

	while (it != jacobsthalNums.end()) {
		auto cur = *it;
		auto prev = *prev_it;

		for (size_t j = cur; j > prev; --j) {
			if (j - 1 < size) {
				insertOrder.emplace_back(j - 1);
			}
		}
		++it;
		++prev_it;
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

std::list<unsigned int>
PmergeMe::generateJacobsthalNumsList(const size_t &size) {
	std::list<unsigned int> jacobsthal_nums = {0, 1};

	unsigned int a = 0;
	unsigned int b = 1;
	unsigned int next;

	while (b < size) {
		next = 2 * a + b;
		jacobsthal_nums.emplace_back(next);
		a = b;
		b = next;
	}
	return jacobsthal_nums;
}

size_t PmergeMe::binarySearch(const std::list<unsigned int> &arr,
							  const unsigned int &val) {
	if (arr.empty())
		return 0;

	size_t pos = 0;
	size_t high = arr.size();

	while (pos < high) {
		size_t mid = pos + (high - pos) / 2;
		auto it = arr.begin();
		std::advance(it, mid);

		if (*it < val) {
			pos = mid + 1;
		} else {
			high = mid;
		}
	}
	return pos;
}
