#ifndef SOCKET_HPP
#define SOCKET_HPP

#include "socket_definitions.hpp"

class Socket
{

    virtual int Guard(int socket_fd, const char* message);

    virtual void init();

    virtual void setParameter();

    virtual void bindSocket();

    virtual void listening();

    virtual void setBuffer();

    virtual void Run();
};

#include <memory>
#include <iostream>

class Logger
{

    public:
    Logger() {};
    
    void warning(const char* module, const char* message) {
        std::cout << message << "\n";
    };

    void warning(std::string& module, std::string& message)
    {
        std::cout << message << "\n";
    }
};

using ptrLogger = std::shared_ptr<Logger>;

class ServerSocket: Socket
{
    private:

        ptrLogger _logger;

        int _serverSocket_fd{};
        int _flags;
        int _clientSocket_fd{};

        int _connectionCount{};

        struct sockaddr_in _addr;

        int _port{};

    private:
        int Guard(int socket_fd, const char* message) override
        {
            // need refactoring accrodingly with linux errors
            if (socket_fd == -1)
            {
                _logger->warning("Socket server", message);
            }
            return socket_fd;
        }

        void init() override
        {
            _serverSocket_fd = Guard( socket(AF_INET, SOCK_STREAM, 0), "Could not create TCP socket server");

            int _flags = Guard( fcntl(_serverSocket_fd, F_GETFL), "Could not get flags on TCP socket serever");

            Guard( fcntl(_serverSocket_fd, F_SETFL, _flags | O_NONBLOCK), "Could not set TCP socket server to be non-blocking");
        }

        void setParameter() override
        {
                _addr.sin_family = AF_INET;
                _addr.sin_port = htons(_port);
                _addr.sin_addr.s_addr = htonl(INADDR_ANY);
        }

        void bindSocket() override
        {
            Guard(bind(_serverSocket_fd, (struct sockaddr*) &_addr, sizeof(_addr)), "Could not bind socket server");
        }

        void listening() override
        {
            Guard(listen(_serverSocket_fd, _connectionCount), "Could not listening socker server");
        }

        void Run(int delay = 1) override
        {
            for(;;)
                {
                int _clientSocket_fd = accept(_serverSocket_fd, NULL, NULL);

                if (_clientSocket_fd == -1) {

                    if (errno == EWOULDBLOCK) {
                        std::cout << "No pending connections; sleeping for one second.\n";
                        sleep(delay);

                    } else {
                        throw std::invalid_argument("Error when accepting connection");

                        exit(EXIT_FAILURE);
                    }
                } else {
                    char msg[] = "hello\n";
                    std::cout << "Got a connection; writing 'hello' then closing.\n";
                    send(_clientSocket_fd, msg, sizeof(msg), 0);
                    close(_clientSocket_fd);
                }
            }
        }

    public:
        ServerSocket(std::shared_ptr<Logger> logger, int port):
        _logger(logger),
        _port(port),
        _connectionCount(64)
        {
            init();
        };

}

#endif // !SOCKET_HPP