/*
Created by: Emily (Em_iIy) Winnink
Created on: 14/10/2025
*/

#include "Jsp.hpp"
#include "Node.hpp"

#include <iostream>

Jsp::Jsp()
{
	_message = "Hello World!";
}

Jsp::~Jsp()
{

}

void	Jsp::run() noexcept
{
	_printMessage();
}

void	Jsp::_printMessage() const noexcept
{
	std::cout << _message << std::endl;
}
