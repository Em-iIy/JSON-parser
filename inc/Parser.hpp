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

		std::shared_ptr<Node>	getRoot();

	private:
		Tokenizer				_tokenizer;
		std::shared_ptr<Node>	_rootNode;

		std::shared_ptr<Node>	_parseString(const Token &token);
		std::shared_ptr<Node>	_parseNumber(const Token &token);
		std::shared_ptr<Node>	_parseObject();
		std::shared_ptr<Node>	_parseList();
		std::shared_ptr<Node>	_parseBoolean(const Token &token);
		std::shared_ptr<Node>	_parseNull(const Token &token);
};

};