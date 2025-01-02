#include "PmergeMe.hpp"
#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>

PmergeMe::PmergeMe(char **argv) {
	if (!argv || !*argv)
        throw std::invalid_argument("Invalid input");

	size_t i = 0;

	while (argv[++i] != NULL) {
		_inputList.push_back(atoi(argv[i]));
		_inputVector.push_back(atoi(argv[i]));
	}

	// #ifdef DEBUG
	std::cout << "Before: ";
	for (auto it: _inputVector)
		std::cout << it << " ";
	std::cout << "\n" << BORDER << "\n";
	// #endif

	auto t1 = std::chrono::high_resolution_clock::now();
	std::vector<unsigned int> sortedVec = Ford_Johnson_Sort(_inputVector);
	auto t2 = std::chrono::high_resolution_clock::now();
	auto vec_time_us = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);

	auto t3 = std::chrono::high_resolution_clock::now();
	std::list<unsigned int> sortedList = Ford_Johnson_Sort(_inputList);
	auto t4 = std::chrono::high_resolution_clock::now();
	auto list_time_us = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3);

	std::cout << BORDER << "\n";
	#ifdef DEBUG
	std::cout << "After: ";
	for (const auto &it : sortedList) {
		std::cout << it << " ";
	}
	std::cout << "\n";
	#endif

	std::cout << "Sorted vec size = " << sortedVec.size() << "\n";
	std::cout << "Vec contains dups: " << checkDuplicatesVec(sortedVec) << "\n";
	if (std::is_sorted(sortedVec.begin(), sortedVec.end())) {
        std::cout << "Verification: The vector is sorted!\n";
    } else {
        std::cout << "Verification: The vector is NOT sorted.\n";
    }
	std::cout << "Time to sort(vec): " << vec_time_us.count() << "us\n";

	std::cout << BORDER << "\n";

	std::cout << "Sorted list size = " << sortedList.size() << "\n";
	std::cout << "List contains dups: " << checkDuplicatesList(sortedList) << "\n";
	if (std::is_sorted(sortedList.begin(), sortedList.end())) {
        std::cout << "Verification: The list is sorted!\n";
    } else {
        std::cout << "Verification: The list is NOT sorted.\n";
    }
	std::cout << "Time to sort(list): " << list_time_us.count() << "us\n";
	std::cout << BORDER << "\n";
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::checkDuplicatesVec(std::vector<unsigned int> &arr) {
  	int n = arr.size();
  	
    sort(arr.begin(), arr.end());
    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i - 1])
            return true;
    }
    return false;
}

bool PmergeMe::checkDuplicatesList(std::list<unsigned int> &arr) {
	if (arr.empty())
		return false;
  	
    arr.sort();
	auto prev = arr.begin();
	auto cur = std::next(arr.begin());
	
	while (cur != arr.end())
	{
		if (*prev == *cur)
			return true;
		prev = cur;
		cur++;
	}
    return false;
}

