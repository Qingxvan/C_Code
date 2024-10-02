#pragma once
#include <iostream>
#include <string>
#include "Log.hpp"
#include "Init.hpp"

extern Log lg;
Init init;

class Task
{
public:
    Task(int sockfd, const std::string &clientip, const uint16_t &clientport)
        : sockfd_(sockfd), clientip_(clientip), clientport_(clientport)
    {
    }
    void run()
    {
        // 测试代码
        char buffer[4096];
        ssize_t n = read(sockfd_, buffer, sizeof(buffer)); 
        if (n > 0)
        {
            buffer[n] = 0;
            std::cout << "client key# " << buffer << std::endl;
            std::string echo_string = init.translation(buffer);

            n = write(sockfd_, echo_string.c_str(), echo_string.size());
            if(n < 0)
            {
                lg(Warning, "write error, errno : %d, errstring: %s", errno, strerror(errno));
            }
        }
        else if (n == 0)
        {
            lg(Info, "%s:%d quit, server close sockfd: %d", clientip_.c_str(), clientport_, sockfd_);
        }
        else
        {
            lg(Warning, "read error, sockfd: %d, client ip: %s, client port: %d", sockfd_, clientip_.c_str(), clientport_);
        }
        close(sockfd_);
    }
    void operator()()
    {
        run();
    }
    ~Task()
    {
    }

private:
    int sockfd_;
    std::string clientip_;
    uint16_t clientport_;
};