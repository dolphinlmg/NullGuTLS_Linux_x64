#ifndef N_TLS_SERVER_H
#define N_TLS_SERVER_H
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <memory.h>

class n_TLS_Server
{
public:
    n_TLS_Server(unsigned short port);
    bool openSocket();
    bool bindSocket();
    bool setListen(int count = 1);
    void setPort(unsigned short port);
    bool acceptSocket();
    bool openServer();
    unsigned short getPort() const;
private:
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int server_sock;
    int client_sock;
    socklen_t addr_size;
};

#endif // N_TLS_SERVER_H
