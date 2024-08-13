#include "BitcoinExchange.hpp"
#include <cctype>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>

#define FORMAT "%Y-%m-%d"

BitcoinExchange::BitcoinExchange():
	_dbPath(""), _inputPath("")
{}

BitcoinExchange::BitcoinExchange(std::filesystem::path inPath, std::filesystem::path dbPath):
	_dbPath(dbPath), _inputPath(inPath)
{
	_datetimeMap = parse_database(_dbPath, ",");
	#ifdef DEBUG
	print_database(_datetimeMap);
	#endif
	exchange();

}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src):
	_dbPath(src._dbPath), _inputPath(src._inputPath), _datetimeMap(src._datetimeMap)
{}

// BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
// {}

std::map<std::string, double> BitcoinExchange::parse_database(std::filesystem::path dbPath, std::string delim)
{
	std::map<std::string, double> dbMap;
	std::string	line;
	std::string	key;
	double		value;

	std::ifstream infile;
	infile.open(dbPath, std::ios::in);
	if (infile.is_open()) {
		while (getline(infile, line)) {
			if (!std::isdigit(line[0]))
				continue;
			size_t delim_pos = line.find(delim);
			if (delim_pos == std::string::npos) {
				throw "Error: invalid csv!";
			}
			else {
				key = line.substr(0, delim_pos);
				value = std::atof(line.substr(delim_pos + 1).c_str());
				dbMap.insert({key, value});
			}
		}
	}
	else
		throw "Error: Couldn't open file.";
	return dbMap;
}

std::chrono::system_clock::time_point BitcoinExchange::parseDateTime(const std::string &dateString, const std::string &format)
{
	tm tmStruct = {};
	std::istringstream ss(dateString);
	ss >> std::get_time(&tmStruct, format.c_str());
	return std::chrono::system_clock::from_time_t(mktime(&tmStruct));
}

std::string BitcoinExchange::formatDatetime(const std::chrono::system_clock::time_point &timePoint, const std::string &format)
{
	time_t time = std::chrono::system_clock::to_time_t(timePoint);
	tm *timeinfo = localtime(&time);
	std::vector<char> buff(70);
	strftime(buff.data(), buff.size(), format.c_str(), timeinfo);
	return std::string(buff.begin(), buff.end());
}

void BitcoinExchange::print_database(std::map<std::string, double> db)
{
	for (auto it: db)
		std::cout << "Date: " << it.first << ", price: " << it.second << std::endl;
}

void BitcoinExchange::exchange()
{
	std::string	line;
	std::string	key;
	double		value;

	std::ifstream infile;
	infile.open(_inputPath, std::ios::in);
	if (infile.is_open()) {
		while (getline(infile, line)) {
			if (!std::isdigit(line[0]))
				continue;
			size_t delim_pos = line.find("|");
			if (delim_pos != std::string::npos) {
				key = line.substr(0, delim_pos);
				value = stof(line.substr(delim_pos + 1));
			}
			else {
				key = line.substr(0);
				value = -1;
			}
			std::cout << "Date: " << key << ", amount: " << value << std::endl;

		}
	}
}
