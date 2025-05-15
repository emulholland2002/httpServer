#ifndef SOCKET_HPP
#define SOCKET_HPP

# include <iostream>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/soicket.h>

class Socket {
  private:
    struct sockaddr_in address;
    int connection;
    int sock;
  public
    // default constructor:
    //  - domain (IPv6) 
    //  - type of service (virutal circuit service) 
    //  - protocol 
    Socket(int domain, int service, int protocol, int port, u_long interface);
    
    // virtual func to connect to a network
    virtual int network_connect(int sock, struct sockaddr_in address) = 0;
    void test_connection(int conn);

    // getter funcs
    struct sockaddr_in get_address();
    int get_sock();
    int get_connection();
    void set_connection(int conn);
};

#endif /* Socket_hpp */
