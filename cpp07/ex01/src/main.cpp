#include "iter.hpp"

int main(void) {
	size_t arr_len = 6;

	int arr[6];
	for (size_t i = 0; i < arr_len; ++i) {
		arr[i] = i + 1;
	}
	std::cout << "Before: " << std::endl;
	iter(arr, arr_len, print);
	iter(arr, arr_len, power);
	std::cout << std::endl;

	std::cout << "After: " << std::endl;
	iter(arr, arr_len, print<int>);
	std::cout << std::endl;

	float farr[6];
	for (size_t i = 0; i < arr_len; i++) {
    	farr[i] = i + 1.1f;
	}
	std::cout << "Before: " << std::endl;
	iter(farr, arr_len, print);
	std::cout << std::endl;
	iter(farr, arr_len, power);
	std::cout << "After: " << std::endl;
	iter(farr, arr_len, print);
	std::cout << std::endl;

	std::string sarr[6] = {"hi", "hoi", "hallo", "oi", "ola", "hey"};
	iter(sarr, arr_len, print);
	// iter(farr, arr_len, power);
	// iter(sarr, arr_len, print);

	return 0;
}
