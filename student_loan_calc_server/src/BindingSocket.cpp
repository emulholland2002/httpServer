#include "BindingSocket.hpp"

int BindingSocket::network_connect(int sock, struct sockaddr_in address) {
  return bind(sock, (struct sockaddr *)&address, sizeof(address));
}
