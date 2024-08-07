#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: ./easyfind <value>" << std::endl;
    return 1;
  }

  std::vector<int> v = {8, 4, 5, 9, 10};
  auto it = easyfind(v, atoi(argv[1]));
  if (it != v.end()) {
    int idx = it - v.begin();
    std::cout << "Value found at index: " << idx << std::endl;
  } else {
    std::cout << "Value not found!" << std::endl;
  }

  return 0;
}
