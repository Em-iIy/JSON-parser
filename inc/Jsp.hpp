/*
Created by: Emily (Em_iIy) Winnink
Created on: 14/10/2025
*/

#pragma once

#include <vector>
#include <string>

#define RESET "\033[m"

#define RED "\033[38;5;1m"
#define GREEN "\033[38;5;2m"

class Jsp {
	public:
		Jsp(int argc, char **argv);
		~Jsp();

		void	run() noexcept;

	private:
		std::vector<std::string>	_inputFiles;

		void	_parseFile(const std::string &filename, int testNo) const noexcept;
};