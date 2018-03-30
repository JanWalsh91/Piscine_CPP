#ifndef ZOMBIE_HORDE_H
# define ZOMBIE_HORDE_H

#include "Zombie.hpp"

class ZombieHorde {
	private:
		int _size;
		Zombie* _zombies;

	public:
		ZombieHorde( int N );
		~ZombieHorde( void );

		void announce( void ) const;
};

#endif