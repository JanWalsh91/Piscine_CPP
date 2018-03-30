#include "ZombieHorde.hpp"

int main ( void ) {
	srand ( time(NULL) );
	ZombieHorde* horde = new ZombieHorde(5);
	delete horde;
}