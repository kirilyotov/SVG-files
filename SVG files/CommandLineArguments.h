#pragma once
#include <iostream>
#include <string>
#include <vector>
class CommandLineArguments
{
private:
	//Vector to store data
	std::vector <std::string> lineArguments;
	//Split line by defined char
	void splitLine(std::string& line);
	//Split line by defined char
	bool splitBy(const char& ch)const;

	bool isQuote(const char& ch) const;
	//Not Allowed found
	bool  isNotAllowedSymbol(const char& ch) const;
public:
	//Constructor with parameters
	CommandLineArguments(std::string argument);
	//Size of vector
	std::size_t size() const;
	//Data in given index
	std::string& operator[] (std::size_t index);
	//LineArgumetns vector is empty
	bool isEmpty() const;
	//Line to lower case
	const std::string& toLowerCase(std::string& line) const;
};

