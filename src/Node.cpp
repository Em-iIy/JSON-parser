/*
Created by: Emily (Em_iIy) Winnink
Created on: 15/10/2025
*/

#include "Node.hpp"

namespace JSON {

std::string	Node::stringify(int indent)
{
	std::string	ret = "";
	switch (type)
	{
	case TYPES::STRING:
		ret += "\"" + *value.string + "\"";
		break ;
	case TYPES::NUMBER:
		ret += std::to_string(*value.number);
		break ;
	case TYPES::OBJECT:
		ret += _stringifyObject(indent);
		break ;
	case TYPES::LIST:
		ret += _stringifyList(indent);
		break ;
	case TYPES::BOOLEAN:
		ret += *value.boolean ? "true" : "false";
		break ;
	case TYPES::NULLED:
		ret += "null";
		break ;
	
	default:
		break;
	}
	return (ret);
}

std::string	Node::_stringifyObject(int indent)
{
	std::size_t	i = 0;
	std::size_t	len = value.object->size();
	std::string	ret ="{\n";
	for (auto &[key, val] : *value.object)
	{
		ret += std::string(indent + 1, '\t');
		ret += "\"" + key + "\": " + val->stringify(indent + 1);
		i++;
		if (i < len)
			ret += ",";
		ret += "\n";
	}
	ret += std::string(indent, '\t');
	ret += "}";
	return (ret);
}

std::string	Node::_stringifyList(int indent)
{
	std::size_t	i = 0;
	std::size_t	len = value.list->size();
	std::string	ret = "[\n";
	for (std::shared_ptr<Node> &val : *value.list)
	{
		ret += std::string(indent + 1, '\t');
		ret += val->stringify(indent + 1);
		i++;
		if (i < len)
			ret += ",";
		ret += "\n";
	}
	ret += std::string(indent, '\t');
	ret += "]";
	return (ret);
}

}