#include "n_tls_server.h"

n_TLS_Server::n_TLS_Server(unsigned short port) {
    try {
        memset(&this->server_addr, 0, sizeof(sockaddr_in));
        this->server_addr.sin_family = AF_INET;
        this->setPort(port);
        this->server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    } catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        exit(-1);
    }
}

bool n_TLS_Server::openSocket() {
    server_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        std::cerr << "Server socket create fail" << std::endl;
        return false;
    }
    return true;
}

bool n_TLS_Server::bindSocket() {
    if (server_sock == -1)	return false;
    if (bind(server_sock, reinterpret_cast<struct sockaddr*>(&server_addr), sizeof(server_addr)) == -1)
        return false;
    return true;
}

bool n_TLS_Server::setListen(int count) {
    if (server_sock == -1) return false;
    if (listen(server_sock, count) == -1)
        return false;
    return true;
}

void n_TLS_Server::setPort(unsigned short port) {
    this->server_addr.sin_port = htons(port);
}

bool n_TLS_Server::acceptSocket() {
    if (server_sock == -1) return false;
    this->addr_size = sizeof(client_addr);
    this->client_sock = accept(server_sock, reinterpret_cast<struct sockaddr*>(&client_addr), &this->addr_size);
    if (this->client_sock == -1) return false;
    write(this->client_sock, "Server Hello", 12);
    return true;
}

unsigned short n_TLS_Server::getPort() const {
    return ntohs(this->server_addr.sin_port);
}

bool n_TLS_Server::openServer() {
    bool ret = this->openSocket() |
            this->bindSocket() |
            this->setListen() |
            this->acceptSocket();
    return ret;
}
