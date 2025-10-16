/*
Created by: Emily (Em_iIy) Winnink
Created on: 14/10/2025
*/

#pragma once

#include <vector>
#include <string>

class Jsp {
	public:
		Jsp(int argc, char **argv);
		~Jsp();

		void	run() noexcept;

	private:
		std::vector<std::string>	_inputFiles;

		void	_parseFile(const std::string &filename, int testNo) const noexcept;
};