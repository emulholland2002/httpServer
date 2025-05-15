#include "../include/socket.hpp"

Socket::(int domain, int service, int protocol, int port, u_long interface) {
  // define address structure
  address.sin_family = domain;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = htonl(interface);

  // establish socket
  sock = socket(domain, service, protocol);
  test_connection(socket);

  // establish network connection
  connection = network_connect(sock, address);
  test_connection(connection);
}

// test connection virtual func
Socket::test_connection(int item_to_test) {
  // confirms connection/socket has been established
  if (item_to_test < 0) {
    perror("Failed to connect...");
    exit(EXIT_FAILURE)
  }
}

// getter funcs:
Socket::get_address() {
  return address;
}

Socket::get_sock() {
  return sock;
}

Socket::get_connection() {
  return connection;
}
