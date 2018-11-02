#ifndef COMMON_CONCURRENT_SPLITSTRING_H
#define COMMON_CONCURRENT_SPLITSTRING_H

#include <vector>
#include <string>
#include <cstdint>

namespace common
{
namespace tools
{

/// \brief Split a string into vector.
/// \param string The string to split. Gets mangled during the process.
/// \param delimiter The delimiter to split on.
/// \param maxSplit The maximum times to split.
/// \return Vector of elements that where split on the delimiter.
std::vector<std::string> SplitString(std::string& string, const std::string& delimiter, size_t maxSplit = SIZE_MAX);

}
}

#endif //COMMON_CONCURRENT_SPLITSTRING_H
