/*
Created by: Emily (Em_iIy) Winnink
Created on: 14/10/2025
*/

#pragma once

#include <string>
#include <fstream>
#include <map>

namespace JSON {

enum class TOKEN {
	END,			// end of tokens
	STRING,			// "
	NUMBER,			// 0-9
	COLON,			// :
	COMMA,			// ,
	OBJECT_OPEN,	// {
	OBJECT_CLOSE,	// }
	LIST_OPEN,		// [
	LIST_CLOSE,		// ]
	BOOLEAN,		// true-false
	NULLED,			// null
};

const std::map<TOKEN, std::string> TokenStrings {
	{TOKEN::END, "END"},
	{TOKEN::STRING, "STRING"},
	{TOKEN::NUMBER, "NUMBER"},
	{TOKEN::COLON, "COLON"},
	{TOKEN::COMMA, "COMMA"},
	{TOKEN::OBJECT_OPEN, "OBJECT_OPEN"},
	{TOKEN::OBJECT_CLOSE, "OBJECT_CLOSE"},
	{TOKEN::LIST_OPEN, "LIST_OPEN"},
	{TOKEN::LIST_CLOSE, "LIST_CLOSE"},
	{TOKEN::BOOLEAN, "BOOLEAN"},
	{TOKEN::NULLED, "NULLED"},
};

class Token {
	public:
		std::string value = "";
		TOKEN		type = TOKEN::END;
};

class Tokenizer {
	public:
		Tokenizer(const std::string &filename);
		~Tokenizer();

		Token	getToken();

	private:
		std::fstream	_file;
};

bool	validateNumber(const std::string &num);

}
