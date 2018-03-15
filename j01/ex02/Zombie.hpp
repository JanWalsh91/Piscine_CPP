#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {
	private:
		std::string _type;
		std::string _name;
	
	public:
		Zombie( std::string name, std::string type );
		~Zombie( void );
		
		void announce( void );
};

#endif