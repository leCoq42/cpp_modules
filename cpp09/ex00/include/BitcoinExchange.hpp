#pragma once

#include <cstddef>
#include <filesystem>
#include <map>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(std::string infile);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

private:
	std::filesystem::path _infile;
	std::map<int, size_t> _dateprice;
};
