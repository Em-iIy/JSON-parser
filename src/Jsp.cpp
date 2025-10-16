/*
Created by: Emily (Em_iIy) Winnink
Created on: 14/10/2025
*/

#include "../json-parser.hpp"
#include "Jsp.hpp"

#include <iostream>

Jsp::Jsp(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Missing input files" << std::endl;
		return ;
	}
	for (int i = 1; i < argc; ++i)
		_inputFiles.push_back(argv[i]);
}

Jsp::~Jsp()
{

}

void	Jsp::run() noexcept
{
	int count = 0;
	for (const std::string &filename : _inputFiles)
	{
		_parseFile(filename, count);
		++count;
	}
}

void	Jsp::_parseFile(const std::string &filename, int testNo) const noexcept
{
	try
	{
		JSON::Parser parsed(filename);
		std::cout << "OK Test " << testNo << " " << filename << "\n";
		// std::cout << parsed.getRoot()->stringify() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "KO Test " << testNo << " " << filename << ":"<< e.what() << "\n";
	}
	
}
