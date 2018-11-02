#include "Logger.hpp"
#include "LoggingFunctions.hpp"

namespace common
{
namespace logging
{


Logger::Logger(const std::function<void(std::string)>& logFunction)
	: logFunction(logFunction)
	, killSwitch(false)
{
	this->logThread = std::thread(std::bind(&Logger::LogqueueHandler, this));
}

Logger::~Logger()
{
	this->killSwitch = true;
	this->logMessages.Push("LogExit");
	this->logThread.join();
}

void Logger::Log(const std::string& message)
{
	this->logMessages.Push(message);
}

void Logger::LogqueueHandler()
{
	while (true)
	{
		auto msg = logMessages.Pop();

		if (this->killSwitch && this->logMessages.Empty())
		{
			return;
		}
		this->logFunction(msg);
	}
}

}
}