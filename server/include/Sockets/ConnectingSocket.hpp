#ifndef ConnectingSocket_hpp 
#define ConnectingSocket_hpp

#include <stdio.h>

#include "Socket.hpp"

class ConnectingSocket: public Socket {
  public:
    // constructor
    ConnectingSocket(int domain, int service, int protocol, int port, u_long interface);
    // virtual func from parent 
    int network_connect(int sock, struct sockaddr_in address);
};

#endif /* ConnectingSocket_hpp */
