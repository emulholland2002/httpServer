#include "../include/Sockets/ListeningSocket.hpp"

int main () {
  std::cout << "Starting..." << std::endl;

  std::cout << "Binding Socket..." << std::endl;
  BindingSocket bs = BindingSocket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY);

  std::cout << "Listening Socket..." << std::endl;
  ListeningSocket ls = ListeningSocket(AF_INET, SOCK_STREAM, 0, 81, INADDR_ANY, 10);
  
  std::cout << "Success..." << std::endl;

  return 0;
}
