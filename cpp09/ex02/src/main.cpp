#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <input sequence>" << std::endl;
		return 1;
	}
	srand(time(NULL));

	PmergeMe pmergeMe(argv);
	return 0;
}
