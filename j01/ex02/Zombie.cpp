#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie( std::string name, std::string type ) : _name(name), _type(type) {
	std::cout << "< " << this->_name << "( " << this->_type << " )> Created" << std::endl;  
}

Zombie::~Zombie( void ) {
	std::cout << "< " << this->_name << "( " << this->_type << " )> Destroyed" << std::endl;  
}

void Zombie::announce( void ) const{
	std::cout << "< " << this->_name << "( " << this->_type << " )> Braiiiiinssss ..." << std::endl;  
}

