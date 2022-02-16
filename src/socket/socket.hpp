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
		WSADATA m_wsaData;
		int m_initResult;

		int m_BufferLength;
		char* m_DefaultPort;

		SOCKET m_ListenSocket = INVALID_SOCKET;
		SOCKET m_ClientSocket = INVALID_SOCKET;

		struct addrinfo* ptrInfo;
		struct addrinfo hints;

		int iSendResult;
		char* recvbuf;

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
