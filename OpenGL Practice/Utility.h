#pragma once
#include <string>
#include <vector>

namespace Utility
{
	std::string GetFileSource(const std::string& filePath);

	std::vector<std::string> Split(std::string string, const std::string& delimiter);
}