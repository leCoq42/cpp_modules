#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
  for (size_t i = 0; i < (sizeof(_lvl_arr) / sizeof(_lvl_arr[0])); i++) {
    if (level == _lvl_arr[i]) {
      (this->*lvl_funcs[i])();
      return;
    }
  }
}

void Harl::debug(void) { std::cout << DEBUG_MSG << std::endl; }

void Harl::info(void) { std::cout << INFO_MSG << std::endl; }

void Harl::warning(void) { std::cout << WARNING_MSG << std::endl; }

void Harl::error(void) { std::cout << ERROR_MSG << std::endl; }
