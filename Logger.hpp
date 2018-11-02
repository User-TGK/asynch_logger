#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <string>
#include <functional>
#include <thread>
#include <atomic>

#include <common/tools/ConcurrentQueue.hpp>

namespace common
{
namespace logging
{

class Logger
{
public:
	/// \brief constructor to create a logobject
	/// \param logFunction the function that handles the logging (tells where to be logged)
	Logger(const std::function<void(std::string)>& logFunction);

	/// \brief default destructor
	~Logger();

	/// \brief The log function logs the message based on the initialized logfunction (where to log)
	/// \param message the message to be logged
	void Log(const std::string& message);

	/// \brief Function that will Log all queued messages
	void LogqueueHandler();

private:
	/// \brief Function instance that handles the logging
	/// (Examples: WriteToFile, WriteToCout in LoggingFunctions.hpp).
	std::function<void(std::string)> logFunction;

	/// \brief Will be false while thread still receives messages to be logged, true if destructor was called.
	std::atomic<bool> killSwitch;

	/// \brief Log thread that runs.
	std::thread logThread;

	/// \brief hreadsafe queue of messages to be logged.
	tools::ConcurrentQueue<std::string> logMessages;
};

#endif /* LOGGER_HPP_ */

}
}