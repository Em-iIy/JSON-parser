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
	
	private:
		std::string		_stringifyObject(int indent);
		std::string		_stringifyList(int indent);
};

};