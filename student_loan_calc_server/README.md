## Primary Server Functions
    - listen for http requests
    - process requests
    - map requests to resources
    - generate responses
    - send responses
    - logging and monitoring 
    - handle concurrency
    - security

### Workflow 
The client and server establish a TCP connection stream, the client sends HTTP request over TCP connection, and then the server processes that request and sends back a reply.

client request --> dns resolution --> TCP connection --> http request --> request handling --> http response --> rendering

### Socket Programming 
A socket is an endpoint for communication between two machines. It is used to establish a connection, send data, and receive data over a network.

    - AF_INET: use IPv4
    - SOCK_STREAM: use TCP
    - INADDR_ANY: the server accepts connections from any network interface

## Server Setup 
create socket --> bind to addr --> listen for connections --> accept connections --> close connection


## HTTP Parsing
The server parses the HTTP request for the requested file path and HTTP method.
The server constructs an HTTP response and sends it.
