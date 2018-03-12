#pragma once
#include <string>
#include <fstream>
#include <assert.h>
#include <sstream>

namespace Utility
{
	std::string GetFileSource(const std::string& filePath)
	{
		std::ifstream inFile(filePath);

		assert(inFile);

		std::stringstream stringStream;
		std::string fileContents;

		stringStream << inFile.rdbuf();
		fileContents = stringStream.str();

		return fileContents;
	}

}