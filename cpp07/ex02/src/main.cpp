#include <Array.hpp>
#include <iostream>

#define MAX_VAL 750
int main(int, char **) {
  Array<int> numbers(MAX_VAL);
  int *mirror = new int[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    /* int value = i; */
    numbers[i] = value;
    mirror[i] = value;
  }

  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  try {
    numbers[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  for (size_t i = 0; i < numbers.size(); i++) {
    std::cout << numbers[i] << std::endl;
  }

  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }

  delete[] mirror;
  return 0;
}

/* int main() { */
/*   Array<int> a; */
/*   Array<int> b(10); */
/**/
/*   std::cout << "a size: " << a.size() << std::endl; */
/*   std::cout << "b size: " << b.size() << std::endl; */
/*   return 0; */
/* } */
