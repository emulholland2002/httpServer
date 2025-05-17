# 🔌 Simple C++ HTTP Server (From Scratch)

A low-level HTTP server implemented in **C++** using only system libraries like `<sys/socket.h>`, `<netinet/in.h>`, and `<unistd.h>`. This project is a great starting point for understanding how networking, sockets, and the HTTP protocol work under the hood — with no external dependencies or frameworks.

---

## 📁 Project Structure
```
server/
├── CMakeLists.txt # CMake build script
├── include/
│     └── Server/
│         ├── Server.hpp
│         └── TestServer.hpp
│     └── Sockets/
│         ├── BindingSocket.hpp
│         ├── ListeningSocket.hpp
│         ├── ConnectingSocket.hpp
│         └── Socket.hpp
├── src/
│     ├── Server/
│     │     ├── Server.cpp
│     │     ├── TestServer.cpp
│     │     └── Test.cpp
│     └── Sockets/
│         ├── BindingSocket.cpp
│         ├── ListeningSocket.cpp
│         ├── ConnectingSocket.cpp
│         └── Socket.cpp
```
---

## ⚙️ Build Instructions

### Prerequisites

- Linux-based system
- C++17-compatible compiler (`g++`, `clang++`)
- CMake 3.10 or higher

### Steps

```bash
cmake ..
make
./bin/server
```

## 🌐 Features

- Raw socket handling using `<sys/>` libraries
- Modular architecture:
  - **Socket abstractions**: binding, listening, connecting
  - **Server logic** separated into `Server` and `TestServer` classes
- Simple HTTP response generation
- CMake-based build for portability

---

## 🧪 Example Output

Once running, access the server using:

```bash
curl http://localhost:PORT
HTTP/1.1 200 OK
Content-Type: text/plain
Hello, this is a raw C++ HTTP server!
```

## 📚 Key Concepts

- **TCP socket setup** using: `socket()`, `bind()`, `listen()`, and `accept()`
- **Manual HTTP parsing** and response formatting
- **Object-oriented encapsulation** of low-level system calls
- **Compile-time dependency management** with CMake

---

## ✅ Future Improvements

- Implement threading or `select()` for concurrent connections
- Add support for HTTP/1.1 headers and persistent connections
- Enable POST method handling
- Serve static HTML files
- Add unit tests and logging

---

## 👤 Author

**Ethan Mulholland**  
GitHub: [emulholland2002](https://github.com/emulholland2002)

---

## 📝 License

MIT License — feel free to use, modify, and share!
