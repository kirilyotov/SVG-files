#include "CMD.h"

const std::string CMD::header =
" <?xml version=\"1.0\" standalone=\"no\"?>\n< svg xmlns = \"http://www.w3.org/2000/svg\" >\n";

const std::vector<std::string> integratedCommands = { "open","close", "save", "saveas",
    "help", "exit", "print", "create", "erase", "translate", "within" };


CMD::CMD()
{
}


void CMD::isCorrectCommand(CommandLineArguments& lines)
{
    if (lines.isEmpty())
        throw std::runtime_error("Problem with storing user input!");
    //TODO create function for commands compare!
    long long  index = 0;
    switch (index)
    {
    case 0:
        open(lines[1]);
        break;
    case 1:
        close();
        break;
    case 2:
        save();
        break;
    case 3:
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
    case 10:
        within();
        break;

    default:
        std::cout << "\'" << lines[0] << "\' is not recognized as an internal or external command\n"
            "Type \'help\' to see supported commands";
        break;
    }

}

void CMD::open(std::string file)
{
}

void CMD::close()
{
}

void CMD::save()
{
}

void CMD::saveAs(std::string directory)
{
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
    if (!collection.isEmpty())
        collection.print();
}

void CMD::exit()
{
}

void CMD::create()
{
}

void CMD::erase(size_t index)
{
    try {
        collection.erase(index);
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

}
//TODO filter & map
void CMD::within()
{

}

void CMD::writeToFile()
{
}

void CMD::readFromFile()
{
}

void CMD::createTemporaryFile()
{
}


CMD& CMD::program()
{
    static CMD cmd;
    return cmd;
}



void CMD::run()
{
    while (true)
    {
        std::string line;
        std::cout << ">";
        std::getline(std::cin, line);

        try {
            CommandLineArguments args(line);

        }
        catch (...) {
            std::cout << "Zarezi brat moje da stanesh dunerdjiq!";
        }
    }
}