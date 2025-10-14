/*
Created by: Emily (Em_iIy) Winnink
Created on: 14/10/2025
*/

#pragma once

#include <fstream>
#include <string>

#include "Node.hpp"
#include "Token.hpp"

namespace JSON {

class Parser {
	public:
		Parser(const std::string &filename);

		

	private:
		Tokenizer	_tokenizer;
};

};