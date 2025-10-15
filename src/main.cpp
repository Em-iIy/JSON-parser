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
		JSON::NodePtr root = test.getRoot();
		std::cout << root->stringify() << std::endl;
		std::cout << root->get("cool")->stringify() << std::endl;
		JSON::ListPtr numbers = root->get("numbers")->getList();

		std::cout << root->get("numbers")->get(1)->stringify() << std::endl;
		for (JSON::NodePtr node : *numbers)
		{
			std::cout << node->stringify() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Jsp parser;

	parser.run();
	return (0);
}