#include "LoggingFunctions.hpp"
#include <iostream>

namespace common {

namespace logging {


LogToFile::LogToFile(const std::string& path)
{
	this->file.open(path, std::ios::out | std::ios::binary);
}

LogToFile::~LogToFile()
{
	this->file.close();
}

void LogToFile::Log(const std::string& message)
{
	this->file << message;
}

}
}
