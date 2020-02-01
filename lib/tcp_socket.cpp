#include "tcp_socket.h"


my_socket::TcpSocket::TcpSocket()
{
}

my_socket::TcpSocket::~TcpSocket()
{
  close(socket_id_);
}


int my_socket::TcpSocket::CreateTcpSocket()
{
  // 初始化套接字
  socket_id_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  return socket_id_;
}

bool my_socket::TcpSocket::TcpConnect(char* request_ip, int request_port)
{
  //向服务器（特定的IP和端口）发起请求
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));          //每个字节都用0填充
  serv_addr.sin_family = AF_INET;                    //使用IPv4地址
  serv_addr.sin_addr.s_addr = inet_addr(request_ip); //具体的IP地址
  serv_addr.sin_port = htons(request_port);          //端口

  const int kError = -1;

  if(connect(socket_id_, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == kError)
  {
    return false;
  }
  return true;
}

bool my_socket::TcpSocket::TcpListen(char* request_ip, int request_port)
{
  //向服务器（特定的IP和端口）发起请求
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));          //每个字节都用0填充
  serv_addr.sin_family = AF_INET;                    //使用IPv4地址
  serv_addr.sin_addr.s_addr = inet_addr(request_ip); //具体的IP地址
  serv_addr.sin_port = htons(request_port);          //端口
  bind(socket_id_, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

  const int kError = -1;
  if(listen(socket_id_, 20) == kError) // 维护20个队列
  {
    return false; // 返回-1代表错误
  }
  std::cout << " 监听中 " << std::endl;
  return true;
}

bool my_socket::TcpSocket::TcpAccept()
{
  struct sockaddr_in clnt_addr;
  socklen_t clnt_addr_size = sizeof(clnt_addr);
  int clnt_sock = accept(socket_id_, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
  std::cout << " 收到请求" << std::endl;
  const int kError = -1;
  if(clnt_sock == kError)
  {
    return false;
  }
  return true;
}

bool my_socket::TcpSocket::TcpWriteMessage(char* message)
{
  write(socket_id_, message, sizeof(message));
}

const char* my_socket::TcpSocket::TcpReadMessage()
{
  // 重置缓冲区
  memset(tcp_buffer_, 0, sizeof(tcp_buffer_));
  read(socket_id_, tcp_buffer_, sizeof(tcp_buffer_) - 1);
  return tcp_buffer_;
}

void my_socket::TcpSocket::TcpClose()
{
  close(socket_id_);
}
