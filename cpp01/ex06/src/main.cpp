#include "Harl.hpp"

constexpr unsigned int hashfunc(const char *input) {
  unsigned int hash = 0;
  while (*input) {
    hash = hash * 31 + *input++;
  }
  return hash;
}

int main(int argc, char **argv) {

  if (argc != 2)
    return (std::cout << "Error: program takes exactly 1 argument!"
                      << std::endl,
            1);

  Harl harl;
  switch (hashfunc(argv[1])) {
  case hashfunc("DEBUG"):
    harl.complain(0);
    break;
  case hashfunc("INFO"):
    harl.complain(1);
    break;
  case hashfunc("WARNING"):
    harl.complain(2);
    break;
  case hashfunc("ERROR"):
    harl.complain(3);
    break;
  default:
    return (std::cout << "[ " << DEFAULT_MSG << " ]" << std::endl, 0);
  }
  return (0);
}
