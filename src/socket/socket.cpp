#include "socket.hpp"

namespace Net {

	Socket::Socket(int buf_len, char* default_port):
	_bufferLength(buf_len),
	_defaultPort(default_port),
	{
		assert(_bufferLength > 0 && _bufferLength <= Settings::tcp_ip_packet_max_size);

		_recvbuf = new char[_bufferLength];

		_listenSocket = INVALID_SOCKET;
		_clientSocket = INVALID_SOCKET;

		_ptrInfo = nullptr;
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
	};

	void Socket::SetSocketParameters()
	{
		ZeroMemory(&_hints, sizeof(_hints));
		hints.ai_family = Addrinfo::aifamily::FAM_AF_INET;
		hints.ai_socktype = Addrinfo::aisocktype::TYPE_SOCK_STREAM;
		hints.ai_protocol = Addrinfo::aiprotocol::PROTOCOL_TCP;
		hints.ai_flags = Addrinfo::aiflags::FLAG_AI_PASSIVE;
	};


	int Socket::CreateSocket() 
	{

		SetSocketParameters();

		// Resolve the server address and port
		_initStatus = getaddrinfo(NULL, _defaultPort, &_hints, &_ptrInfo);
		if (_initStatus != 0) {
a
			printf("getaddrinfo failed with error: %d\n", _initStatus);
			WSACleanup();
			return 0;
		}
		else {

			printf("GetaddrInfo successfully.\n");
		}
	};

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
	};


} // namespace Net