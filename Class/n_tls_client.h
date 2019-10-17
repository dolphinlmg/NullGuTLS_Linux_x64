#ifndef N_TLS_CLIENT_H
#define N_TLS_CLIENT_H
#include "Class/n_socket.h"

class n_TLS_Client
{
public:
    n_TLS_Client(std::string& server_ip, unsigned short port);
    bool openSocket();
    bool connectSocket();
    long sendMessage(std::string msg);
    int get_client_sock();
    unsigned short getPort();
    void setPort(unsigned short port);
    bool openServer();
private:
    int client_sock;
    struct sockaddr_in server_addr;
};

#endif // N_TLS_CLIENT_H
