#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main( void ) {
	srand ( time(NULL) );
	Zombie zombie("blarg", "nasty");
	zombie.announce();

	ZombieEvent squishy;
	squishy.setZombieType("squishy");
	squishy.randomChump();

	ZombieEvent superNice;
	superNice.setZombieType("superNice");
	Zombie* bob = superNice.newZombie("Bob");
	bob->announce();
	return (0);
}