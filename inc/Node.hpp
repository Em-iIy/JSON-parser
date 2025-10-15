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
			~Values() {};
			std::unique_ptr<std::string>	string;
			std::unique_ptr<float>			number;
			std::unique_ptr<Object>			object;
			std::unique_ptr<List>			list;
			std::unique_ptr<bool>			boolean;
		};
		TYPES			type;
		Values			value;
};

};