#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {
	private:
		std::string _type;
		std::string _name;
	
	public:
		Zombie( void );
		~Zombie( void );
		
		void announce( void ) const;
};

#endif