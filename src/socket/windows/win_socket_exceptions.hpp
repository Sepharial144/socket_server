#ifndef WIN_SOCKET_EXCEPTIONS_HPP
#define WIN_SOCKET_EXCEPTIONS_HPP

#ifdef _WIN32

#include "winsock2.h"

namespace Net {

	extern std::map<SocketExceptions, const char*> ExceptionsMap;
	extern enum SocketExceptions;

} //namespace Net

#endif // !_WIN32

#endif // !WIN_SOCKET_EXCEPTIONS_HPP
