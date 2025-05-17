#include "../../include/Server/HttpServer.hpp"
#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>

HttpServer::HttpServer() : Server(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10) {
  launch();
}

void HttpServer::accepter() {
  struct sockaddr_in address = get_socket()->get_address();
  int addrlen = sizeof(address);
  new_socket = accept(get_socket()->get_sock(), (struct sockaddr *)&address, (socklen_t *)&addrlen);
  read(new_socket, buffer, 30000);
}

void HttpServer::handler() {
  std::cout << buffer << std::endl;
}

void HttpServer::responder() {
      // Open the HTML file
    std::ifstream file("public/index.html");
    if (!file.is_open()) {
        std::string error_response =
            "HTTP/1.1 500 Internal Server Error\r\n"
            "Content-Type: text/plain\r\n\r\n"
            "Failed to load index.html\n";
        write(new_socket, error_response.c_str(), error_response.length());
        close(new_socket);
        return;
    }

    // Read file contents
    std::stringstream htmlStream;
    htmlStream << file.rdbuf();
    std::string htmlContent = htmlStream.str();

    // Compose HTTP response
    std::string response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: " + std::to_string(htmlContent.length()) + "\r\n"
        "Connection: close\r\n"
        "\r\n" +
        htmlContent;

    // Send response
    ssize_t bytes_sent = write(new_socket, response.c_str(), response.length());
    if (bytes_sent < 0) {
        perror("write failed");
    }

    // Close the socket
    close(new_socket);
}

void HttpServer::launch() {
  while (true) {
    std::cout << "waiting..." << std::endl;
    accepter();
    handler();
    responder();
    std::cout << "finished..." << std::endl;  
  }
}
