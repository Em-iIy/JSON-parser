/*
Created by: Emily (Em_iIy) Winnink
Created on: 14/10/2025
*/

#include "Token.hpp"

namespace JSON {

Tokenizer::Tokenizer(const std::string &filename)
{
	_file.open(filename, std::fstream::in);
	if (!_file.is_open())
		throw std::runtime_error("could not open: " + filename);
}

Token	Tokenizer::getToken()
{
	char			c;
	Token			ret;
	// std::streampos	start = _file.tellg();
	
	_file.get(c);
	if (_file.eof())
		return (ret); // end of file token by default
	while (std::isspace(static_cast<int>(c)))
	{
		_file.get(c);
		if (_file.eof())
			break ;
	}
	if (std::isspace(static_cast<int>(c)))
		return (ret); // end of file token by default
	switch (c)
	{
	case '"':
		ret.type = TOKEN::STRING;
		_file.get(c);
		while (c != '"' && !_file.eof())
		{
			ret.value += c;
			_file.get(c);
		}
		break ;
	case '-': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
		ret.type = TOKEN::NUMBER;
		_file.get(c);
		while ((c == '-' || c == '.' || std::isdigit(static_cast<int>(c))) && !_file.eof())
		{
			ret.value += c;
			_file.get(c);
		}
		break ;
	case ':':
		ret.type = TOKEN::COLON;
		ret.value = c;
		break ;
	case ',':
		ret.type = TOKEN::COMMA;
		ret.value = c;
		break ;
	case '{':
		ret.type = TOKEN::OBJECT_OPEN;
		ret.value = c;
		break ;
	case '}':
		ret.type = TOKEN::OBJECT_CLOSE;
		ret.value = c;
		break ;
	case '[':
		ret.type = TOKEN::LIST_OPEN;
		ret.value = c;
		break ;
	case ']':
		ret.type = TOKEN::LIST_CLOSE;
		ret.value = c;
		break ;
	case 't':
		ret.value += c;
		for (int i = 0; i < 3; i++)
		{
			_file.get(c);
			ret.value += c;
			if (_file.eof())
				return (ret);
		}
		if (ret.value == "true")
			ret.type = TOKEN::BOOLEAN;
		break ;
	case 'f':
		ret.value += c;
		for (int i = 0; i < 4; i++)
		{
			_file.get(c);
			ret.value += c;
			if (_file.eof())
				return (ret);
		}
		if (ret.value == "false")
			ret.type = TOKEN::BOOLEAN;
		break ;
	case 'n':
		ret.value += c;
		for (int i = 0; i < 3; i++)
		{
			_file.get(c);
			ret.value += c;
			if (_file.eof())
				return (ret);
		}
		if (ret.value == "null")
			ret.type = TOKEN::NULLED;
		break ;
	default:
		break ;
	}
	return (ret);
}

Tokenizer::~Tokenizer()
{
	if (_file.is_open())
		_file.close();
}

}