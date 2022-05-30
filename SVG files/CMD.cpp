#include "CMD.h"

const std::string CMD::header =
" <?xml version=\"1.0\" standalone=\"no\"?>\n< svg xmlns = \"http://www.w3.org/2000/svg\" >\n";

CMD& CMD::program()
{
    static CMD cmd;
    return cmd;
}



void CMD::run()
{
    
}


CMD::CMD()
{
}

void CMD::print()
{
    if(!collection.isEmpty())
        collection.print();
}

void CMD::create()
{
}

void CMD::erase(size_t index)
{
    try{
    collection.erase(index);
    }
    catch(std::invalid_argument e){
        std::cerr << e.what() << std::endl;
    }
    catch(...){
        std::cerr << "Unexpected exception!" << std::endl;
    }
}

void CMD::translate(size_t index)
{

}

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
