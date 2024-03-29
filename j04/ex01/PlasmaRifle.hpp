#ifndef PLASMA_RIFLE_H
# define PLASMA_RIFLE_H

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

	public:
		PlasmaRifle( void );
		PlasmaRifle( PlasmaRifle const & plasmaRifle );
		~PlasmaRifle( void );

		virtual void attack( void ) const;

		PlasmaRifle &    operator=( PlasmaRifle const & rhs );
};

#endif