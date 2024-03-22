#include "Span.hpp"
#include <numeric>

int main() {
  std::cout << "Span test: ints" << std::endl;
  Span<int> sp(5);
  try {
    sp.addNumber(-2);
    sp.addNumber(-3);
    sp.addNumber(-23);
    sp.addNumber(5);
    sp.addNumber(11);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp.longestSpan() << std::endl;

  Span<int> sp_big(100);
  std::vector<int> vec(100);
  std::iota(vec.begin(), vec.end(), 1);
  for (int i : vec)
    std::cout << i << std::endl;
  sp_big.addRange(vec);
  std::cout << "Shortest span: " << sp_big.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp_big.longestSpan() << std::endl;

  std::cout << std::endl << "Span test: floats" << std::endl;
  Span<double> sp_float(5);
  try {
    sp_float.addNumber(6.6);
    sp_float.addNumber(3.6);
    sp_float.addNumber(17.1);
    sp_float.addNumber(9.1);
    sp_float.addNumber(11.2);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "Shortest span: " << sp_float.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp_float.longestSpan() << std::endl;
  try {
    sp_float.addNumber(19.2);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  /* std::cout << std::endl << "Span test: strings?" << std::endl; */
  /* Span<std::string> err_arr(5); */
  /* err_arr.addNumber("test"); */
  /* err_arr.addNumber("bla"); */
  /* std::cout << "Shortest span: " << err_arr.shortestSpan() << std::endl; */
  /* std::cout << "Longest span: " << err_arr.longestSpan() << std::endl; */
  return 0;
}
