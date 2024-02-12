#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string const target);
  ShrubberyCreationForm(const std::string &name, int gradeToSign,
                        int gradeToExecute);
  ~ShrubberyCreationForm();

  ShrubberyCreationForm(const ShrubberyCreationForm &src);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

  void execute(Bureaucrat const &executor) const;

  class FileNotOpenException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return ("ShrubberyCreationForm Exception: File could not be opened.");
    };
  };

private:
  const char *_text_art = R"(
                ,@@@@@@@,
        ,,,.   ,@@@@@@/@@,  .oo8888o.
    ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o
   ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'
    %&&%&%&/%&&%@@\@@/ /@@@88888\88888'
    %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'
    `&%\ ` /%&'    |.|        \ '|8'
        |o|        | |         | |
        |.|        | |         | |
     \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_
	
)";
};
#endif
