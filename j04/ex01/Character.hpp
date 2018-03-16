#ifndef CHARACTER_H
# define CHARACTER_H

# include "AWeapon.hpp"
# include "Enemy.hpp"

# include <string>
# include <iostream>

class Character {

	protected:
		std::string _name;
		int			_ap;
		AWeapon *	_weapon;

	public:
		Character( void );
		Character( std::string const & name );
		Character( Character const & character );
		virtual ~Character( void );

		void recoverAP( void );
		void equip( AWeapon* weapon );
		void attack( Enemy* enemy );
		std::string virtual getName( void ) const;
		int virtual getAP( void ) const;
		AWeapon* getWeapon( void ) const;

		Character &    operator=( Character const & rhs );
};

std::ostream& operator<<( std::ostream& os, const Character & character );

#endif