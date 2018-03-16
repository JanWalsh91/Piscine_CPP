#ifndef PLASMA_RIFLE_H
# define PLASMA_RIFLE_H

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

	public:
		PlasmaRifle( void );
		PlasmaRifle( PlasmaRifle const & plasmaRifle );
		~PlasmaRifle( void );

		void attack( void ) const;
};

#endif