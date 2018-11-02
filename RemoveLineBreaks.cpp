#include "RemoveLineBreaks.hpp"

#include <algorithm>

namespace common
{
namespace tools
{

std::string RemoveLineBreaks(const std::string& string)
{
	std::string copy = string;
	copy.erase(
		std::remove(copy.begin(), copy.end(), '\r'),
		copy.end()
	);
	copy.erase(
		std::remove(copy.begin(), copy.end(), '\n'),
		copy.end()
	);

	return copy;
}

}
}