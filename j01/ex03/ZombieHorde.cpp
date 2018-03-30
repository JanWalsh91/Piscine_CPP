#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde( int N ) : _size(N), _zombies(new Zombie[N]) {
	this->announce();
}

ZombieHorde::~ZombieHorde( void ) {
	if (this->_zombies)
		delete [] this->_zombies;
}

void ZombieHorde::announce( void ) const {
	for (int i = 0; i < this->_size; i++) {
		this->_zombies[i].announce();
	}
}