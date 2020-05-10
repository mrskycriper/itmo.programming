#pragma once

#include <string>
#include <iostream>

class QueueException : public std::exception
{
public:
	explicit QueueException(const std::string& error = "")
	{
		std::cerr << error << std::endl;
	}
};
