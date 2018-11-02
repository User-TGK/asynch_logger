/*
 * LoggingFunctions.hpp
 * This file contains example functions to be used for logging
 *
 *  Created on: 24 May 2017
 *      Author: Ties
 */

#ifndef COMMON_SRC_COMMON_LOGGING_LOGGINGFUNCTIONS_HPP_
#define COMMON_SRC_COMMON_LOGGING_LOGGINGFUNCTIONS_HPP_

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <memory>

namespace common {

namespace logging {

/// \brief example function WriteToCout is an example function that writes a line to the console output
/// \param message the message to be logged
inline void WriteToCout(const std::string& message)
{
	std::cout << message << std::endl;
}

class LogToFile
{
public:
	/// \brief Create LogToFile object
	/// \param path path to file where to be logged
	LogToFile(const std::string& path);

	/// \brief Destructor LogToFile
	~LogToFile();

	/// \brief Log function will be binded to Log.Log
	/// \param message message to be logged
	void Log(const std::string& message);

private:
	/// \brief file where to be logged to
	std::fstream file;
};

}
}
#endif /* COMMON_SRC_COMMON_LOGGING_LOGGINGFUNCTIONS_HPP_ */
