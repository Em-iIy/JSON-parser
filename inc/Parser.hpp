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

		NodePtr		parse(const Token &token);

		NodePtr		getRoot();

	private:
		Tokenizer	_tokenizer;
		NodePtr		_rootNode;

		NodePtr		_parseString(const Token &token);
		NodePtr		_parseNumber(const Token &token);
		NodePtr		_parseObject(const Token &token);
		NodePtr		_parseList(const Token &token);
		NodePtr		_parseBoolean(const Token &token);
		NodePtr		_parseNull();
};

};