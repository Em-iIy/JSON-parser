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
		switch (cur.type)
		{
		case TOKEN::STRING:
		{
			std::shared_ptr<Node>	parsedString = _parseString(cur);
			if (!_rootNode)
				_rootNode = parsedString;
			break ;
		}
		case TOKEN::NUMBER:
		{
			std::shared_ptr<Node>	parsedNumber = _parseNumber(cur);
			if (!_rootNode)
				_rootNode = parsedNumber;
			break ;
		}
		case TOKEN::OBJECT_OPEN:
		{
			std::shared_ptr<Node>	parsedObject = _parseObject();
			if (!_rootNode)
				_rootNode = parsedObject;
			break ;
		}
		case TOKEN::LIST_OPEN:
		{
			std::shared_ptr<Node>	parsedList = _parseList();
			if (!_rootNode)
				_rootNode = parsedList;
			break ;
		}
		case TOKEN::BOOLEAN:
		{
			std::shared_ptr<Node>	parsedBoolean = _parseBoolean(cur);
			if (!_rootNode)
				_rootNode = parsedBoolean;
			break ;
		}
		case TOKEN::NULLED:
		{
			std::shared_ptr<Node>	parsedNull = _parseNull(cur);
			if (!_rootNode)
				_rootNode = parsedNull;
			break ;
		}
		default:
			break ;
		}
		sizeof(Node);
	}
}
catch(const std::runtime_error &e)
{
	throw std::runtime_error("JSON: Parser: " + std::string(e.what()));
}

std::shared_ptr<Node>	Parser::getRoot()
{
	return (_rootNode);
}

std::shared_ptr<Node>	Parser::_parseString(const Token &token)
{
	std::shared_ptr<Node> ret = std::make_shared<Node>();
	ret->type = Node::TYPES::STRING;
	ret->value.string = new std::string(token.value); // maybe do something else????
	return ret;
}

std::shared_ptr<Node>	Parser::_parseNumber(const Token &token)
{

}

std::shared_ptr<Node>	Parser::_parseObject()
{

}

std::shared_ptr<Node>	Parser::_parseList()
{

}

std::shared_ptr<Node>	Parser::_parseBoolean(const Token &token)
{

}

std::shared_ptr<Node>	Parser::_parseNull(const Token &token)
{

}

}
