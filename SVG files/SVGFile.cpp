#include "SVGFile.h"
#include <fstream>
#include <iostream>
#include "Collection.h"


std::string SVGFile::fileDirectory = "";
const std::string SVGFile::header =
" <?xml version=\"1.0\" standalone=\"no\"?>\n<svg xmlns = \"http://www.w3.org/2000/svg\" >\n";

const std::string SVGFile::openTag = "<svg>\n";

const std::string SVGFile::closeTag = "</svg>";

bool SVGFile::exist(const std::string& fileName)
{
	std::ifstream file(fileName);
	bool isGood = file.good();
	file.close();
	return isGood;
}
SVGFile::SVGFile()
{
}

void SVGFile::open(std::string path, Collection* col)
{
	fileDirectory = path;
	char line[1000];
	size_t lineCount = 0;

	if (exist(path)) {
		std::ifstream file(fileDirectory);
		while (file.eof())
		{

			file.getline(line, 1000);
			if (lineCount > 3 && strcmp(line, closeTag.c_str()) == 0) {
				try {
					col->create(line);
				}
				catch (std::exception& e) {
					throw e;
				}
			}
		}
		std::cout << "File read successfully!\n";
	}
	std::cout << "File not found!\n";
}

void SVGFile::save(Collection* col)
{

	std::ofstream  file(fileDirectory, std::ios::trunc);
	if (!file.is_open())
	{
		throw std::runtime_error("Can not open file!\n");
	}
	file << header;
	file << openTag;
	file << col;
	file << closeTag;
	file.close();
	std::cout << "File saved successfully!\n";
}

void SVGFile::close(Collection* col)
{
	save(col);
	std::cout << "File closed successfully!\n";
}

void SVGFile::saveAs(const std::string& directry, Collection* col)
{
	remove(fileDirectory.c_str());

	std::ofstream  file(directry);
	if (!file.is_open())
	{
		throw std::runtime_error("Can not open file!\n");
	}
	file << header;
	file << openTag;
	file << col;
	file << closeTag;
	file.close();
	std::cout << "File saved successfully!\n";
}
