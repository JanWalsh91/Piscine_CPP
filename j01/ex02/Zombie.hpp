#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {
	private:
		std::string _name;
		std::string _type;
	
	public:
		Zombie( std::string name, std::string type );
		~Zombie( void );
		
		void announce( void ) const;
};

#endif