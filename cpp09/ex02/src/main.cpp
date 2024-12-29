#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <input sequence>" << std::endl;
    return 1;
  }
  srand(time(NULL));

  PmergeMe pmergeMe(argv);
  std::cout << "Time to process a range of " << pmergeMe._inputList.size()
            << " elements with std::... : " << 0 << " us" << std::endl;
  std::cout << "Time to process a range of " << pmergeMe._inputVector.size()
            << " elements with std::... : " << 0 << " us " << std::endl;
  return 0;
}
