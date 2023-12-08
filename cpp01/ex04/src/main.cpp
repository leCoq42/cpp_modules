#include "general.hpp"

int main(int argc, char **argv) {
  if (argc != 4)
    return (std::cerr << "Invalid Input: Progam Takes 3 Arguments."
                      << std::endl,
            1);

  const std::string s1 = argv[2];
  if (s1.empty())
    return (std::cerr << "Error: Empty Search String Not Valid!" << std::endl,
            1);
  const std::string s2 = argv[3];

  std::ifstream infile(argv[1]);
  if (!infile)
    return (std::cerr << "Error: Unable To Open Infile!" << std::endl, 1);

  std::ofstream outfile(argv[1] + std::string(".replace"));
  if (!outfile)
    return (infile.close(),
            std::cerr << "Error: Unable To Create Outfile!" << std::endl, 1);

  std::string line;
  while (getline(infile, line)) {
    find_replace(line, s1, s2);
    outfile << line << std::endl;
  }

  infile.close();
  outfile.close();
}

void find_replace(std::string &line, const std::string s1,
                  const std::string s2) {
  size_t pos = 0;

  while ((pos = line.find(s1, pos)) != std::string::npos) {
    line.erase(pos, s1.length());
    line.insert(pos, s2);
    pos += s2.length();
  }
}
