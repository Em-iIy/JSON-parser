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
	Token	cur = _tokenizer.getToken();
	if (cur.type == TOKEN::END)
		return;
	NodePtr	node = parse(cur);
	if (_rootNode == nullptr)
		_rootNode = node;
}
catch(const std::runtime_error &e)
{
	throw std::runtime_error("JSON: Parser: " + std::string(e.what()));
}

NodePtr	Parser::parse(const Token &token)
{
	NodePtr	ret = nullptr;
	switch (token.type)
	{
	case TOKEN::STRING:
	{
		ret = _parseString(token);
		break ;
	}
	case TOKEN::NUMBER:
	{
		ret = _parseNumber(token);
		break ;
	}
	case TOKEN::OBJECT_OPEN:
	{
		ret = _parseObject(token);
		break ;
	}
	case TOKEN::LIST_OPEN:
	{
		ret = _parseList(token);
		break ;
	}
	case TOKEN::BOOLEAN:
	{
		ret = _parseBoolean(token);
		break ;
	}
	case TOKEN::NULLED:
	{
		ret = _parseNull();
		break ;
	}
	default:
		break ;
	}
	return (ret);
}


NodePtr	Parser::getRoot()
{
	return (_rootNode);
}

NodePtr	Parser::_parseString(const Token &token)
{
	NodePtr	ret = std::make_shared<Node>();
	ret->type = Node::TYPES::STRING;
	ret->value.string = std::make_shared<std::string>(token.value); // maybe do something else????
	return ret;
}

NodePtr	Parser::_parseNumber(const Token &token)
{
	NodePtr	ret = std::make_shared<Node>();
	ret->type = Node::TYPES::NUMBER;
	ret->value.number = std::make_shared<float>(std::stof(token.value));
	return ret;
}

NodePtr	Parser::_parseObject(const Token &token)
{
	Token					prev = token;
	Token					cur;
	std::string				key = "";
	NodePtr	val = nullptr;

	NodePtr	ret = std::make_shared<Node>();
	ret->type = Node::TYPES::OBJECT;
	ret->value.object = std::make_shared<Object>();
	while (true)
	{
		cur = _tokenizer.getToken();
		if (cur.type == TOKEN::END)
			throw std::runtime_error("syntax error at: " + prev.value);
		if (cur.type == TOKEN::OBJECT_CLOSE)
			break ;
		if (cur.type != TOKEN::STRING)
			throw std::runtime_error("syntax error at: `" + prev.value + "` - expected: `" + TokenStrings.at(TOKEN::STRING) + "` found: `" + TokenStrings.at(cur.type) + "`");
		key = cur.value;
		prev = cur;

		cur = _tokenizer.getToken();
		if (cur.type != TOKEN::COLON)
			throw std::runtime_error("syntax error at: `" + prev.value + "` - expected: `" + TokenStrings.at(TOKEN::COLON) + "` found: `" + TokenStrings.at(cur.type) + "`");
		prev = cur;

		cur = _tokenizer.getToken();
		val = parse(cur);
		if (val == nullptr)
			throw std::runtime_error("syntax error at: `" + prev.value + "` - expected: `value` found: `" + TokenStrings.at(cur.type) + "`");
		prev = cur;

		ret->value.object->insert({key, val});

		cur = _tokenizer.getToken();
		if (cur.type == TOKEN::OBJECT_CLOSE)
			break ;
		if (cur.type != TOKEN::COMMA)
			throw std::runtime_error("syntax error at: `" + prev.value + "` - expected: `" + TokenStrings.at(TOKEN::COMMA) + "` or `" + TokenStrings.at(TOKEN::OBJECT_CLOSE) + "` found: `" + TokenStrings.at(cur.type) + "`");
		prev = cur;
	}
	return ret;
}

NodePtr	Parser::_parseList(const Token &token)
{
	Token					prev = token;
	Token					cur;
	NodePtr	val = nullptr;

	NodePtr	ret = std::make_shared<Node>();
	ret->type = Node::TYPES::LIST;
	ret->value.list = std::make_shared<List>();
	while (true)
	{
		cur = _tokenizer.getToken();
		if (cur.type == TOKEN::END)
			throw std::runtime_error("syntax error at: " + prev.value);
		if (cur.type == TOKEN::LIST_CLOSE)
			break ;
		
		val = parse(cur);
		if (val == nullptr)
			throw std::runtime_error("syntax error at: `" + prev.value + "` - expected: `value` found: `" + TokenStrings.at(cur.type) + "`");
		prev = cur;

		ret->value.list->push_back(val);

		cur = _tokenizer.getToken();
		if (cur.type == TOKEN::LIST_CLOSE)
			break ;
		if (cur.type != TOKEN::COMMA)
			throw std::runtime_error("syntax error at: `" + prev.value + "` - expected: `" + TokenStrings.at(TOKEN::COMMA) + "` or `" + TokenStrings.at(TOKEN::LIST_CLOSE) + "` found: `" + TokenStrings.at(cur.type) + "`");
		prev = cur;
	}
	return ret;
}

NodePtr	Parser::_parseBoolean(const Token &token)
{
	NodePtr	ret = std::make_shared<Node>();
	bool					val = true;
	if (token.value == "false")
		val = false;			
	ret->type = Node::TYPES::BOOLEAN;
	ret->value.boolean = std::make_shared<bool>(val);
	return ret;
}

NodePtr	Parser::_parseNull()
{
	NodePtr	ret = std::make_shared<Node>();
	ret->type = Node::TYPES::NULLED;
	ret->value.boolean = nullptr;
	return ret;
}

}
