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