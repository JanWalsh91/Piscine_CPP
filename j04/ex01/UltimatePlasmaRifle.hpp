#ifndef ULTIMATE_PLASMA_RIFLE_H
# define ULTIMATE_PLASMA_RIFLE_H

# include "PlasmaRifle.hpp"

class UltimatePlasmaRifle : public PlasmaRifle {

	public:
		UltimatePlasmaRifle( void );
		UltimatePlasmaRifle( UltimatePlasmaRifle const & ultimatePlasmaRifle );
		~UltimatePlasmaRifle( void );

		virtual void attack( void ) const;

		UltimatePlasmaRifle &    operator=( UltimatePlasmaRifle const & rhs );
};

#endif