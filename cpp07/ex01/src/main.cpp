#include "iter.hpp"

int main(void) {
  int arr_len = 6;

  int arr[arr_len];
  for (int i = 0; i < arr_len; ++i) {
    arr[i] = i + 1;
  }
  iter(arr, arr_len, power);
  for (int i = 0; i < arr_len; i++) {
    std::cout << arr[i] << std::endl;
  }

  float farr[arr_len];
  for (int i = 0; i < arr_len; i++) {
    farr[i] = i + 1.1;
  }
  iter(farr, arr_len, power);
  for (int i = 0; i < arr_len; i++) {
    std::cout << farr[i] << std::endl;
  }

  return 0;
}
