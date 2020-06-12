#pragma once
#include <string>

class IO
{
public:
	static void Read(const std::string& Name, unsigned char** data);
	static void Write(const std::string& Name, unsigned char** data);
};

