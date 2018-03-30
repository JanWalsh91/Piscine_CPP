#ifndef ZOMBIE_EVENT_H
# define ZOMBIE_EVENT_H

# include "Zombie.hpp"

# include <string>

class ZombieEvent {
	private:
		std::string _type;
	
	public:
		ZombieEvent( void );
		~ZombieEvent( void );
		void setZombieType( std::string type );
		Zombie* newZombie( std::string name ) const;
		void randomChump( void ) const;
};

#endif