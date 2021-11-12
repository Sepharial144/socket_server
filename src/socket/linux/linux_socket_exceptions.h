#ifndef LINUX_SOCKET_EXCEPTIONS_H
#define LINUX_SOCKET_EXCEPTIONS_H

#if defined(__linux__) && !defined(_WIN32)

namespace Net {

	extern std::map<SocketExceptions, const char*> ExceptionsMap;
	extern enum SocketExceptions;

} //namespace Net

#endif

#endif // !1
