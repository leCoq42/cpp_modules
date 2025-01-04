#include "PmergeMe.hpp"
#include <iostream>
#include <iterator>

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

	std::list<std::pair<unsigned int, unsigned int>> pairs;
	auto end = input.end();
	auto it = input.begin();
	while (it != end && std::next(it) != end) {
		unsigned int first = *it;
		unsigned int second = *std::next(it);
		pairs.emplace_back(std::min(first, second), std::max(first, second));
		std::advance(it, 2);
	}

	sortPairs(pairs, 0, pairs.size() - 1);

#ifdef DEBUG
	std::cout << "Sorted pairs: " << pairs.size() << "\n";
	for (auto it : pairs) {
		std::cout << "Smaller: " << it.first << " " << "Larger: " << it.second
				  << "\n";
	}
	if (n % 2 != 0)
		std::cout << "Leftover: " << input.back() << "\n";
	std::cout << BORDER << "\n";
#endif

	std::list<unsigned int> result;
	for (const auto &p : pairs)
		result.emplace_back(p.second);

	if (!pairs.empty())
		result.push_front(pairs.front().first);

	std::list<size_t> insertOrder = generateInsertionOrderList(pairs.size());

	result = InsertionSortJacobsthal(result, pairs, insertOrder);

	if (n % 2 == 1) {
		unsigned int pending = *std::prev(input.end());
		auto pos =
			binarySearchList(result, pending, result.begin(), result.end());
		result.insert(pos, input.back());
	}

#ifdef DEBUG
	std::cout << "Sorted: ";
	for (auto num : result) {
		std::cout << num << " ";
	}
	std::cout << "\n" << BORDER << "\n";
#endif

	return result;
}

void PmergeMe::sortPairs(
	std::list<std::pair<unsigned int, unsigned int>> &pairs,
	const unsigned int begin, const unsigned int end) {
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	sortPairs(pairs, begin, mid);
	sortPairs(pairs, mid + 1, end);
	mergePairs(pairs, begin, mid, end);
}

void PmergeMe::mergePairs(
	std::list<std::pair<unsigned int, unsigned int>> &pairs,
	const unsigned int left, const unsigned int mid, const unsigned int right) {

	std::list<std::pair<unsigned int, unsigned int>> result;

	auto leftIt = pairs.begin();
	std::advance(leftIt, left);

	auto midIt = pairs.begin();
	std::advance(midIt, mid + 1);

	auto rightIt = pairs.begin();
	std::advance(rightIt, right + 1);

	auto leftCurrent = leftIt;
	auto rightCurrent = rightIt;

	while (leftCurrent != midIt && rightCurrent != rightIt) {
		if (leftCurrent->second <= rightCurrent->second) {
			result.push_back(*leftCurrent);
			++leftCurrent;
		} else {
			result.push_back(*rightCurrent);
			++rightCurrent;
		}
	}

	while (leftCurrent != midIt) {
		result.push_back(*leftCurrent);
		++leftCurrent;
	}
	while (rightCurrent != rightIt) {
		result.push_back(*rightCurrent);
		++rightCurrent;
	}

	auto targetIt = leftIt;
	for (const auto &p : result) {
		*targetIt = p;
		++targetIt;
	}
}

std::list<unsigned int> PmergeMe::InsertionSortJacobsthal(
	std::list<unsigned int> &sorted,
	const std::list<std::pair<unsigned int, unsigned int>> &pairs,
	const std::list<size_t> &insertOrder) {
	for (size_t k : insertOrder) {
		auto low = sorted.begin();
		auto high = sorted.begin();
		std::advance(high, k);

		auto pending = pairs.begin();
		std::advance(pending, k);

		unsigned int elementToInsert = pending->first;

		auto pos = binarySearchList(sorted, elementToInsert, low, high);
		sorted.insert(pos, elementToInsert);
	}
	return sorted;
}

std::list<size_t> PmergeMe::generateInsertionOrderList(const size_t &size) {
	std::list<unsigned int> jacobsthalNums = generateJacobsthalNumsList(size);

	std::list<size_t> insertOrder;
	if (size < 1)
		return insertOrder;

	auto it = jacobsthalNums.begin();
	std::advance(it, 3);

	auto prev_it = jacobsthalNums.begin();
	std::advance(prev_it, 2);

	while (it != jacobsthalNums.end()) {
		auto cur = *it;
		auto prev = *prev_it;

		for (size_t j = cur; j > prev; --j) {
			if (j - 1 < size && j > 1) {
				insertOrder.emplace_back(j - 1);
			}
		}
		++it;
		++prev_it;
	}

#ifdef DEBUG
	std::cout << "Jacobsthal Numbers: ";
	for (const auto &it : jacobsthalNums) {
		std::cout << it << " ";
	}
	std::cout << "\n";
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

std::list<unsigned int>::iterator
PmergeMe::binarySearchList(std::list<unsigned int> &arr, unsigned int item,
						   std::list<unsigned int>::iterator low,
						   std::list<unsigned int>::iterator high) {
	if (std::distance(low, high) <= 0)
		return (item > *low) ? std::next(low) : low;

	auto mid = low;
	std::advance(mid, std::distance(low, high) / 2);

	if (item == *mid)
		return std::next(mid);

	if (item > *mid)
		return binarySearchList(arr, item, std::next(mid), high);
	return binarySearchList(arr, item, low, mid);
}
