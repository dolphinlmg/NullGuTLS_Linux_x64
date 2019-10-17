#include "n_tls_client.h"

n_TLS_Client::n_TLS_Client(std::string& server_ip, unsigned short port) {
    try {
        memset(&this->server_addr, 0, sizeof(server_addr));
        this->server_addr.sin_family = AF_INET;
        this->server_addr.sin_addr.s_addr = inet_addr(server_ip.c_str());
        this->setPort(port);
    } catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        exit(-1);
    }
}

bool n_TLS_Client::openSocket() {
    this->client_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (this->client_sock == -1) return false;
    return true;
}

bool n_TLS_Client::connectSocket() {
    if (connect(this->client_sock, reinterpret_cast<struct sockaddr*>(&this->server_addr), sizeof(server_addr)) == -1)
        return false;
    return true;
}

long n_TLS_Client::sendMessage(std::string msg) {
    return write(this->get_client_sock(), msg.c_str(), msg.size());
}

unsigned short n_TLS_Client::getPort() {
    return ntohs(this->server_addr.sin_port);
}

void n_TLS_Client::setPort(unsigned short port) {
    this->server_addr.sin_port = htons(port);
}

int n_TLS_Client::get_client_sock() {
    return this->client_sock;
}

bool n_TLS_Client::openServer() {
    bool ret =  this->openSocket() |
            this->connectSocket();
    this->sendMessage("Client Hello");
    return ret;
}
