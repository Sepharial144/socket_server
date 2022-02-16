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

		int _bufferLen;
		char* _defaultPort;

		SOCKET _listenSocket = INVALID_cleaSOCKET;
		SOCKET _clientSocket = INVALID_SOCKET;

		struct addrinfo* _ptrInfo;
		struct addrinfo _hints;

		int _sendStatus;
		char* _recvbuf;
	
	public:

		Socket::Socket(int buf_len, char* default_port):
		_bufferLen(buf_len),
		_defaultPort(default_port),
		_listenSocket(INVALID_SOCKET),
		_clientSocket(INVALID_SOCKET),
		_ptrInfo(nullptr)
		{
			assert(_bufferLength > 0 && _bufferLength <= Settings::tcp_ip_packet_max_size);

			_recvbuf = new char[_bufferLen];
		}

	Socket::~Socket()
	{
		freeaddrinfo(_ptrInfo);
		delete[] _recvbuf;
	}

	int Socket::Init() {

		_initStatus = WSAStartup(MAKEWORD(2, 2), &_wsaData);
		if (_initStatus != 0) {
			//m_Error = "WSAStartup failed with error: ";
			//Logging::Logger::WriteLog(Logging::SOCKET, Logging::ERROR_MESSAGE, strcat(m_Error, static_cast<char*>(_initStatus)));
			printf("WSAStartup failed with error: %d\n", _initStatus);
			return 0;
		}
		else {
			printf("WSAStartup started: %d\n", _initStatus);
		}
		return 1;
	}

	void Socket::SetSocketParameters()
	{
		ZeroMemory(&_hints, sizeof(_hints));
		_hints.ai_family = Addrinfo::aifamily::FAM_AF_INET;
		_hints.ai_socktype = Addrinfo::aisocktype::TYPE_SOCK_STREAM;
		_hints.ai_protocol = Addrinfo::aiprotocol::PROTOCOL_TCP;
		_hints.ai_flags = Addrinfo::aiflags::FLAG_AI_PASSIVE;
	}

	int Socket::CreateSocket() 
	{

		SetSocketParameters();

		// Resolve the server address and port
		_initStatus = getaddrinfo(NULL, _defaultPort, &_hints, &_ptrInfo);
		if (_initStatus != 0) {

			printf("getaddrinfo failed with error: %d\n", _initStatus);
			WSACleanup();
			return 0;
		}
		else {
			printf("GetaddrInfo successfully.\n");
		}
		return 1;
	}

	int Socket::ListenSocket()
	{
		// Listen socket for connecting to server
		_listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

		if (_listenSocket == INVALID_SOCKET) {
			printf("socket failed with error: %ld\n", WSAGetLastError());
			freeaddrinfo(result);
			WSACleanup();
			return 1;
		}
		else {

			std::cout << "Listenning successfully.\n";
		}
		return 0;
	}

} // namespace Net

#endif // !SOCKET_HPP
