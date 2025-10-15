/*
Created by: Emily (Em_iIy) Winnink
Created on: 14/10/2025
*/

#pragma once

#include <map>
#include <vector>
#include <string>
#include <memory>

namespace JSON {

class Node;

using Object = std::map<std::string, std::shared_ptr<Node>>;
using List = std::vector<std::shared_ptr<Node>>;

class Node {
	public:
		enum class TYPES {STRING, NUMBER, OBJECT, LIST, BOOLEAN, NULLED};
		union Values {
			Values(): number(nullptr) {};
			~Values() {number = nullptr;};
			std::shared_ptr<std::string>	string;
			std::shared_ptr<float>			number;
			std::shared_ptr<Object>			object;
			std::shared_ptr<List>			list;
			std::shared_ptr<bool>			boolean;
		};
		TYPES			type;
		Values			value;

		std::string		stringify(int indent = 0);
	
		Node::TYPES		getType() const;

		std::string		getString();
		float			getNumber();
		bool			getBool();
		bool			isNull();

	private:
		std::string		_stringifyObject(int indent);
		std::string		_stringifyList(int indent);
		std::string		_stringifyType();
};

const std::map<Node::TYPES, std::string> TypeStrings {
	{Node::TYPES::STRING, "STRING"}, 
	{Node::TYPES::NUMBER, "NUMBER"}, 
	{Node::TYPES::OBJECT, "OBJECT"}, 
	{Node::TYPES::LIST, "LIST"}, 
	{Node::TYPES::BOOLEAN, "BOOLEAN"}, 
	{Node::TYPES::NULLED, "NULLED"},
};

};