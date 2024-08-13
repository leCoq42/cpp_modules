#include "BitcoinExchange.hpp"
#include <filesystem>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	std::filesystem::path inPath{argv[1]};
	std::filesystem::path dbPath = "./cpp_09/data.csv";
	BitcoinExchange exchange(inPath, dbPath);
}
