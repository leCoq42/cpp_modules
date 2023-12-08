#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
  for (size_t i = 0; i < sizeof(lvl_arr); i++) {
    if (level == lvl_arr[i]) {
      (this->*func_ptr_arr[i])();
      return;
    }
  }
}

void Harl::debug(void) { std::cout << DEBUG_MSG << std::endl; }

void Harl::info(void) { std::cout << INFO_MSG << std::endl; }

void Harl::warning(void) { std::cout << WARNING_MSG << std::endl; }

void Harl::error(void) { std::cout << ERROR_MSG << std::endl; }
