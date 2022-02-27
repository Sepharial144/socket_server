#include "logger.hpp"

namespace Logging {

	Logger::Logger() {

		Modules = ModuleMap;
		Messages = MessageMap;
		FilePath = FileModulePathMap;

		chunkFiles.reserve(2);
		itFile = chunkFiles.begin();
	};

	const char* Logger::getModuleName(Module module_name)
	{
		return Modules[module_name].c_str();
	};


	const char* Logger::getMessageTypeStr(TypeMessage mes)
	{
		return Messages[mes].c_str();
	};

	const char* Logger::getFilePath(Module module_name) 
	{
		return FilePath[module_name].c_str();
	};


	void Logger::WriteLog(Module module_name, TypeMessage mes, const char* text)
	{
		auto itFile = chunkFiles.begin();
		auto end = chunkFiles.end();
		for (itFile; itFile != end; ++itFile)
		{
			if ( itFile->moudule_type == module_name) {
				if (itFile->file_status == true) 
				{
					itFile->file << getMessageTypeStr(mes) << text;
				} else {
					itFile->file.open();
					itFile->file << getMessageTypeStr(mes) << text;
				}
			}
		}
	}; // end class Logger

}; // end Logging namespace