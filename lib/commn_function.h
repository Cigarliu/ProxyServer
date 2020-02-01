#ifndef COMMN_FUNCTION_H
#define COMMN_FUNCTION_H

#include <iostream>
#include <string>

namespace my_commn_fuction
{
/*
 * 颜色枚举
 * 用于输出日志颜色
 */
enum Color
{
  RED = 0,
  YELLOW,
  BLUE,
  GREEN,
  VIOLET,
  WHITE
};


class CommnFunction
{
  public:
  CommnFunction();

  /**
   *  @brief     用于输出日志
   *  @param     日志标题，内容，颜色
   *  @note      备注
   *  @Sample usage:
   *  @return    返回
   */
  void Clog(const std::string& title, const std::string& content, const Color& color = RED);
};
}
#endif // COMMN_FUNCTION_H
