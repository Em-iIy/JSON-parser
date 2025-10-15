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

using NodePtr = std::shared_ptr<Node>;
using Object = std::map<std::string, NodePtr>;
using ObjectPtr = std::shared_ptr<Object>;
using List = std::vector<NodePtr>;
using ListPtr = std::shared_ptr<List>;

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
		TYPES					type; // make private
		Values					value; // make private

		std::string				stringify(int indent = 0);
	
		Node::TYPES				getType() const;

		std::string				getString();
		float					getNumber();
		std::shared_ptr<Object>	getObject();
		std::shared_ptr<List>	getList();
		bool					getBool();
		bool					isNull();

		NodePtr					get(const std::string &key);
		NodePtr					get(std::size_t index);

		NodePtr					operator[](std::size_t index);

	private:
		std::string				_stringifyObject(int indent);
		std::string				_stringifyList(int indent);

		std::string				_accessErrorMessage(TYPES target);
		std::string				_accessErrorMessage(const std::string &key);
		std::string				_accessErrorMessage(std::size_t index);
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