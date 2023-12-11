#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(size_t level) {
  while (level < (sizeof(lvl_arr) / sizeof(lvl_arr[0])))
    (this->*func_ptr_arr[level++])();
  return;
}

void Harl::debug(void) {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout << DEBUG_MSG << std::endl << std::endl;
}

void Harl::info(void) {
  std::cout << "[ INFO ]" << std::endl;
  std::cout << INFO_MSG << std::endl << std::endl;
}

void Harl::warning(void) {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout << WARNING_MSG << std::endl << std::endl;
}

void Harl::error(void) {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << ERROR_MSG << std::endl << std::endl;
}
