#include "Bureaucrat.hpp"

int main(void) {
  try {
    Bureaucrat Bureaucrats[4];
    int numbers[4] = {1, 1, 150, 150};

    for (size_t i = 0; i < 4; i++)
      Bureaucrats[i] = Bureaucrat("Henk" + std::to_string(i), numbers[i]);

    /* Bureaucrats[0].incrementGrade(); */
    Bureaucrats[1].decrementGrade();

    /* Bureaucrats[2].decrementGrade(); */
    Bureaucrats[3].incrementGrade();

    for (size_t i = 0; i < 4; i++)
      std::cout << Bureaucrats[i] << std::endl;

    Bureaucrat Joe(Bureaucrats[0]);
    std::cout << Joe << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
