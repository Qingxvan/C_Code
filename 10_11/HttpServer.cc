#include "HttpServer.hpp"
#include <iostream>
#include <memory>
#include <pthread.h>
#include "Log.hpp"


using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        exit(1);
    }
    
    uint16_t port = std::stoi(argv[1]);
    // HttpServer *svr = new HttpServer();
    // std::unique<HttpServer> svr(new HttpServer());
    std::unique_ptr<HttpServer> svr(new HttpServer(port));
    svr->Start();
    return 0;
}