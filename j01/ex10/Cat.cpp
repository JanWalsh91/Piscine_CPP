#include "Cat.hpp"
#include <fstream>
#include <iostream>

Cat::Cat( void ) {
	return ;
}

Cat::~Cat( void ) {
	return ;
};

void Cat::handleArg( std::string arg ) {
	if (arg == "-") {
		this->readSI();
	}
	else {
		this->writeFileToSO( arg );
	}
};

void Cat::writeFileToSO( std::string file ) {
	std::ifstream is(file);

	std::string fileContents;
	std::string line;

	if (is.is_open()) {
		while (getline(is, line)){
			fileContents += line;
		}
	}	
	is.close();

	std::cout << fileContents;
};

void Cat::readSI( void ) {
	while (1) {
		
	}
};