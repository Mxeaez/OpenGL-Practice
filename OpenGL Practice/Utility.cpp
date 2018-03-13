#include "Utility.h"
#include <assert.h>
#include <sstream>
#include <fstream>

std::string Utility::GetFileSource(const std::string & filePath)
{
	std::ifstream inFile(filePath);

	assert(inFile);

	std::stringstream stringStream;
	std::string fileContents;

	stringStream << inFile.rdbuf();
	fileContents = stringStream.str();

	return fileContents;
}

std::vector<std::string> Utility::Split(std::string string, const std::string& delimiter)
{
	
	std::vector<std::string> splitString;

	int start = 0;

	for (int end = string.find(delimiter); end != std::string::npos; end = string.find(delimiter))
	{
		std::string subString = string.substr(start, end);
		splitString.push_back(subString);
		
		string.erase(start, end + 1);
	}

	if (string.size() > 0)
	{
		splitString.push_back(string);
	}

	return splitString;
}
