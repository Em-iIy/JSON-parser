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
			std::string	*string;
			float		number;
			Object		*object;
			List		*list;
			bool		boolean;
		};
		TYPES			type;
		Values			value;
		
};

};