#include "SplitString.hpp"


namespace common
{
namespace tools
{


std::vector <std::string> SplitString(std::string& string, const std::string& delimiter, size_t maxSplit)
{
	std::vector <std::string> split;

	size_t splitCount = 0;
	size_t pos = 0;
	std::string token;
	while ((pos = string.find(delimiter)) != std::string::npos && splitCount < maxSplit)
	{
		token = string.substr(0, pos);
		split.push_back(token);
		string.erase(0, pos + delimiter.length());
		splitCount++;
	}
	split.push_back(string);

	return split;
}

}
}