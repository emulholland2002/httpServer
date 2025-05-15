#include "BindingSocket.hpp"

// constructor
BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long interface) :
  Socket(domain, service, protocol, port, interface) {
  // establish network connection
  set_connection(network_connect(get_sock(), get_address()));
  test_connection(get_connection());
}

// implementation of network connect virtual func
int BindingSocket::network_connect(int sock, struct sockaddr_in address) {
  return bind(sock, (struct sockaddr *)&address, sizeof(address));
}
