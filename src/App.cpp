#include "App.hpp"

#include <iostream>

App::App()
{
	_message = "Hello World!";
}

App::~App()
{

}

void	App::run() noexcept
{
	_printMessage();
}

void	App::_printMessage() const noexcept
{
	std::cout << _message << std::endl;
}
