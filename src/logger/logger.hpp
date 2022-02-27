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
		MES_NO_TYPE,
		ERROR_MESSAGE,
		INFORMATION_MESSAGE,
		SERVICE_MESSAGE
	};

	namespace {
		// Module-> Type module in string
		std::map<Module, std::string> ModuleMap
		{
			{Module::SOCKET, "SOCKET MODULE"},
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

		std::map <Module, std::string> _modules;
		std::map <TypeMessage, std::string> _messages;
		std::map <Module, std::string> _filePath;

		struct FileInfo
		{
			Module _moudule_type;
			std::ofstream _file;
			char* _filename;

			FileInfo(Module module_name, char* file_name):
			_moudule_type(module_name),
			_filename(file_name)
			{};

			~FileInfo()
			{}
		};

		std::vector<FileInfo> _chunkFiles;
		std::vector<FileInfo>::const_iterator _itFile;

		const char* getModuleName(Module module_name);

		const char* getMessageTypeStr(TypeMessage mes);

		auto Logger::findIterator(Module module_name) -> std::vector<FileInfo>::const_iterator;

		const char* getFilePath(Module module_name);


	public:
		Logger();

		void WriteLog(Module module_name, TypeMessage mes, const char *text);
	};


}; // end namespace Logging

#endif // !LOGGER_HPP