#include "commn_function.h"

my_commn_fuction::CommnFunction::CommnFunction()
{
}

void my_commn_fuction::CommnFunction::Clog(const std::string &title, const std::string &content,
                                           const my_commn_fuction::Color &color)
{
  //std::cerr << std::endl;
  switch(color)
  {
    case RED:
      std::cerr << "[" + title + "]"
                << " : \033[31m" << content << " \033[0m" << std::endl;
      break;
    case YELLOW:
      std::cerr << "[" + title + "]"
                << " : \033[33m" << content << " \033[0m" << std::endl;
      break;
    case BLUE:
      std::cerr << "[" + title + "]"
                << " : \033[34m" << content << " \033[0m" << std::endl;
      break;
    case GREEN:
      std::cerr << "[" + title + "]"
                << " : \033[32m" << content << " \033[0m" << std::endl;
      break;
    case VIOLET:
      std::cerr << "[" + title + "]"
                << " : \033[35m" << content << " \033[0m" << std::endl;
      break;
    case WHITE:
      std::cerr << "[" + title + "]"
                << " : \033[37m" << content << " \033[0m" << std::endl;
      break;
  }
}
