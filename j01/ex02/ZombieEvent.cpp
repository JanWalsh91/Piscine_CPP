#include "Zombie.hpp"
#include "ZombieEvent.hpp"

#include <iostream>
#include <string>

ZombieEvent::ZombieEvent( void ) {
	this->_type = "undefined";
	return ;
}

ZombieEvent::~ZombieEvent( void ) {
	return ;
}

void ZombieEvent::setZombieType( std:: string type ){
	this->_type = type;
	return ;
}

Zombie* ZombieEvent::newZombie( std::string name ) {	
	return new Zombie(name, this->_type);
}

void ZombieEvent::randomChump( void ) {
	std::string names[6] = { "Gertrude", "Josephine", "Marilla", "Claire", "Hope", "Angelina"};
	
	Zombie zombie(names[rand() % 6], this->_type);
	zombie.announce();
}

