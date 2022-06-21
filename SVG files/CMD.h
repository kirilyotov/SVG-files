#pragma once

#include "Collection.h"
#include "CommandLineArguments.h"
#include "SVGFile.h"
//Singleton class
class CMD
{
private:
	CMD();

	//Collection of figures
	Collection* collection;
	//Integrated commands
	static const std::vector<std::string> integratedCommands;
	//parameters 
	static const size_t TWO_PARAMS = 2;
	static const size_t ONE_PARAM = 1;
	
	static bool exitFromProgram;  
	//Number of integrated command
	int commandNumber( CommandLineArguments& lines) const;
	//Run command by number
	void runCommand(CommandLineArguments& lines) ;

	//svg file
	SVGFile svgFile;
	//Open file
	void open(const std::string& file); //0
	//Close file
	void close();//1
	//Save file
	void save();//2
	//Save as file
	void saveAs(std::string directory);//3
	//help info user output
	void help();//4
	//Print data
	void print();//5
	//Exit from program
	void exit();//6
	//Create figure
	void create();//7
	//Delete figure by index
	void erase(size_t index);//8
	//Translate figure
	void translate(size_t index);//9





public:
	//Deleting copy constructor
	CMD(const CMD& other) = delete;
	//Deleting operator=
	CMD& operator= (const CMD& other) = delete;
	//Start point of singleton class
	static CMD& program();
	//Run program
	void run();
	

};

