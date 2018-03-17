#include "Zombie.hpp"

#include <iostream>
#include <string>

Zombie::Zombie( std::string name, std::string type ) {
	this->_name = name;
	this->_type = type;
	return ;
}

Zombie::~Zombie( void ) {
	return ;
}

void Zombie::announce( void ) {
	std::cout << "< " << this->_name << "( " << this->_type << " )> Braiiiiinssss ..." << std::endl;  
}

