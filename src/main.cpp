#include "logger/logger.hpp"
#include "socket/socket.hpp"

#include <memory>

int main()
{
	Logger::Logger logger;
	ServerSocket server(logger, 8080);
	return 0;
}