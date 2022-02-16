#ifndef SOCKET_EXCEPTIONS_HPP
#define SOCKET_EXCEPTIONS_HPP

#ifdef _WIN32

#include "win_socket_exceptions.hpp"

#elif __linux__

#include "linux_socket_exceptions.hpp"

#endif // Architecture defined

#endif // !SOCKET_EXCEPTIONS_HPP
