#include "Bureaucrat.hpp"

int main(void) {
  try {
    Bureaucrat Bureaucrats[4];
    int numbers[4] = {1, 1, 150, 150};

    for (size_t i = 0; i < 4; i++)
      Bureaucrats[i] = Bureaucrat("Henk" + std::to_string(i), numbers[i]);

    Bureaucrats[0].decrementGrade();
    /* Bureaucrats[1].incrementGrade(); */

    Bureaucrats[2].incrementGrade();
    /* Bureaucrats[3].decrementGrade(); */

    for (size_t i = 0; i < 4; i++)
      std::cout << Bureaucrats[i] << std::endl;

    Bureaucrat Joe(Bureaucrats[0]);
    std::cout << Joe << std::endl;

    Bureaucrat Joe2("Joe", 1);
    std::cout << Joe2 << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
