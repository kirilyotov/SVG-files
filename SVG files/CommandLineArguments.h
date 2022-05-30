#pragma once
#include <iostream>
#include <string>
#include <vector>
class CommandLineArguments
{
private:
	std::vector <std::string> lineArguments;
	void splitLine(std::string& line);

public:
	CommandLineArguments(std::string _lineArguement);
	std::size_t size() const;
	std::string& operator[] (std::size_t index);
	bool isEmpty() const;
	const std::string& toLowerCase(std::string& line) const;
};

