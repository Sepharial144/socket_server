#ifndef LINSOCKET_HPP
#define LINSOCKET_HPP


#define PORT 8080
#include "socket_definitions.hpp"
#include <iostream>


class Socket
{
private:
    int server_fd, _clientSocket;
    int  valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char* hello = "Hello from server";

public:
    Socket(/* args */);
    ~Socket();

    void createSocket()
    {
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        {
            std::cout<< "Socket failed" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    void init()
    {
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
        {
            std::cout << "Setsockopt" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    
    void SetConfiguration()
    {
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);
    }

    void bindSocket()
    {
        if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
        {
            std::cout << "Bind failed" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    void listenSocket()
    {
        if (listen(server_fd, 3) < 0)
        {
            std::cout << "Listen" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    void AcceptSocket()
    {
        if ((_clientSocket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) <0 )
        {
            std::cout << "Accept failure" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    void ReadSocket()
    {
        valread = read(_clientSocket, buffer, 1024);
        std::cout<< buffer << std::endl;
        send(_clientSocket, hello, strlen(hello), 0);
        std::cout << "Hello message sended" << std::endl;
    }

};

Socket::Socket(/* args */)
{
}

Socket::~Socket()
{
}



#endif // !LINSOCKET_HPP