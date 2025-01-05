#pragma once

#include <ctime>
#include <filesystem>
#include <map>

class BitcoinExchange {
  public:
	BitcoinExchange(std::filesystem::path inPath, std::filesystem::path dbPath);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

  private:
	std::filesystem::path _dbPath;
	std::filesystem::path _inputPath;
	std::map<std::time_t, double> _datetimeMap;

	void swap(BitcoinExchange &lhs);
	void exchange();
	std::map<std::time_t, double> parse_database(std::filesystem::path dbPath,
												 std::string delim);

	BitcoinExchange();
	void parse_database();
	std::time_t split_keyvalue(double &value, const std::string &line,
							   const size_t &delim_pos);
	std::string formatDatetime(const std::time_t &timePoint,
							   const std::string &format);
	std::time_t parseDateTime(const std::string &dateString,
							  const std::string &format);
	void print_database(std::map<std::time_t, double> db);
};
