#ifndef HUMAN_B_H
# define HUMAN_B_H

# include "Weapon.hpp"

# include <string>

class HumanB {
	public:
		HumanB( std::string name );
		~HumanB( void );
		std::string name;
		Weapon * weapon;
		void attack( void );
		void setWeapon( Weapon & weapon );
};

#endif