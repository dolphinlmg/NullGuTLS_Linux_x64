#include <iostream>
#include "Class/n_tls_client.h"
#define MAX_SIZE 1024
using namespace std;

int main()
{
    n_TLS_Client client("172.203.0.10",1234);
    char receve_buf[MAX_SIZE];
    //char send_buf[MAX_SIZE];
    string send_buf;
    while(true){
        client.openSocket();
        client.connectSocket();
        int fd = client.get_client_sock();
        while(true){
            getline(cin,send_buf);
            //if (cin.eof())
            //    break;
            if(send_buf=="exit"){
                close(fd);
                break;
            }
            cout << "Input str: " << send_buf <<endl;
            cout << "write bytes: " <<
                    write(fd, send_buf.c_str(), send_buf.size()) <<endl;
            memset(receve_buf, 0, MAX_SIZE);
            read(fd, receve_buf, MAX_SIZE);
            cout  << "Server: " << receve_buf << endl;
        }
        //close(fd);
        send_buf = "";
    }
}
