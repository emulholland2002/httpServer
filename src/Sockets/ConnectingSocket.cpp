#include "../../include/Sockets/ConnestingSocket.hpp"

// constructor
ConnestingSocket::ConnestingSocket(int domain, int service, int protocol, int port, u_long interface) :
  Socket(domain, service, protocol, port, interface) {
    set_connection(network_connect(get_sock(), get_address()));
    test_connection(get_connection());
  }

int ConnestingSocket::network_connect(int sock, struct sockaddr_in address) {
  return connect (sock, (struct sockaddr *)&address, sizeof(address));
}
