#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <vector>

#define FORMAT "%Y-%m-%d "

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

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	BitcoinExchange tmp(rhs);
	tmp.swap(*this);
	return *this;
}

void BitcoinExchange::swap(BitcoinExchange &lhs)
{
	std::swap(_datetimeMap, lhs._datetimeMap);
	std::swap(_inputPath, lhs._inputPath);
	std::swap(_dbPath, lhs._dbPath);
}

std::map<std::time_t, double> BitcoinExchange::parse_database(std::filesystem::path dbPath, std::string delim)
{
	std::map<std::time_t, double>	dbMap;
	std::string						line;
	std::time_t						key;
	double							value;
	std::ifstream					infile;

	infile.open(dbPath, std::ios::in);
	if (infile.is_open()) {
		while (getline(infile, line)) {
			if (!std::isdigit(line[0]))
				continue;
			size_t delim_pos = line.find(delim);
			if (delim_pos == std::string::npos)
				throw "Error: invalid csv.";
			else {
				key = split_keyvalue(value, line, delim_pos);
				if (key < 0)
					continue;
				dbMap.insert({key, value});
			}
		}
	}
	else
		throw "Error: Couldn't open file.";
	return dbMap;
}

std::time_t BitcoinExchange::parseDateTime(const std::string &dateString, const std::string &format)
{
	std::tm t = {};
	time_t time;
	std::istringstream ss(dateString);
	ss >> std::get_time(&t, format.c_str());
	if (ss.fail())
		return -1;
	time = mktime(&t);
	return time;
}

std::string BitcoinExchange::formatDatetime(const std::time_t &timePoint, const std::string &format)
{
	tm *timeinfo = localtime(&timePoint);
	std::vector<char> buff(70);
	strftime(buff.data(), buff.size(), format.c_str(), timeinfo);
	return std::string(buff.begin(), buff.end());
}

void BitcoinExchange::print_database(std::map<time_t, double> db)
{
	for (auto it: db)
		std::cout << "Date: " << formatDatetime(it.first, FORMAT) << ", price: " << it.second << std::endl;
}

std::time_t	BitcoinExchange::split_keyvalue(double &value, const std::string &line, const size_t &delim_pos)
{
	time_t key;

	key = parseDateTime(line.substr(0, delim_pos), FORMAT);
	if (key == -1) {
		std::cerr << "Error: invalid date => " << line.substr(0, delim_pos) << std::endl;
		return -1;
	}
	try {
		value = std::stof(line.substr(delim_pos + 1));
	}
	catch (const std::invalid_argument &e) {
		std::cerr << "Invalid amount:" << e.what() << std::endl;
		return -1;
	}
	catch (const std::out_of_range &e) {
		std::cerr << "Over/underflow error: " << e.what() << std::endl;
		return -1;
	}
	return key;
}

void BitcoinExchange::exchange()
{
	std::string		line;
	std::time_t		key;
	double			value;
	double			price;
	std::ifstream	infile;

	infile.open(_inputPath, std::ios::in);
	if (infile.is_open()) {
		while (getline(infile, line)) {
			if (!std::isdigit(line[0]))
				continue;
			size_t delim_pos = line.find("|");
			if (delim_pos != std::string::npos) {
				key = split_keyvalue(value, line, delim_pos);
				if (key < 0)
					continue;
				if (value > 1000) {
					std::cerr << "Error: too large a number." << std::endl;
					continue;
				}
				if (value < 0) {
					std::cerr << "Error: not a positive number." << std::endl;
					continue;
				}
				auto res = _datetimeMap.find(key);
				if (res != _datetimeMap.end())
					price = res->second;
				else {
					res = _datetimeMap.lower_bound(key);
					if (res != _datetimeMap.begin()) {
						res--;
						price = res->second;
					}
				}
				#ifdef DEBUG
				std::cout << "Bound date: " << formatDatetime(res->first, FORMAT) << ", bound price: " << res->second << std::endl;
				#endif
				std::cout << formatDatetime(key, FORMAT) << " => " << value << " = " << (value * price) << std::endl;
			}
			else {
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}
		}
	}
}
