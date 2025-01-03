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

	sortPairs(pairs, 0, pairs.size() - 1);

#ifdef DEBUG
	std::cout << "Num sorted pairs: " << pairs.size() << "\n";
	for (auto it : pairs) {
		std::cout << "Smaller: " << it.first << " " << "Larger: " << it.second
				  << "\n";
	}
	if (n % 2 != 0)
		std::cout << "Leftover: " << input.back() << "\n";
#endif

	std::list<unsigned int> result;
	for (const auto &p : pairs)
		result.emplace_back(p.second);

	std::list<size_t> insertOrder = generateInsertionOrderList(pairs.size());

	result = InsertionSortJacobsthal(result, pairs, insertOrder);

	if (n % 2 == 1) {
		size_t pos = binarySearch(result, input.back());
		auto insertIt = result.begin();
		std::advance(insertIt, pos);
		result.insert(insertIt, input.back());
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

	std::vector<std::pair<unsigned int, unsigned int>> leftList(leftIt, midIt);
	std::vector<std::pair<unsigned int, unsigned int>> rightList(midIt, rightIt);

	auto leftCurrent = leftList.begin();
    auto rightCurrent = rightList.begin();

	while (leftCurrent != leftList.end() && rightCurrent != rightList.end()) {
		if (leftCurrent->second <= rightCurrent->second) {
			result.push_back(*leftCurrent);
			++leftCurrent;
		} else {
			result.push_back(*rightCurrent);
			++rightCurrent;
		}
	}

	result.insert(result.end(), leftCurrent, leftList.end());
    result.insert(result.end(), rightCurrent, rightList.end());

    auto targetIt = pairs.begin();
    std::advance(targetIt, left);
    auto sourceIt = result.begin();

	while (sourceIt != result.end()) {
        *targetIt = *sourceIt;
        ++targetIt;
        ++sourceIt;
    }
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
