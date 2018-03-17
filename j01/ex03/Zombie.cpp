#include "Zombie.hpp"

#include <iostream>
#include <string>

Zombie::Zombie( void ) {
	std::string names[6] = { "Gertrude", "Josephine", "Marilla", "Claire", "Hope", "Angelina"};
	this->_name = names[rand() % 6];
	this->_type = "Hoarder";
	return ;
}

Zombie::~Zombie( void ) {
	return ;
}

void Zombie::announce( void ) {
	std::cout << "< " << this->_name << "( " << this->_type << " )> Braiiiiinssss ..." << std::endl;  
}

