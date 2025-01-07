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

	InsertionSortJacobsthal(result, pairs);

	if (n % 2 == 1) {
		size_t pos =
			binarySearchVec(result, input.back(), 0, result.size() - 1);
		result.insert(result.begin() + pos, input.back());
	}

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

	std::copy(leftArr.begin() + leftIndex, leftArr.end(),
			  pairs.begin() + mergedIndex);
	std::copy(rightArr.begin() + rightIndex, rightArr.end(),
			  pairs.begin() + mergedIndex);
}

void PmergeMe::InsertionSortJacobsthal(
	std::vector<unsigned int> &sorted,
	const std::vector<std::pair<unsigned int, unsigned int>> &pairs) {
	size_t i = 1;
	for (const size_t &k : _insertionOrder) {
		if (k < pairs.size()) {
			// std::cout << "k + i: " << k + i << ", sorted_size = " <<
			// sorted.size()
			// 		  << "\n";
			size_t pos = binarySearchVec(sorted, pairs[k].first, 0, k + i);
			sorted.insert(sorted.begin() + pos, pairs[k].first);
			i++;
		}
	}
}

size_t PmergeMe::binarySearchVec(const std::vector<unsigned int> &arr,
								 unsigned int item, size_t low, size_t high) {
	// for (auto it : arr)
	// 	std::cout << it << " ";
	// std::cout << "\n";
	// std::cout << "low: " << low << ", high: " << high << ", x: " << item
	// 		  << "\n";

	if (high >= arr.size())
		high = arr.size() - 1;
	if (item < arr[low])
		return low;

	while (low <= high) {
		size_t mid = low + (high - low) / 2;
		// std::cout << "low: " << low << ", high: " << high << ", mid: " << mid
		// 		  << ", x: " << item << "\n";

		if (arr[mid] == item)
			return mid;
		if (arr[mid] < item)
			low = mid + 1;
		else
			high = (mid == 0) ? 0 : mid - 1;
	}
	return low;
}
