#ifndef N_TLS_SERVER_H
#define N_TLS_SERVER_H
#include <sys/socket.h>

class n_TLS_Server
{
public:
    n_TLS_Server(int port);
    bool openSocket();
    bool bindSocket();
    bool setListen();
    void setPort(int port);
    int getPort() const;
private:
    struct sockaddr sock;
    int fd;
};

#endif // N_TLS_SERVER_H
