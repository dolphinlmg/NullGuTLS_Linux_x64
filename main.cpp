#include <iostream>
#include "Class/n_tls_server.h"
#define MAX_SIZE 1024

using namespace std;

int main()
{
    n_TLS_Server server(1234);
    char receve_buf[MAX_SIZE] = "";

    server.openSocket();
    server.bindSocket();
    server.setListen();

    while(true) {
        if (!server.acceptSocket()) return -1;
        cout << "Peer connected" << endl;
        int fd = server.getClientSock();
        cout << "fd: " << fd << endl;
        while(true) {
            cout << "reading from fd: " << fd << endl;
            long status = read(fd, receve_buf, MAX_SIZE);
            cout << "read bytes are: " << status << endl;
            if (status > 0) {
                receve_buf[status] = 0;
                cout << receve_buf << endl << endl;
                write(fd, "Server receved", 15);
            } else if (status == 0) {
                cout << "Peer close the socket.." << endl << endl;
                close(fd);
                break;
            }
            memset(receve_buf, 0, MAX_SIZE);
        }
    }

}
