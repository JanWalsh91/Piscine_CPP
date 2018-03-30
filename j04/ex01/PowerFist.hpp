#ifndef POWER_FIST_H
# define POWER_FIST_H

# include "AWeapon.hpp"

class PowerFist : public AWeapon {

	public:
		PowerFist( void );
		PowerFist( PowerFist const & powerFist );
		~PowerFist( void );

		virtual void attack( void ) const;

		PowerFist &    operator=( PowerFist const & rhs );
};

#endif