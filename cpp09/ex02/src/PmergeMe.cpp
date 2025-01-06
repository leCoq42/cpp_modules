#include "PmergeMe.hpp"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>

PmergeMe::PmergeMe(char **argv) {
	size_t i = 0;

	while (argv[++i] != NULL) {
		_inputList.push_back(atoi(argv[i]));
		_inputVector.push_back(atoi(argv[i]));
	}

	generateInsertionOrder(_inputVector.size() / 2);

#ifdef DEBUG
	std::cout << "Before: ";
	for (auto it : _inputVector)
		std::cout << it << " ";
	std::cout << "\n" << BORDER << "\n";
#endif

// 	std::cout << "Vector sorting: \n";
// 	auto t1 = std::chrono::high_resolution_clock::now();
// 	std::vector<unsigned int> sortedVec = Ford_Johnson_Sort(_inputVector);
// 	auto t2 = std::chrono::high_resolution_clock::now();
// 	auto vec_time_us =
// 		std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
//
// #ifdef DEBUG
// 	std::cout << "After vec: ";
// 	for (const auto &it : sortedVec) {
// 		std::cout << it << " ";
// 	}
// 	std::cout << "\n";
// #endif
//
//
// 	std::cout << "Sorted vec size = " << sortedVec.size() << "\n";
// 	std::cout << "Vec contains dups: " << checkDuplicatesVec(sortedVec) << "\n";
// 	if (std::is_sorted(sortedVec.begin(), sortedVec.end())) {
// 		std::cout << "Verification: The vector is sorted!\n";
// 	} else {
// 		std::cout << "Verification: The vector is NOT sorted.\n";
// 	}
// 	std::cout << "Time to sort(vec): " << double(vec_time_us.count()) / 1000
// 			  << "us\n";
//
// 	std::cout << BORDER << "\n";


	std::cout << "List sorting: \n";
	auto t3 = std::chrono::high_resolution_clock::now();
	std::list<unsigned int> sortedList = Ford_Johnson_Sort(_inputList);
	auto t4 = std::chrono::high_resolution_clock::now();
	auto list_time_us =
		std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3);

#ifdef DEBUG
	std::cout << "After list: ";
	for (const auto &it : sortedList) {
		std::cout << it << " ";
	}
	std::cout << "\n";
#endif

	std::cout << "Sorted list size = " << sortedList.size() << "\n";
	std::cout << "List contains dups: " << checkDuplicatesList(sortedList)
			  << "\n";
	if (std::is_sorted(sortedList.begin(), sortedList.end())) {
		std::cout << "Verification: The list is sorted!\n";
	} else {
		std::cout << "Verification: The list is NOT sorted.\n";
	}
	std::cout << "Time to sort(list): " << double(list_time_us.count()) / 1000
			  << "us\n";
	std::cout << BORDER << "\n";
}

PmergeMe::~PmergeMe() {}

void PmergeMe::generateInsertionOrder(const size_t &size) {
	std::vector<unsigned int> jacobsthalNums = generateJacobsthalNums(size);

	for (size_t i = 3; i < jacobsthalNums.size(); ++i) {
		for (size_t j = jacobsthalNums[i]; j > jacobsthalNums[i - 1]; --j) {
			if (j - 1 < size && j > 1)
				_insertionOrder.emplace_back(j - 1);
		}
	}

	std::cout << "Jacobsthal Numbers: ";
	for (const auto &it : jacobsthalNums) {
		std::cout << it << " ";
	}
	std::cout << "\n";

	std::cout << "Insertion order: ";
	for (const auto &it : _insertionOrder) {
		std::cout << it << " ";
	}
	std::cout << "\n" << BORDER << "\n";
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

bool PmergeMe::checkDuplicatesVec(std::vector<unsigned int> arr) {
	int n = arr.size();

	sort(arr.begin(), arr.end());
	for (int i = 1; i < n; ++i) {
		if (arr[i] == arr[i - 1])
			return true;
	}
	return false;
}

bool PmergeMe::checkDuplicatesList(std::list<unsigned int> arr) {
	if (arr.empty())
		return false;


	arr.sort();
	auto prev = arr.begin();
	auto cur = std::next(arr.begin());

	while (cur != arr.end()) {
		if (*prev == *cur)
			return true;
		prev = cur;
		cur++;
	}
	return false;
}
