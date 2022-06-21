#include "Collection.h"
#include <iostream>
#include <typeinfo>

Collection::Collection()
{

}

void Collection::print()
{
	try {
		size_t count = 0;
		for (Figure* fig : figures) {
			std::cout << ++count << ". " << fig << std::endl;;
		}
	}
	catch (std::exception& e)
	{
		throw e;
	}
}

void Collection::create(CommandLineArguments& args)
{
	if (args[1] == "circle")
		figures.push_back(new Circle(std::stod(args[2]), std::stod(args[3]), std::stod(args[4]), args[4]));
	if (args[1] == "rectangle")
		figures.push_back(new Rectangle(std::stod(args[2]), std::stod(args[3]), std::stod(args[4]), std::stod(args[5]), args[6]));
	if (args[1] == "line")
		figures.push_back(new StraightLine(std::stod(args[2]), std::stod(args[3]), std::stod(args[4]), std::stod(args[5]), std::stod(args[6]), args[7]));
}

void Collection::create(char* line)
{
	size_t i = 0;
	std::vector<std::string> args;
	std::string word = "";
	while (line[i])
	{
		if (line[i] != ' ')
			word += line[i];
		else {
			args.push_back(word);
			word = "";
		}
	}
	if (args[0] == "circle")
		figures.push_back(new Circle(std::stod(args[1]), std::stod(args[2]), std::stod(args[3]), args[4]));
	if (args[1] == "rectangle")
		figures.push_back(new Rectangle(std::stod(args[1]), std::stod(args[2]), std::stod(args[3]), std::stod(args[4]), args[5]));
	if (args[1] == "line")
		figures.push_back(new StraightLine(std::stod(args[1]), std::stod(args[2]), std::stod(args[3]), std::stod(args[4]), std::stod(args[5]), args[6]));
}


void Collection::erase(size_t index)
{
	if (index > figures.size())
		throw std::invalid_argument("Not correct index to erase!");

	std::cout << "Erased a ";
	if (typeid(figures.begin() + index) == typeid(Circle))
		std::cout << "circle ";

	if (typeid(figures.begin() + index) == typeid(Rectangle))
		std::cout << "rectangle ";

	if (typeid(figures.begin() + index) == typeid(StraightLine))
		std::cout << "line ";
	std::cout << "(" << index << ")" << std::endl;

	figures.erase(figures.begin() + index);
}

void Collection::translate(size_t index)
{

}



bool Collection::isEmpty()
{
	return figures.empty();
}

std::ofstream& operator<<(std::ofstream& out, Collection& col)
{
	for (auto fig : col.figures)
		out << fig;
	return out;
}
