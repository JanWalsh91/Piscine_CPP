#ifndef ZOMBIE_EVENT_H
# define ZOMBIE_EVENT_H

#include <string>
#include "Zombie.hpp"

class ZombieEvent {
	private:
		std::string _type;
	
	public:
		ZombieEvent( void );
		~ZombieEvent( void );
		void setZombieType( std:: string type );
		Zombie* newZombie( std::string name );
		void randomChump( void );
};

#endif