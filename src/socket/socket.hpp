#ifndef SOCKET_HPP
#define SOCKET_HPP

class Socket
{
    virtual void init();

    virtual void setParameter();

    virtual void bind();

    virtual void listening();

    virtual void setBuffer();

    virtual void accept();
};

class ServerSocket: Socket
{
    private:
        int _socketServer_fd;
    public:

}

#endif // !SOCKET_HPP