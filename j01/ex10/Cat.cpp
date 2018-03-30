#include "Cat.hpp"

#include <fstream>
#include <iostream>
#include <cerrno>

Cat::Cat( void ) {}

Cat::~Cat( void ) {}

void Cat::handleArg( std::string arg ) {
	if (arg == "-") {
		this->readSI();
	}
	else {
		this->writeFileToSO( arg );
	}
}

void Cat::writeFileToSO( std::string file ) {
	std::ifstream is(file);
	std::string fileContents;
	std::string line;
	char		c = 0;

	if (is.is_open()) {
		while (getline(is, line)){
			fileContents += line;
			if ( is.eof() ) {
				is.seekg(-1, std::ios_base::end);
				is.get(c);
				if ( c == '\n' ) {
					fileContents += "\n";
				}
			}
			else {
				fileContents += "\n";
			}
		}
		if ( is.fail() && errno != 0 ) {
			std::cout << "cat: " << file << ": ";
			std::cout << std::strerror(errno) << std::endl;
			return ;
		}
		is.close();
	}
	else if ( is.fail() && errno != 0 ) {
		std::cout << "cat: " << file << ": ";
		std::cout << std::strerror(errno) << std::endl;
		return ;
	}
	std::cout << fileContents;
}

void Cat::readSI( void ) {
	std::string s;

	while(getline(std::cin, s)) {

		if ( std::cin.eof() ) {
			std::cout << s << std::endl;
			return ;
		}
		std::cout << s << std::endl;
	}
}