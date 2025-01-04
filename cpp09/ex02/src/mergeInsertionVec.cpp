#include "PmergeMe.hpp"
#include <cstddef>
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
	for (size_t i = 0; i < (n / 2); ++i) {
		unsigned int min = std::min(input[2 * i], input[2 * i + 1]);
		unsigned int max = std::max(input[2 * i], input[2 * i + 1]);
		pairs.emplace_back(min, max);
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

	std::vector<unsigned int> result;
	for (const auto &pair : pairs)
		result.emplace_back(pair.second);

	if (!pairs.empty())
		result.insert(result.begin(), pairs[0].first);

	std::vector<size_t> insertOrder = generateInsertionOrder(pairs.size());

	result = InsertionSortJacobsthal(result, pairs, insertOrder);

	if (n % 2 == 1) {
		size_t pos =
			binarySearchVec(result, input.back(), 0, result.size() - 1);
		result.insert(result.begin() + pos, input.back());
	}

#ifdef DEBUG
	std::cout << "sorted: ";
	for (auto num : result) {
		std::cout << num << " ";
	}
	std::cout << "\n" << BORDER << "\n";
#endif

	return result;
}

void PmergeMe::sortPairs(
	std::vector<std::pair<unsigned int, unsigned int>> &pairs,
	const unsigned int begin, const unsigned int end) {
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	sortPairs(pairs, begin, mid);
	sortPairs(pairs, mid + 1, end);
	mergePairs(pairs, begin, mid, end);
}

void PmergeMe::mergePairs(
	std::vector<std::pair<unsigned int, unsigned int>> &pairs,
	const unsigned int left, const unsigned int mid, const unsigned int right) {
	const size_t leftLen = mid - left + 1;
	const size_t rightLen = right - mid;

	std::vector<std::pair<unsigned int, unsigned int>> leftArr;
	std::vector<std::pair<unsigned int, unsigned int>> rightArr;

	for (size_t i = 0; i < leftLen; ++i) {
		leftArr.emplace_back(pairs[left + i]);
	}
	for (size_t i = 0; i < rightLen; ++i) {
		rightArr.emplace_back(pairs[mid + 1 + i]);
	}

	size_t leftIndex = 0;
	size_t rightIndex = 0;
	size_t mergedIndex = left;

	while (leftIndex < leftLen && rightIndex < rightLen) {
		if (leftArr[leftIndex].second <= rightArr[rightIndex].second) {
			pairs[mergedIndex] = leftArr[leftIndex];
			++leftIndex;
		} else {
			pairs[mergedIndex] = rightArr[rightIndex];
			++rightIndex;
		}
		++mergedIndex;
	}

	std::copy(leftArr.begin() + leftIndex, leftArr.end(), pairs.begin() + mergedIndex);
    std::copy(rightArr.begin() + rightIndex, rightArr.end(), pairs.begin() + mergedIndex);
}

std::vector<unsigned int> PmergeMe::InsertionSortJacobsthal(
	std::vector<unsigned int> &sorted,
	const std::vector<std::pair<unsigned int, unsigned int>> &pairs,
	const std::vector<size_t> &insertOrder) {
	for (const size_t &k : insertOrder) {
		size_t pos = binarySearchVec(sorted, pairs[k].first, 0, k);
		sorted.insert(sorted.begin() + pos, pairs[k].first);
	}
	return sorted;
}

std::vector<size_t> PmergeMe::generateInsertionOrder(const size_t &size) {
	std::vector<unsigned int> jacobsthalNums = generateJacobsthalNums(size);

	std::vector<size_t> insertOrder;
	for (size_t i = 3; i < jacobsthalNums.size(); ++i) {
		for (size_t j = jacobsthalNums[i]; j > jacobsthalNums[i - 1]; --j) {
			if (j - 1 < size && j > 1)
				insertOrder.emplace_back(j - 1);
		}
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

size_t PmergeMe::binarySearchVec(std::vector<unsigned int> &res,
								 unsigned int item, size_t low, size_t high) {
	if (high <= low)
		return (item > res[low]) ? (low + 1) : low;

	size_t mid = (low + high) / 2;

	if (item == res[mid])
		return mid + 1;

	if (item > res[mid])
		return binarySearchVec(res, item, mid + 1, high);

	return binarySearchVec(res, item, low, mid);
}
