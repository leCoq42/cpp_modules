#include "iter.hpp"
#include <iostream>

int main(void) {
	size_t arr_len = 6;

	int arr[6];
	for (size_t i = 0; i < arr_len; ++i) {
		arr[i] = i + 1;
	}
	iter(arr, arr_len, std::function<void(int&)>(print<int>));
	std::cout << std::endl;

	float farr[6];
	for (size_t i = 0; i < arr_len; i++) {
    	farr[i] = i + 1.1f;
	}
	iter(farr, arr_len, std::function<void(float&)>(print<float>));
	std::cout << std::endl;
	
	std::string sarr[3] = {"hi", "hoi", "hey"};
	iter(sarr, 3, print<std::string>);
	std::cout << std::endl;

	return 0;
}
