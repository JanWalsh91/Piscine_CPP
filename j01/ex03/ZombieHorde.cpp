#include "ZombieHorde.hpp"
#include "Zombie.hpp"

ZombieHorde::ZombieHorde( int N ) {
	this->zombies = new Zombie[N];
	this->_size = N;
	this->announce();
}

ZombieHorde::~ZombieHorde( void ) {
	delete [] this->zombies;
}

void ZombieHorde::announce() {
	for (int i = 0; i < this->_size; i++) {
		this->zombies[i].announce();
	}
}