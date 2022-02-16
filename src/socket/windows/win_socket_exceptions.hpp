#ifndef WIN_SOCKET_EXCEPTIONS_HPP
#define WIN_SOCKET_EXCEPTIONS_HPP

#if defined(_WIN32) && !defined(__linux__)

#include "winsock2.h"

namespace Net {

	extern std::map<SocketExceptions, const char*> ExceptionsMap;
	extern enum SocketExceptions;

} //namespace Net

#endif

#endif // !WIN_SOCKET_EXCEPTIONS_HPP
