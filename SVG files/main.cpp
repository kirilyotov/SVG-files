
#include <iostream>
#include "CMD.h"
#include "CommandLineArguments.h"

int main(int argc, char **argv)
{
	try {
		std::string str;
		std::cout << '>';
		std::getline(std::cin, str);
		CommandLineArguments c(str);
		for (size_t i = 0; i < c.size(); i++) {
			std::cout << c.toLowerCase(c[i]);
		}
	}
	catch (std::exception e) {
		std::cerr << e.what();
	}

	
}
