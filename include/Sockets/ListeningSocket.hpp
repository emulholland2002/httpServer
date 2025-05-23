#ifndef ListeningSocket_hpp
#define ListeningSocket_hpp

#include <stdio.h>

#include "BindingSocket.hpp"

class ListeningSocket : public BindingSocket {
  private:
    int backlog;
    int listening;
  public:
    ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int bcklg);
    void start_listening();
};

#endif /* ListeningSocket_hpp */
