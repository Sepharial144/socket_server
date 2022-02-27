#include "logger.hpp"

namespace Logging {

	Logger::Logger() {

		_modules = ModuleMap;
		_messages = MessageMap;
		_filePath = FileModulePathMap;

		_chunkFiles.reserve(2);
	};

	const char* Logger::getModuleName(Module module_name)
	{
		return _modules[module_name].c_str();
	};


	const char* Logger::getMessageTypeStr(TypeMessage mes)
	{
		return _messages[mes].c_str();
	};

	const char* Logger::getFilePath(Module module_name) 
	{
		return _filePath[module_name].c_str();
	};

	auto Logger::findIterator(Module module_name) -> std::vector<FileInfo>::const_iterator
	{
		std::vector<FileInfo>::const_iterator begin = _chunkFiles.begin();
		auto end = _chunkFiles.end();
		for (begin; begin != end; ++begin)
		{
			if ( begin->_moudule_type == module_name)
				return begin;
		}
	}

	void Logger::WriteLog(Module module_name, TypeMessage mes, const char* text)
	{
		auto fileIterator = findIterator(module_name);
		if (fileIterator->_file.is_open() == true) 
		{
			fileIterator->_file << getMessageTypeStr(mes) << text;
		} else {
			fileIterator->_file.open(fileIterator->_filename);
			fileIterator->_file << getMessageTypeStr(mes) << text;
		}
	}
	}; // end class Logger

}; // end Logging namespace