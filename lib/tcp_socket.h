#ifndef TCP_SOCKET_H
#define TCP_SOCKET_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
namespace my_socket
{
using namespace std;

class TcpSocket
{
  public:
  TcpSocket();
  ~TcpSocket();

  /**
   *  @brief     获得socket句柄
   *  @param     参数
   *  @note      备注
   *  @Sample usage:
   *  @return    返回
   */
  int GetSocketId();

  /**
   *  @brief     创建(初始化)一个服务端socket套接字
   *  @param
   *  @note
   *  @Sample usage:
   *  @return    返回
   */
  int CreateTcpSocket();


  /**
   *  @brief    发起tcp连接
   *  @param
   *  @note     发起连接
   *  @Sample usage:
   *  @return    返回
   */
  bool TcpConnect(char* request_ip, int request_port);

  /**
   *  @brief     监听tcp连接
   *  @param
   *  @note      用于监听
   *  @Sample usage:
   *  @return    返回
   */
  bool TcpListen(char* request_ip, int request_port);


  /**
   *  @brief     同意一个tcp连接
   *  @param
   *  @note
   *  @Sample usage:
   *  @return    返回
   */
  bool TcpAccept();

  /**
   *  @brief     发送一条信息
   *  @param
   *  @note
   *  @Sample usage:
   *  @return    返回
   */
  bool TcpWriteMessage(char* message);

  /**
   *  @brief     读取一条信息
   *  @param
   *  @note
   *  @Sample usage:
   *  @return    返回
   */
  const char* TcpReadMessage();

  /**
   *  @brief     关闭socket句柄
   *  @param
   *  @note
   *  @Sample usage:
   *  @return    返回
   */
  void TcpClose();

  private:
  int socket_id_;
  char tcp_buffer_[1024];
};
}
#endif // TCP_SOCKET_H
