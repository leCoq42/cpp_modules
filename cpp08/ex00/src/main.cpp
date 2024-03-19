#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: ./easyfind <value>" << std::endl;
    return 1;
  }

  std::vector<int> v = {8, 4, 5, 9, 10};
  try {
    int i = easyfind(v, atoi(argv[1]));
    std::cout << "Value found at index: " << i << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
