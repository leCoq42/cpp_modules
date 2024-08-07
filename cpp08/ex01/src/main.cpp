#include "Span.hpp"
#include <numeric>

int main() {
  std::cout << "Span test: ints" << std::endl;
  std::cout << "*---------------------------*" << std::endl;
  Span sp(5);
  try {
    sp.addNumber(-10);
    sp.addNumber(-5);
    sp.addNumber(0);
    sp.addNumber(5);
    sp.addNumber(10);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp.longestSpan() << std::endl;
  std::cout << "*---------------------------*" << std::endl;

  Span sp_big(10000);
  std::vector<int> vec(9999);
  std::iota(vec.begin(), vec.end(), 1);
  sp_big.addRange(vec);
  sp_big.addNumber(-10);
  std::cout << "Shortest span: " << sp_big.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp_big.longestSpan() << std::endl;
  std::cout << "*---------------------------*" << std::endl;

  return 0;
}
