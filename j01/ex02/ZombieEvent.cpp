#include "ZombieEvent.hpp"

#include <iostream>

ZombieEvent::ZombieEvent( void ) : _type("undefined") {}

ZombieEvent::~ZombieEvent( void ) {}

void ZombieEvent::setZombieType( std::string type ){
	this->_type = type;
	return ;
}

Zombie* ZombieEvent::newZombie( std::string name ) const {	
	return new Zombie(name, this->_type);
}

void ZombieEvent::randomChump( void ) const {
	std::string names[6] = { "Gertrude", "Josephine", "Marilla", "Claire", "Hope", "Angelina" };
	
	Zombie zombie(names[rand() % 6], this->_type);
	zombie.announce();
}

