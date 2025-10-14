/*
Created by: Emily (Em_iIy) Winnink
Created on: 14/10/2025
*/

#include "Jsp.hpp"
#include "Parser.hpp"

#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	try
	{
		JSON::Parser test(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Jsp parser;

	parser.run();
	return (0);
}