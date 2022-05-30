#include "Collection.h"
#include <iostream>
#include <typeinfo>
Collection::Collection()
{
	
}

void Collection::print()
{
	size_t count = 1;
	for (Figure* fig : figures) {
		std::cout << count << ". " << fig << std::endl;;
	}
}

void Collection::create()
{

	//figures.push_back(new Circle(3,4,5,"  "));
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

void Collection::within()
{

}

bool Collection::isEmpty()
{
	return figures.empty();
}
