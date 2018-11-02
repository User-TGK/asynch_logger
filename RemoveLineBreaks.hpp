#ifndef COMMON_CONCURRENT_REMOVELINEBREAKS_H
#define COMMON_CONCURRENT_REMOVELINEBREAKS_H

#include <string>

namespace common
{
namespace tools
{

/// \brief Remove line breaks from a string.
/// \param string The string to remove line breaks for.
/// \return A new string with the linebreaks removed.
std::string RemoveLineBreaks(const std::string& string);

}
}

#endif //COMMON_CONCURRENT_REMOVELINEBREAKS_H
