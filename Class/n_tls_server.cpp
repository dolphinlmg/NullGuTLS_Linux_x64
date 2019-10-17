#include "n_tls_server.h"

n_TLS_Server::n_TLS_Server(unsigned short port) {
    memset(&this->server_addr, 0, sizeof(sockaddr_in));
    this->server_addr.sin_family = AF_INET;
    this->setPort(port);
    this->server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
}

bool n_TLS_Server::openSocket() {
    fd = socket(PF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        std::cerr << "Server socket create fail" << std::endl;
        return false;
    }
    return true;
}

bool n_TLS_Server::bindSocket() {
    if (fd == -1)	return false;
    if (bind(fd, reinterpret_cast<struct sockaddr*>(&server_addr), sizeof(sockaddr_in)) == -1)
        return false;
    return true;
}

bool n_TLS_Server::setListen(int count) {
    if (listen(fd, count) == -1)
        return false;
    return true;
}

void n_TLS_Server::setPort(unsigned short port) {
    this->server_addr.sin_port = htons(port);
}

unsigned short n_TLS_Server::getPort() const {
    return ntohs(this->server_addr.sin_port);
}
