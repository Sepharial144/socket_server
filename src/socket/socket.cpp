#include "socket.h"

namespace Net {

	Socket::Socket(int buf_len, char* default_port)
	{
		assert(buf_len > 0 && buf_len <= TCPIP_PACKET_MAX_SIZE);
		m_BufferLength = buf_len;
		m_DefaultPort = default_port;

		recvbuf = new char[m_BufferLength];

		m_ListenSocket = INVALID_SOCKET;
		m_ClientSocket = INVALID_SOCKET;

		ptrInfo = nullptr;
	}

	Socket::~Socket()
	{
		freeaddrinfo(ptrInfo);
		delete[] recvbuf;
	}

	int Socket::Init() {

		m_initResult = WSAStartup(MAKEWORD(2, 2), &m_wsaData);
		if (m_initResult != 0) {
			//m_Error = "WSAStartup failed with error: ";
			//Logging::Logger::WriteLog(Logging::SOCKET, Logging::ERROR_MESSAGE, strcat(m_Error, static_cast<char*>(m_initResult)));
			printf("WSAStartup failed with error: %d\n", m_initResult);
			return 0;
		}
		else {
			printf("WSAStartup started: %d\n", m_initResult);
		}
	};

	void Socket::SetSocketParameters()
	{
		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = Addrinfo::aifamily::FAM_AF_INET;
		hints.ai_socktype = Addrinfo::aisocktype::TYPE_SOCK_STREAM;
		hints.ai_protocol = Addrinfo::aiprotocol::PROTOCOL_TCP;
		hints.ai_flags = Addrinfo::aiflags::FLAG_AI_PASSIVE;
	};


	int Socket::CreateSocket() 
	{

		SetSocketParameters();

		// Resolve the server address and port
		m_initResult = getaddrinfo(NULL, m_DefaultPort, &hints, &ptrInfo);
		if (m_initResult != 0) {
a
			printf("getaddrinfo failed with error: %d\n", m_initResult);
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
		m_ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

		if (m_ListenSocket == INVALID_SOCKET) {
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