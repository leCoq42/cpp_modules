#include "general.hpp"

int main(int argc, char **argv) {
  if (argc != 4)
    return (1);
  std::fstream file;
  file.open(argv[1], ios::in);
  if (!file)
    return (std::cout << "Error: unable to open file!" << std::endl, 1);
}
