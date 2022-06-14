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
	bool splitBy(const char& ch)const;
	bool isQuote(const char& ch) const;
	bool  isNotAllowedSymbol(const char& ch) const;
	CommandLineArguments(std::string argument);
	std::size_t size() const;
	std::string& operator[] (std::size_t index);
	bool isEmpty() const;
	const std::string& toLowerCase(std::string& line) const;
};

