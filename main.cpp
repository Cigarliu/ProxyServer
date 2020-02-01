#include <string>
#include "lib/commn_function.h"
#include "lib/tcp_socket.h"

void test1()
{
    using namespace my_commn_fuction;
    CommnFunction com;
    com.Clog("测试", "测试内容");

    using namespace my_socket;

    TcpSocket* tcp_server_ = new TcpSocket;
    int sock_id;
    sock_id = tcp_server_->CreateTcpSocket();
    std::cout << " 创建连接: " << sock_id << std::endl;

    bool check_status;
    check_status = tcp_server_->TcpListen("127.0.0.1", 1998);
    if(!check_status)
    {
        com.Clog("错误", "tcp监听端口绑定失败");
    }
    tcp_server_->TcpAccept();

    const char* message;
    message =  tcp_server_->TcpReadMessage();
    std::cout << message << std::endl;
}


void test2()
{
    //创建套接字
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    //将套接字和IP、端口绑定
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    serv_addr.sin_port = htons(1999);  //端口
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    //进入监听状态，等待用户发起请求
    listen(serv_sock, 20);

    //接收客户端请求
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

    //向客户端发送数据
    char str[] = "http://c.biancheng.net/socket/";
    write(clnt_sock, str, sizeof(str));

    //关闭套接字
    close(clnt_sock);
    close(serv_sock);

}

int main()
{
 test2();

}
