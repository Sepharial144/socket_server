#ifndef WIN_SOCKET_EXCEPTIONS_H
#define WIN_SOCKET_EXCEPTIONS_H

#include "winsock2.h"

#if defined(_WIN32) && !defined(__linux__)

namespace Net {

	extern std::map<SocketExceptions, const char*> ExceptionsMap;
	extern enum SocketExceptions;

} //namespace Net

#endif

#endif // !1
