#ifndef HUMAN_A_H
# define HUMAN_A_H

# include "Weapon.hpp"

# include <string>

class HumanA {
	public:
		HumanA( std::string name, Weapon & weapon );
		~HumanA( void );
		std::string name;
		Weapon & weapon;
		void attack( void );
};

#endif