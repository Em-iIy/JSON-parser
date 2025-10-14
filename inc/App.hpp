#pragma once

#include <string>

class App {
	public:
		App();
		~App();

		void	run() noexcept;

	private:
		std::string	_message{};

		void	_printMessage() const noexcept;
};