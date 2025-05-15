#ifndef BindingSocket_hpp
#define BindingSocket_hpp

#include <stdio.h>

#include "Socket.hpp"

class BindingSocket: public Socket {
  public:
    // constructor
    BindingSocket(int domain, int service, int protocol, int port, u_long interface);
    // virtual func from parent 
    int network_connect(int sock, struct sockaddr_in address);
};

#endif /* BindingSocket_hpp */
