#ifndef HUMAN_B_H
# define HUMAN_B_H

# include "Weapon.hpp"

# include <string>

class HumanB {
	private:
		std::string	_name;
		Weapon *	_weapon;

	public:
		HumanB( std::string name );
		~HumanB( void );
		void attack( void ) const;
		void setWeapon( Weapon & weapon );
};

#endif