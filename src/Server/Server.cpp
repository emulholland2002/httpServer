#include "../../include/Server/Server.hpp"

Server::Server(int domain, int service, int protocol, int port, u_long interface, int bcklg) {
  socket = new ListeningSocket(domain, service, protocol, port, interface, bcklg);
}

ListeningSocket * Server::get_socket() {
  return socket;
}
