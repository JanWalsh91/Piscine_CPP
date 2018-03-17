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
	// std::cout << "handleArg" << std::endl;
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
	std::string s;
	// std::cin.clear();
	// std::cin.ignore();
	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	// char c;
	// while (1) {
	// 	std::cin >> c;
		
	// }

	while (1) {
		// getline( std::cin, s );
		// std::cout << "getline: " << i << std::endl; 
		if (!getline( std::cin, s )) {
			// std::cout << "std::cin false" << std::endl;
			// std::cin.clear();
			break ;
		}
		// std::cout << "You just wrote: " << (int)(s[0]) << std::endl;
		std::cout << s << std::endl; 
	}
};