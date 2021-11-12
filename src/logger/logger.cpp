#include "logger.h"

namespace Logging {

	Logger::Logger() {

		Modules = ModuleMap;
		Messages = MessageMap;
		FilePath = FileModulePathMap;

		chunkFiles.reserve(Module::LENGTH);
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


	static void Logger::WriteLog(Module module_name, TypeMessage mes, const char* text)
	{
		for (itFile = chunkFiles.begin(); itFile != chunkFiles.end(); ++itFile)
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