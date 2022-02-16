#include "linux_socket_exceptions.hpp"

#include <map>
#include <string>

#ifdef __linux__

namespace Net {

	// Windows socket exceprions
	enum SocketExceptions {
		
	};

	std::map<SocketExceptions, const char*> ExceptionsMap
	{
	
	};

#endif // ! __linux__

} // namespace Net