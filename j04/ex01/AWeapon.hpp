#ifndef A_WEAPON_H
# define A_WEAPON_H

# include <string>
# include <iostream>

class AWeapon {

	protected:
		std::string		_name;
		unsigned int	_apcost;
		unsigned int	_damage;

	public:
		AWeapon( void );
		AWeapon( std::string const & name, int apcost, int damage );
		AWeapon( AWeapon const & aWeapon );
		virtual ~AWeapon( void );

		std::string virtual getName( void ) const;
		int getAPCost( void ) const;
        int getDamage( void ) const;
		
		virtual void attack( void ) const = 0;

		AWeapon &    operator=( AWeapon const & rhs );
};

#endif