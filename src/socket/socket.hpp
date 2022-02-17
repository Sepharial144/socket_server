#ifndef SOCKET_HPP
#define SOCKET_HPP

class Socket
{

    virtual int Guard(int socket_fd, const char* message);

    virtual void init();

    virtual void setParameter();

    virtual void bind();

    virtual void listening();

    virtual void setBuffer();

    virtual void accept();
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
};

using ptrLogger = std::shared_ptr<Logger>;

class ServerSocket: Socket
{
    private:

        ptrLogger _logger;

        int _socketServer_fd;

    private:
        int Guard(int socket_fd, const char* message) override
        {
            if (socket_fd == -1)
            {
                _logger->warning("Socket server", message);
            }
            return socket_fd;
        }

        void init() override
        {
        
        }



    public:
        ServerSocket(std::shared_ptr<Logger> logger):
        _logger(logger)
        {
            init();
        };

}

#endif // !SOCKET_HPP