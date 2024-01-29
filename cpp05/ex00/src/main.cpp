#include "Bureaucrat.hpp"

int main(void) {
  try {
    Bureaucrat Bureacrats[4];
    int numbers[4] = {1, 1, 150, 150};

    for (size_t i = 0; i < 4; i++)
      Bureacrats[i] = Bureaucrat("Henk" + std::to_string(i), numbers[i]);

    /* Bureacrats[0].incrementGrade(); */
    Bureacrats[1].decrementGrade();

    // Bureacrats[2].decrementGrade();
    Bureacrats[3].incrementGrade();

    for (size_t i = 0; i < 4; i++)
      std::cout << Bureacrats[i] << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
