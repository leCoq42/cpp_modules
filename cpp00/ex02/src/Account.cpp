#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) {}

Account::Account(int initial_deposit) {
  this->_accountIndex = _nbAccounts;
  this->_amount = initial_deposit;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;
  _nbAccounts++;
  _totalAmount += initial_deposit;
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "created" << std::endl;
}

Account::~Account(void) {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void) { return (_nbAccounts); }

int Account::getTotalAmount(void) { return (_totalAmount); }

int Account::getNbDeposits(void) { return (_totalNbDeposits); }

int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";";
  std::cout << "total:" << getTotalAmount() << ";";
  std::cout << "deposits:" << getNbDeposits() << ";";
  std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
  _totalAmount += deposit;
  _totalNbDeposits++;
  this->_amount += deposit;
  this->_nbDeposits++;

  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << this->_amount - deposit << ";";
  std::cout << "deposit:" << deposit << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {

  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << this->_amount << ";";
  if (this->_amount - withdrawal < 0) {
    std::cout << "withdrawal:refused" << std::endl;
    return (false);
  }
  _totalAmount -= withdrawal;
  _totalNbWithdrawals++;
  this->_amount -= withdrawal;
  this->_nbWithdrawals++;
  std::cout << "withdrawal:" << withdrawal << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
  return (true);
}

int Account::checkAmount(void) const { return (this->_amount); }

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "deposits:" << this->_nbDeposits << ";";
  std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
  std::time_t t = std::time(nullptr);
  std::cout << std::put_time(std::localtime(&t), "[%Y%m%d_%H%M%S] ");
}
