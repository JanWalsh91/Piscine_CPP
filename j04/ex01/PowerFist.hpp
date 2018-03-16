#ifndef POWER_FIST_H
# define POWER_FIST_H

# include "AWeapon.hpp"

class PowerFist : public AWeapon {

	public:
		PowerFist( void );
		PowerFist( PowerFist const & powerFist );
		~PowerFist( void );

		void attack( void ) const;
};

#endif