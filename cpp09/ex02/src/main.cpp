#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <input sequence>" << std::endl;
		return 1;
	}
	std::cout << "Before: " << argv[1] << std::endl;
	std::cout << "After: " << argv[1] << std::endl;
	std::cout << "Time to process a range of 3000 elements with std::... : " << PmergeMe::timeToProcess(3000) << " us" << std::endl;
	std::cout << "Time to process a range of 3000 elements with std::... : " << PmergeMe::timeToProcess(3000) << " us" << std::endl;
	return 0;
}
