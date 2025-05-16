#include "../../include/Sockets/Socket.hpp"

Socket::Socket(int domain, int service, int protocol, int port, u_long interface) {
  // define address structure
  address.sin_family = domain;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = htonl(interface);

  // establish socket
  sock = socket(domain, service, protocol);
  test_connection(sock);
}

// test connection virtual func
void Socket::test_connection(int item_to_test) {
  // confirms connection/socket has been established
  if (item_to_test < 0) {
    perror("Failed to connect...");
    exit(EXIT_FAILURE);
  }
}

// getter funcs:
sockaddr_in Socket::get_address() {
  return address;
}

int Socket::get_sock() {
  return sock;
}

int Socket::get_connection() {
  return connection;
}

// setter funcs
void Socket::set_connection(int conn) {
  connection = conn;
}
