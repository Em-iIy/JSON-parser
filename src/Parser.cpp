/*
Created by: Emily (Em_iIy) Winnink
Created on: 14/10/2025
*/

#include <exception>
#include <iostream>

#include "Parser.hpp"

namespace JSON {

Parser::Parser(const std::string &filename)try : _tokenizer(filename)
{
	while (true)
	{
		Token	cur = _tokenizer.getToken();
		std::cout << TokenStrings.at(cur.type) << ": <" << cur.value << ">" << std::endl;
		if (cur.type == TOKEN::END)
			return;
	}
}
catch(const std::runtime_error &e)
{
	throw std::runtime_error("JSON: Parser: " + std::string(e.what()));
}

}