#ifndef ZOMBIE_HORDE_H
# define ZOMBIE_HORDE_H

#include "Zombie.hpp"

class ZombieHorde {
	private:
		int _size;

	public:
		ZombieHorde( int N );
		~ZombieHorde( void );

		Zombie* zombies;
		void announce( void );
};

#endif