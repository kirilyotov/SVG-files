#include "CommandLineArguments.h"

void CommandLineArguments::splitLine(std::string& line)
{
	size_t i = 0;
	std::string temp;
	bool quote = false;
	while (line[i])
	{
		if (isQuote(line[i]))
			quote = !quote;
		else
		{
			if (quote || !splitBy(line[i]))
			{
				temp += line[i];
			}

			if (splitBy(line[i]))
			{
				if (!temp.empty()) {
					lineArguments.push_back(temp);
					temp.clear();
				}
			}
		}
		++i;
		if (isNotAllowedSymbol(line[i]))
			throw std::invalid_argument("Not allowed symbol detected! It is not allowed to use " + line[i]);
	}
	if (!temp.empty()) 
		lineArguments.push_back(temp);
	
}

bool CommandLineArguments::splitBy(const char&  ch) const
{

	return ch == ' ' || ch == '\t';
}

bool CommandLineArguments::isQuote(const char& ch) const
{
	return ch == '\"';
}

// https://docs.microsoft.com/en-us/windows/win32/fileio/naming-a-file
bool CommandLineArguments::isNotAllowedSymbol(const char& ch) const
{
	return ch == '*' || ch == '>' || ch == '<' || ch == ':' || ch == '|' || ch == '?';
}


CommandLineArguments::CommandLineArguments(std::string argument)
{
	if (argument.length() == 0)
		throw std::invalid_argument("Empty line!");

	splitLine(argument);
}

std::size_t CommandLineArguments::size() const
{
	return lineArguments.size();
}

std::string& CommandLineArguments::operator[](std::size_t index)
{
	if (isEmpty())
		throw std::runtime_error("No data found!");
	if (index > lineArguments.size())
		throw std::invalid_argument("Not correct index!");

	return lineArguments[index];
}

bool CommandLineArguments::isEmpty() const
{
	return lineArguments.empty();
}

const std::string&   CommandLineArguments::toLowerCase(std::string& line) const
{
	for (char& c : line)  c = tolower(c);
	return line;
}
