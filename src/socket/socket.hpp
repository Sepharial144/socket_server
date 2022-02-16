#ifndef SOCKET_HPP
#define SOCKET_HPP

#include "socket_definitions.hpp"
#include "logger.hpp"


namespace Net {


	enum SocketType {
		Socket_Unspecified = 0,
		Socket_IP_V4 = 0,
		Socket_IP_V6 = 1,
	};

	class Socket
	{
	private:
		WSADATA _wsaData;
		int _initStatus;

		int _bufferLength;
		char* _defaultPort;

		SOCKET _listenSocket = INVALID_SOCKET;
		SOCKET _clientSocket = INVALID_SOCKET;

		struct addrinfo* _ptrInfo;
		struct addrinfo _hints;

		int iSendResult;
		char* _recvbuf;

		int Init();

		void SetSocketParameters();

		int CreateSocket();

		int ListenSocket();

	public:
		Socket(int buf_len, char* default_port);
		~Socket();

	};

} // namespace Net

#endif // !SOCKET_HPP
