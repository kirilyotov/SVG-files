#include "CommandLineArguments.h"

void CommandLineArguments::splitLine(std::string& line)
{
	size_t i = 0;
	std::string temp;

	while (line[i])
	{
		if (line[i] != ' ')
		{
			temp += line[i];
		}

		if (line[i] == ' ')
		{
			if (!temp.empty()) {
				lineArguments.push_back(temp);
				temp.clear();
			}
		}
		++i;
	}
	if (!temp.empty()) 
		lineArguments.push_back(temp);
	
}

CommandLineArguments::CommandLineArguments(std::string _lineArguement)
{
	if (_lineArguement.length() == 0)
		throw std::invalid_argument("Empty line!");

	splitLine(_lineArguement);
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
