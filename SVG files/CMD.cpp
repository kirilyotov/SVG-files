#include "CMD.h"

bool CMD::exitFromProgram = false;


const std::vector<std::string> integratedCommands = { "open","close", "save", "saveas",
	"help", "exit", "print", "create", "erase", "translate" };


CMD::CMD()
{
}

int CMD::commandNumber(CommandLineArguments& lines) const
{
	for (size_t i = 0; i < integratedCommands.size(); i++) {
		if (integratedCommands[i] == lines[0])
			return i;
	}
	return -1;
}

void CMD::runCommand(CommandLineArguments& lines)
{
	if (lines.isEmpty())
		throw std::runtime_error("Problem with storing user input!\n");
	//TODO create function for commands compare!
	int index = commandNumber(lines);
	switch (index)
	{
	case 0:
		if (lines.size() != TWO_PARAMS)
			throw std::invalid_argument("Function \'open\' takes only two parameters!\n");

		open(lines[1]);
		break;
	case 1:
		if (lines.size() != ONE_PARAM)
			throw std::invalid_argument("Function \'close\' takes only one parameter!\n");

		close();
		break;
	case 2:
		if (lines.size() != ONE_PARAM)
			throw std::invalid_argument("Function \'save\' takes only one parameter!\n");

		save();
		break;
	case 3:
		if (lines.size() != TWO_PARAMS)
			throw std::invalid_argument("Function \'saveas\' takes only two parameters!\n");

		saveAs(lines[1]);
		break;
	case 4:
		help();
		break;
	case 5:
		exit();
		break;
	case 6:
		print();
		break;
	case 7:
		create();
		break;
	case 8:
		erase(std::stod(lines[1]));
		break;
	case 9:
		translate(0);
		break;
	

	default:
		throw std::invalid_argument("\'" + lines[0] + "\' is not recognized as an internal or external command\n"
			"Type \'help\' to see supported commands.\n");
		break;
	}

}



void CMD::open(const std::string& path)
{
	svgFile.open(path, collection);
}

void CMD::close()
{
	svgFile.close(collection);
}

void CMD::save()
{
	svgFile.close(collection);
}

void CMD::saveAs(std::string directory)
{
	svgFile.saveAs(directory, collection);
}

void CMD::help()
{
	std::cout << "The following commands are supported :";
	std::cout << "open                    <file> opens <file>";
	std::cout << "close                   closes currently opened file";
	std::cout << "save                    saves the currently open file";
	std::cout << "saveas                  <file> saves the currently open file in <file>";
	std::cout << "help                    prints this information";
	std::cout << "exit                    exists the program";
	std::cout << "print                   prints in console all figures";
	std::cout << "create                  creates new figure";
	std::cout << "erase <n>               deletes figure with index <n>";
	std::cout << "translate               translates figure with index <n> or all figures if <n> is not given";
	std::cout << "within <option>         prints all figures from same type given by user input <option>\n"
		"it could be circle, rectangle, or line";
}

void CMD::print()
{
	if (!collection->isEmpty())
		collection->print();
}

void CMD::exit()
{
	exitFromProgram = true;
}

void CMD::create()
{
	//collection.create()
}

void CMD::erase(size_t index)
{
	try {
		collection->erase(index);
	}
	catch (std::invalid_argument e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}

void CMD::translate(size_t index)
{
	std::cout << "Right now it is not working!";
}




CMD& CMD::program()
{
	static CMD cmd;
	return cmd;
}



void CMD::run()
{
	while (!exitFromProgram)
	{
		std::string line;
		std::cout << ">";
		std::getline(std::cin, line);

		try {
			CommandLineArguments args(line);

		}
		catch (std::exception& e) {
		std::cerr <<e.what();
		}
	}
	delete[] collection;
}