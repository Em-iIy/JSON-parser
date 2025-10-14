/*
Created by: Emily (Em_iIy) Winnink
Created on: 14/10/2025
*/

#pragma once

#include <string>

class Jsp {
	public:
		Jsp();
		~Jsp();

		void	run() noexcept;

	private:
		std::string	_message{};

		void	_printMessage() const noexcept;
};