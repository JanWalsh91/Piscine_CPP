#include "Weapon.hpp"
#include <string>

class HumanB {
	public:
		HumanB( std::string name );
		~HumanB( void );
		std::string name;
		Weapon * weapon;
		void attack( void );
		void setWeapon( Weapon & weapon );
};