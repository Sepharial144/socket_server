#ifndef SOCKET_EXCEPTIONS_HPP
#define SOCKET_EXCEPTIONS_HPP

#if defined(_WIN32) && !defined(__linux__)

#include "win_socket_exceptions.h"

#elif defined(__linux__) && !defined(_WIN32)

#include "linux_socket_exceptions.h"

#endif



#endif // !SOCKET_EXCEPTIONS_HPP
