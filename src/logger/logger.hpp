#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <vector>
#include <map>

namespace Logging {

	// Description of modules using in this program
	enum class Module
	{
		SOCKET = 0,
		PACKET_STORAGE = 1,
		LENGTH = 2,
	};

	// Type of message
	enum class TypeMessage
	{
		MES_NO_TYPE = 0,
		ERROR_MESSAGE = 1,
		INFORMATION_MESSAGE = 2,
		SERVICE_MESSAGE = 3
	};

	namespace {
		// Module-> Type module in string
		std::map<Module, std::string> ModuleMap
		{
			{Module::SOCKET, "SOCKET"},
			{Module::PACKET_STORAGE, "PACKET_STORAGE"},
		};

		// Type of message -> string message
		std::map<TypeMessage, std::string> MessageMap
		{
			{TypeMessage::MES_NO_TYPE, "[NO_TYPE]"},
			{TypeMessage::ERROR_MESSAGE, "[ERROR]"},
			{TypeMessage::INFORMATION_MESSAGE, "[INFORMATION]"},
			{TypeMessage::SERVICE_MESSAGE, "[SERVICE]"},
		};

		// Module -> FIle
		std::map<Module, std::string> FileModulePathMap
		{
			{Module::SOCKET, "socket.txt"},
			{Module::PACKET_STORAGE, "packet_storage.txt"},
		};

	}; // end anonimous namespace


	class Logger
	{
	private:

		std::map <Module, std::string> Modules;
		std::map <TypeMessage, std::string> Messages;
		std::map <Module, std::string> FilePath;

		struct FileInfo
		{
			Module moudule_type;
			std::ofstream file;
			char* filename;
			bool file_status = false;


			FileInfo(Module module_name, char* file_name)
			{
				moudule_type = module_name;

				filename = file_name;

				file.open(filename);
				if (file.is_open())
				{
					file_status = true;
				}
			};

			~FileInfo()
			{
				if (file_status == true) file.close();
			}
		};

		std::vector<FileInfo> chunkFiles;
		std::vector<FileInfo>::iterator itFile;

		const char* getModuleName(Module module_name);

		const char* getMessageTypeStr(TypeMessage mes);

		const char* getFilePath(Module module_name);


	public:
		Logger();

		static void WriteLog(Module module_name, TypeMessage mes, const char *text);
	};


}; // end namespace Logging

#endif // !LOGGER_HPP