#include <iostream>
#include "Class/n_tls_server.h"

using namespace std;

int main()
{
    n_TLS_Server server(1234);
    server.openTestServer();
    return 0;
}
