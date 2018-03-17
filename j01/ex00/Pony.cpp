#include "Pony.hpp"

#include <string>
#include <iostream>

Pony::Pony ( std::string color ):  _color(color) {
	std::cout << this->_color << " pony created." << std::endl;
};

Pony::~Pony ( void ){
	std::cout << this->_color << " pony destroyed." << std::endl;
};

void Pony::neigh( void ){
	std::cout << "\"NEEEEEIIIIIGH!\" says the " << this->_color << " pony." << std::endl;
};