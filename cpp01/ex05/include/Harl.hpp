#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define DEBUG_MSG                                                              \
  "I love having extra bacon for my "                                          \
  "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"

#define INFO_MSG                                                               \
  "I cannot believe adding extra bacon costs more money. You didn\'t put "     \
  "enough bacon in my burger! If you did, I wouldn\'t be asking for more!"

#define WARNING_MSG                                                              \
  "I think I deserve to have some extra bacon for free. I’ve been coming for " \
  "years whereas you started working here since last month."

#define ERROR_MSG "This is unacceptable! I want to speak to the manager now."

class Harl {
public:
  Harl();
  ~Harl();

  void complain(std::string level);

private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

  const std::string _lvl_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  typedef void (Harl::*t_func_ptr)();
  const t_func_ptr lvl_funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning,
                                   &Harl::error};
};

#endif
