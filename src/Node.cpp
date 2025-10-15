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
	std::string	ret ="{";
	if (len > 0)
	{
		ret += "\n";
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
	}
	ret += "}";
	return (ret);
}

std::string	Node::_stringifyList(int indent)
{
	std::size_t	i = 0;
	std::size_t	len = value.list->size();
	std::string	ret ="[";
	if (len > 0)
	{
		ret += "\n";
		for (NodePtr &val : *value.list)
		{
			ret += std::string(indent + 1, '\t');
			ret += val->stringify(indent + 1);
			i++;
			if (i < len)
				ret += ",";
			ret += "\n";
		}
		ret += std::string(indent, '\t');
	}
	ret += "]";
	return (ret);
}

Node::TYPES	Node::getType() const
{
	return (type);
}

std::string	Node::getString()
{
	if (type != TYPES::STRING)
		throw std::runtime_error(_accessErrorMessage(TYPES::STRING));
	return (*value.string);
}

float	Node::getNumber()
{
	if (type != TYPES::NUMBER)
		throw std::runtime_error(_accessErrorMessage(TYPES::NUMBER));
	return (*value.number);
}

std::shared_ptr<Object>	Node::getObject()
{
	if (type != TYPES::OBJECT)
		throw std::runtime_error(_accessErrorMessage(TYPES::OBJECT));
	return (value.object);
}

std::shared_ptr<List>	Node::getList()
{
	if (type != TYPES::LIST)
		throw std::runtime_error(_accessErrorMessage(TYPES::LIST));
	return (value.list);
}

bool	Node::getBool()
{
	if (type != TYPES::BOOLEAN)
		throw std::runtime_error(_accessErrorMessage(TYPES::BOOLEAN));
	return (*value.boolean);
}

bool	Node::isNull()
{
	return (type == TYPES::NULLED);
}

NodePtr	Node::get(const std::string &key)
{
	if (type != TYPES::OBJECT)
		throw std::runtime_error(_accessErrorMessage(TYPES::OBJECT));
	if (!value.object->contains(key))
		throw std::runtime_error(_accessErrorMessage(key));
	return (value.object->at(key));
}

NodePtr	Node::get(std::size_t index)
{
	return ((*this)[index]);
}

NodePtr	Node::operator[](std::size_t index)
{
	if (index >= value.list->size())
		throw std::runtime_error(_accessErrorMessage(index));
	return ((*value.list)[index]);
}

std::string				Node::_accessErrorMessage(TYPES target)
{
	std::string errorMsg = "JSON: access: wrong type - expected: `" + TypeStrings.at(target) + "` found:\t`" + TypeStrings.at(type) + "` -> ";
	errorMsg += stringify(1);
	return (errorMsg);
}

std::string				Node::_accessErrorMessage(const std::string &key)
{
	std::string errorMsg = "JSON: access: key `" + key + "` not found - \t`" + TypeStrings.at(type) + "` -> ";
	errorMsg += stringify(1);
	return (errorMsg);
}

std::string				Node::_accessErrorMessage(std::size_t index)
{
	std::string errorMsg = "JSON: access: index `" + std::to_string(index) + "` out of range - \t`" + TypeStrings.at(type) + "` -> ";
	errorMsg += stringify(1);
	return (errorMsg);
}

}