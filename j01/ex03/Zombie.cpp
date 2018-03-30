#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie( void ) {
	std::string names[6] = { "Gertrude", "Josephine", "Marilla", "Claire", "Hope", "Angelina"};
	this->_name = names[rand() % 6];
	this->_type = "Hoarder";
	std::cout << "< " << this->_name << "( " << this->_type << " )> Created" << std::endl;  
}

Zombie::~Zombie( void ) {
	std::cout << "< " << this->_name << "( " << this->_type << " )> Destroyed" << std::endl;  
}

void Zombie::announce( void ) const {
	std::cout << "< " << this->_name << "( " << this->_type << " )> Braiiiiinssss ..." << std::endl;  
}

