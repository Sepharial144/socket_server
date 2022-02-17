#include "socket_definitions.hpp"
#include <iostream>
#include <exception>

int guard(int n, const char* error)
{
    if (n == -1)
    {
        std::cout << error << std::endl;
        exit(EXIT_FAILURE);
    }
    return n;
}

int main() 
{
    int listen_socket_fd = guard(socket(AF_INET, SOCK_STREAM, 0), "Could not create TCP listening socket");

    int flags = guard(fcntl(listen_socket_fd, F_GETFL), "could not get flags on TCP listening socket");

    guard(fcntl(listen_socket_fd, F_SETFL, flags | O_NONBLOCK), "could not set TCP listening socket to be non-blocking");

    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    guard( bind(listen_socket_fd, (struct sockaddr*) &addr, sizeof(addr)), "could not bind socket");

    guard(listen(listen_socket_fd, 100), "could not listen");

    for(;;)
    {
        int client_socket_fd = accept(listen_socket_fd, NULL, NULL);

        if (client_socket_fd == -1) {

            if (errno == EWOULDBLOCK) {
                std::cout << "No pending connections; sleeping for one second.\n";
                sleep(1);

            } else {
                throw std::invalid_argument("Error when accepting connection");

                exit(EXIT_FAILURE);
            }
        } else {
            char msg[] = "hello\n";
            std::cout << "Got a connection; writing 'hello' then closing.\n";
            send(client_socket_fd, msg, sizeof(msg), 0);
            close(client_socket_fd);
        }
    }

    return EXIT_SUCCESS;
}
