#pragma once
#include <iostream>
#include <string>
#include "Collection.h"
class SVGFile //Singleton class
{
private:
	//Static member for header of svg file
	static const  std::string header;
	//Static member for open tag of svg file
	static const  std::string openTag;
	//Static member for close tag of svg file
	static const  std::string closeTag;

	//static string for file directory
	static std::string fileDirectory;
	//True if file exists
	bool exist(const std::string& file);
public:

	SVGFile();
	SVGFile(const SVGFile& other) = delete;
	SVGFile& operator= (const SVGFile& other) = delete;
	//Open file
	void open(std::string path, Collection* col);
	//Save file
	void save(Collection* col);
	//Close file
	void close(Collection* col);
	//Save as file
	void saveAs(const std::string& directry, Collection* col);
};

