#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2)
		return 1;
	try {
		RPN rpn(argv[1]);
		std::cout << rpn.getResult() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
