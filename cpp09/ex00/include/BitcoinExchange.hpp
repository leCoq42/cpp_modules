#pragma once

#include <chrono>
#include <ctime>
#include <filesystem>
#include <map>

class BitcoinExchange {
public:
  BitcoinExchange();
  BitcoinExchange(std::filesystem::path inPath, std::filesystem::path dbPath);
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &src);
  BitcoinExchange &operator=(const BitcoinExchange &rhs);

private:
  std::filesystem::path _dbPath;
  std::filesystem::path _inputPath;
  std::map<std::string, double> _datetimeMap;
  std::map<std::string, double> _inputMap;

  void exchange();
  std::map<std::string, double> parse_database(std::filesystem::path dbPath,
                                               std::string delim);
  void parse_database();
  std::string
  formatDatetime(const std::chrono::system_clock::time_point &timePoint,
                 const std::string &format);
  std::chrono::system_clock::time_point
  parseDateTime(const std::string &dateString, const std::string &format);
  void print_database(std::map<std::string, double> db);
};
