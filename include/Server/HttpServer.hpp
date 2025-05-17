#ifndef HttpServer_hpp
#define HttpServer_hpp

#include <stdio.h>
#include <unistd.h>

#include "../../include/Server/Server.hpp"

class HttpServer: public Server {
  private:
    char buffer[30000] = {0};
    int new_socket;

    void accepter();
    void handler();
    void responder();
  public:
    HttpServer();
    void launch();
};

#endif /* HttpServer_hpp */
