#include "BitcoinExchange.hpp"
#include <filesystem>

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	std::filesystem::path path{argv[1]};
}
