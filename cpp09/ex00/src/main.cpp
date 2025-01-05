#include "BitcoinExchange.hpp"
#include <filesystem>
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	std::filesystem::path inPath{argv[1]};
	std::filesystem::path dbPath = "data.csv";
	try {
		BitcoinExchange exchange(inPath, dbPath);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
