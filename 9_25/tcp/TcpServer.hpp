#pragma once
#include "Log.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

Log lg;

const int defaultfd = -1;
const std::string defaultip = "0.0.0.0";

class TcpServer
{
public:
    TcpServer(const uint16_t &port, const std::string &ip = defaultip)
        : listensock_(defaultfd), port_(port), ip_(ip)
    {
    }
    void InitServer()
    {
        listensock_ = socket(AF_INET, SOCK_STREAM, 0);
        if (listensock_ < 0)
        {
            lg(Fatal, "create socket, errno: %d, errstring: %s", errno, strerror(errno));
            exit(2);
        }
        lg(Info, "create socket success, listensock_: %d", listensock_);
        struct sockaddr_in local;
        memset(&local, 0, sizeof(local));
        local.sin_family = AF_INET;
        local.sin_port = htons(port_);
        inet_aton(ip_.c_str(), &(local.sin_addr));
        // 绑定
        if (bind(listensock_, (struct sockaddr *)&local, sizeof(local)) < 0)
        {
            lg(Fatal, "bind, errno: %d, errstring: %s", errno, strerror(errno));
            exit(3);
        }
        lg(Info, "bind success");
        // 设置监听状态
        if (listen(listensock_, 5) < 0)
        {
            lg(Fatal, "listen, errno: %d, errstring: %s", errno, strerror(errno));
            exit(4);
        }
        lg(Info, "listen start, listensock_: %d", listensock_);
    }
    void Start()
    {
        for (;;)
        {
            lg(Info, "tcpserver is running...");
            // 获取新链接
            struct sockaddr_in client;
            socklen_t clientlen = sizeof(client);
            int sockfd = accept(listensock_, (struct sockaddr *)&client, &clientlen);
            if (sockfd < 0)
            {
                lg(Warning, "accept, errno: %d, errstring: %s", errno, strerror(errno));
                continue;
            }
            uint16_t clientport = ntohs(client.sin_port);
            char clientip[32];
            inet_ntop(AF_INET, &client.sin_addr, clientip, sizeof(clientip));
            // 根据新链接来进行通信
            lg(Info, "get a new link..., sockfd: %d, client ip: %s, client port: %d", sockfd, clientip, clientport);

        }
    }

    ~TcpServer()
    {
    }

private:
    int listensock_;
    uint16_t port_;
    std::string ip_;
};