#include <Array.hpp>
#include <cstddef>
#include <exception>
#include <iostream>

#define MAX_VAL 5
// int main(int, char **) {
//   Array<int> numbers(MAX_VAL);
//   int *mirror = new int[MAX_VAL];
//   srand(time(NULL));
//   for (int i = 0; i < MAX_VAL; i++) {
//     const int value = rand();
//     /* int value = i; */
//     numbers[i] = value;
//     mirror[i] = value;
//   }
//
//   // SCOPE
//   {
//     Array<int> tmp = numbers;
//     Array<int> test(tmp);
//   }
//
//   for (int i = 0; i < MAX_VAL; i++) {
//     if (mirror[i] != numbers[i]) {
//       std::cerr << "didn't save the same value!!" << std::endl;
//       return 1;
//     }
//   }
//   try {
//     numbers[-2] = 0;
//   } catch (const std::exception &e) {
//     std::cerr << e.what() << '\n';
//   }
//   try {
//     numbers[MAX_VAL] = 0;
//   } catch (const std::exception &e) {
//     std::cerr << e.what() << '\n';
//   }
//
//   for (size_t i = 0; i < numbers.size(); i++) {
//     std::cout << numbers[i] << std::endl;
//   }
//
//   for (int i = 0; i < MAX_VAL; i++) {
//     numbers[i] = rand();
//   }
//
//   for (int i = 0; i < MAX_VAL; i++) {
//     if (mirror[i] != numbers[i]) {
//       std::cerr << "didn't save the same value!!" << std::endl;
//       return 1;
//     }
//   }
//
//   delete[] mirror;
//   return 0;
// }

int main() {
  Array<int> nums(MAX_VAL);
  for (size_t i = 0; i < MAX_VAL; i++)
    nums[i] = i;

  std::cout << "[OG]" << std::endl;
  for (size_t i = 0; i < MAX_VAL; i++)
    std::cout << "num[" << i << "] = " << nums[i] << std::endl;

  Array<int> cpy = nums;
  std::cout << "[CPY]" << std::endl;
  for (size_t i = 0; i < MAX_VAL; i++)
    std::cout << "num[" << i << "] = " << cpy[i] << std::endl;

  for (size_t i = 0; i < MAX_VAL; i++)
    nums[i] += 1;

  std::cout << "[OG]" << std::endl;
  for (size_t i = 0; i < MAX_VAL; i++)
    std::cout << "num[" << i << "] = " << nums[i] << std::endl;

  std::cout << "[CPY]" << std::endl;
  for (size_t i = 0; i < MAX_VAL; i++)
    std::cout << "num[" << i << "] = " << cpy[i] << std::endl;

  try {
    std::cout << "This should not work: " << nums[MAX_VAL + 1] << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "undefined error" << std::endl;
  }

  try {
    std::cout << "This should not work: " << nums[-1] << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "undefined error" << std::endl;
  }
}
