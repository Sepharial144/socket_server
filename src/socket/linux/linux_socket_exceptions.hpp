#ifndef LINUX_SOCKET_EXCEPTIONS_HPP
#define LINUX_SOCKET_EXCEPTIONS_HPP

#include <map>

#ifdef __linux__

namespace Net {

	extern std::map<SocketExceptions, const char*> ExceptionsMap;
	extern enum SocketExceptions;

} //namespace Net

#endif

#endif // !LINUX_SOCKET_EXCEPTIONS_HPP
