#include "../../include/Server/TestServer.hpp"
#include <cstring>

TestServer::TestServer() : Server(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10) {
  launch();
}

void TestServer::accepter() {
  struct sockaddr_in address = get_socket()->get_address();
  int addrlen = sizeof(address);
  new_socket = accept(get_socket()->get_sock(), (struct sockaddr *)&address, (socklen_t *)&addrlen);
  read(new_socket, buffer, 30000);
}

void TestServer::handler() {
  std::cout << buffer << std::endl;
}

void TestServer::responder() {
  const char *hello = "hello from server";
  write(new_socket, hello, strlen(hello));
  close(new_socket);
}

void TestServer::launch() {
  while (true) {
    std::cout << "waiting..." << std::endl;
    accepter();
    handler();
    responder();
    std::cout << "finished..." << std::endl;  
  }
}
